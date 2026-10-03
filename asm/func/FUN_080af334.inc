	push {lr}
	mov ip, r0
	ldr r0, [r0]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
	str r0, [r2]
	adds r2, #0x68
	movs r3, #7
_080AF348:
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r2, #0x68
	subs r3, #1
	cmp r3, #0
	bge _080AF348
	movs r2, #2
	rsbs r2, r2, #0
	movs r1, #0xea
	lsls r1, r1, #2
	add r1, ip
	movs r3, #5
_080AF362:
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	adds r1, #0x68
	subs r3, #1
	cmp r3, #0
	bge _080AF362
	pop {r0}
	bx r0
