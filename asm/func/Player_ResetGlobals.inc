	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r1, _0807A2F4 @ =0x03002B98
	movs r0, #0
	strh r0, [r1]
	ldr r5, _0807A2F8 @ =0x03002B60
	ldr r6, _0807A2FC @ =0x03002B7C
	ldr r7, _0807A300 @ =0x03002B8C
	ldr r0, _0807A304 @ =0x03002BF0
	mov ip, r0
	ldr r1, _0807A308 @ =0x03002BD0
	mov r8, r1
	ldr r0, _0807A30C @ =0x03002B80
	mov sb, r0
	ldr r1, _0807A310 @ =0x03002B78
	mov sl, r1
	movs r2, #0
	ldr r4, _0807A314 @ =0x03002BC0
	ldr r1, _0807A318 @ =0x03002B68
	ldr r3, _0807A31C @ =0x03002BE0
	movs r0, #3
_0807A2A0:
	stm r3!, {r2}
	strh r2, [r1]
	stm r4!, {r2}
	adds r1, #2
	subs r0, #1
	cmp r0, #0
	bge _0807A2A0
	movs r0, #0
	strh r0, [r5]
	strh r0, [r6]
	strh r0, [r7]
	mov r1, ip
	strh r0, [r1]
	mov r1, r8
	strh r0, [r1]
	mov r1, sb
	strh r0, [r1]
	mov r1, sl
	strh r0, [r1]
	ldr r1, _0807A320 @ =0x03002BA0
	movs r2, #0
	adds r0, r1, #4
_0807A2CC:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _0807A2CC
	movs r0, #0
	ldr r1, _0807A324 @ =0x03002B84
	strh r0, [r1]
	ldr r1, _0807A328 @ =0x03002BAC
	strh r0, [r1]
	ldr r1, _0807A32C @ =0x03002B90
	strh r0, [r1]
	ldr r1, _0807A330 @ =0x03002BB0
	strh r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807A2F4: .4byte 0x03002B98
_0807A2F8: .4byte 0x03002B60
_0807A2FC: .4byte 0x03002B7C
_0807A300: .4byte 0x03002B8C
_0807A304: .4byte 0x03002BF0
_0807A308: .4byte 0x03002BD0
_0807A30C: .4byte 0x03002B80
_0807A310: .4byte 0x03002B78
_0807A314: .4byte 0x03002BC0
_0807A318: .4byte 0x03002B68
_0807A31C: .4byte 0x03002BE0
_0807A320: .4byte 0x03002BA0
_0807A324: .4byte 0x03002B84
_0807A328: .4byte 0x03002BAC
_0807A32C: .4byte 0x03002B90
_0807A330: .4byte 0x03002BB0
