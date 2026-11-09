	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x40
	movs r7, #0
	ldr r0, _08204BC8 @ =0x085AE834
	mov r8, r0
	adds r4, r6, #0
	adds r4, #0x7e
_08204B9A:
	ldrb r0, [r4, #2]
	cmp r0, #1
	bne _08204BB4
	ldrb r0, [r4]
	cmp r0, #1
	bhi _08204BBE
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r6, #0
	adds r1, r5, #0
	bl _call_via_r2
_08204BB4:
	adds r4, #0x44
	adds r5, #0x44
	adds r7, #1
	cmp r7, #0xf
	ble _08204B9A
_08204BBE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08204BC8: .4byte 0x085AE834
