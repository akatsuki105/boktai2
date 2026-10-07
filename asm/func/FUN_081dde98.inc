	push {r4, r5, r6, r7, lr}
	mov ip, r0
	movs r4, #0
	ldrh r0, [r0, #0x1a]
	cmp r4, r0
	bge _081DDECE
	mov r3, ip
	adds r3, #0x88
	movs r2, #0xd2
	lsls r2, r2, #1
	add r2, ip
_081DDEAE:
	adds r1, r3, #0
	adds r0, r2, #0
	adds r0, #0x1c
	ldm r0!, {r5, r6, r7}
	stm r1!, {r5, r6, r7}
	ldm r0!, {r5, r6, r7}
	stm r1!, {r5, r6, r7}
	ldm r0!, {r5, r6, r7}
	stm r1!, {r5, r6, r7}
	adds r3, #0x24
	adds r2, #0x48
	adds r4, #1
	mov r0, ip
	ldrh r0, [r0, #0x1a]
	cmp r4, r0
	blt _081DDEAE
_081DDECE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
