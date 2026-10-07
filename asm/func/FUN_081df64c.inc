	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r6, r1, #0
	ldr r0, _081DF664 @ =0x03002C68
	ldr r7, [r0]
	cmp r7, #0
	bne _081DF668
	movs r0, #1
	rsbs r0, r0, #0
	b _081DF68E
	.align 2, 0
_081DF664: .4byte 0x03002C68
_081DF668:
	movs r5, #0
_081DF66A:
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r7, r1
	adds r4, r0, r5
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, r6
	bne _081DF686
	mov r0, r8
	adds r1, r6, #0
	bl FUN_081e1984
	movs r0, #0xff
	strb r0, [r4]
_081DF686:
	adds r5, #1
	cmp r5, #4
	ble _081DF66A
	movs r0, #0
_081DF68E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
