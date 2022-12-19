#!/usr/bin/python3
"""
0. Count it!
"""
import requests


def count_words(subreddit, word_list, after=None, count={}):
    """
    Recursive function that queries the Reddit API,
        parses the title of all hot articles, and prints
        a sorted count of given keywords
    """
    if after is None:
        url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    else:
        url = 'https://www.reddit.com/r/{}/hot.json?after={}'.format(
            subreddit, after)
    subreddit_req = requests.get(url,
                                 headers={"user-agent": "user"},
                                 allow_redirects=False)
    try:
        data = subreddit_req.json().get("data")
    except Exception as e:
        return None
    for word in word_list:
        word = word.lower()
        if word not in count.keys():
            count[word] = 0
    children = data.get("children")
    for child in children:
        hot_title = (child.get("data").get("title").lower())
        hot_title = hot_title.split(' ')
        for word in word_list:
            word = word.lower()
            count[word] += hot_title.count(word)
    after = data.get("after")
    if after is None:
        sorted_subs = sorted(count.items(), key=lambda x: x[0])
        for subs in sorted_subs:
            if subs[1] != 0:
                print(subs[0] + ": " + str(subs[1]))
    else:
        return count_words(subreddit, word_list, after, count)
