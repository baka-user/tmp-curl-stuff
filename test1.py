import requests
url = 'https://raw.githubusercontent.com/ik-user/tmp-curl-stuff/main/gauss_el.c'
html_response = requests.get(url=url)
html_res_str = html_response.text
text = open('ok.c','w')
text.write(html_res_str)
text.close()