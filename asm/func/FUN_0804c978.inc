	push {lr}
	adds r3, r0, #0
	movs r1, #0x32
	adds r1, r1, r3
	mov ip, r1
	ldrb r1, [r1]
	cmp r1, #0
	beq _0804C98E
	movs r1, #0
	mov r2, ip
	strb r1, [r2]
_0804C98E:
	ldr r1, [r3, #0x44]
	cmp r1, #0x78
	bls _0804C9A4
	movs r2, #8
	movs r1, #0
	strb r1, [r3, #0x1c]
	strh r2, [r3, #0x38]
	str r1, [r3, #0x44]
	movs r1, #1
	mov r2, ip
	strb r1, [r2]
_0804C9A4:
	pop {r1}
	bx r1
