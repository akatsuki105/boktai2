	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov ip, r0
	adds r6, r1, #0
	movs r4, #0
	ldr r0, _082328E8 @ =0x030046A4
	ldr r0, [r0]
	adds r0, #0x1c
	mov sl, r0
	movs r0, #0xff
	mov sb, r0
	movs r5, #0xc0
	movs r1, #3
	mov r8, r1
_082328AA:
	adds r0, r4, #0
	mov r2, r8
	ands r0, r2
	lsls r0, r0, #1
	add r0, sl
	movs r7, #0
	ldrsh r1, [r0, r7]
	mov r2, ip
	movs r3, #0
	adds r0, r5, #0
	mov r7, sb
	ands r0, r7
_082328C2:
	adds r2, r2, r1
	cmp r2, r6
	beq _082328DA
	adds r3, #1
	cmp r3, #3
	ble _082328C2
	adds r5, #0x40
	adds r4, #1
	cmp r4, #3
	ble _082328AA
	movs r0, #1
	rsbs r0, r0, #0
_082328DA:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_082328E8: .4byte 0x030046A4
