	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0804E510 @ =0x03002B58
	ldr r0, [r0]
	mov ip, r0
	cmp r0, #0
	beq _0804E50A
	movs r0, #0xde
	lsls r0, r0, #2
	add r0, ip
	str r4, [r0]
	movs r0, #0xdf
	lsls r0, r0, #2
	add r0, ip
	str r1, [r0]
	movs r0, #0xe0
	lsls r0, r0, #2
	add r0, ip
	str r2, [r0]
	movs r0, #0xe1
	lsls r0, r0, #2
	add r0, ip
	str r3, [r0]
_0804E50A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804E510: .4byte 0x03002B58
