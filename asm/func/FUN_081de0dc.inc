	push {r4, lr}
	mov ip, r0
	movs r1, #4
	movs r3, #4
	movs r0, #0x8e
	lsls r0, r0, #1
	add r0, ip
_081DE0EA:
	strb r1, [r0]
	subs r0, #1
	subs r3, #1
	cmp r3, #0
	bge _081DE0EA
	movs r3, #0
	movs r2, #0
	movs r0, #0x90
	lsls r0, r0, #1
	add r0, ip
	movs r4, #0xa2
	lsls r4, r4, #1
	add r4, ip
	movs r1, #0x9c
	lsls r1, r1, #1
	add r1, ip
_081DE10A:
	strh r2, [r0]
	strh r2, [r0, #8]
	strh r2, [r0, #0x10]
	strh r2, [r1]
	stm r4!, {r2}
	adds r0, #2
	adds r1, #2
	adds r3, #1
	cmp r3, #3
	ble _081DE10A
	movs r1, #0xa0
	lsls r1, r1, #1
	add r1, ip
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
