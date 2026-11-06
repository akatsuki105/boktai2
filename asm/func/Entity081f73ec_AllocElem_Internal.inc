	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r6, #0
	movs r2, #1
	ldr r3, _081F71F4 @ =0x000006EC
	ldr r0, _081F71F8 @ =0x00000723
	adds r7, r5, r0
	adds r4, r5, #0
	adds r4, #0x3c
_081F71E4:
	adds r1, r2, #0
	lsls r1, r6
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F71FC
	movs r0, #1
	b _081F71FE
	.align 2, 0
_081F71F4: .4byte 0x000006EC
_081F71F8: .4byte 0x00000723
_081F71FC:
	movs r0, #0
_081F71FE:
	cmp r0, #0
	bne _081F721E
	adds r0, r4, #0
	adds r1, r3, #0
	str r2, [sp]
	bl ClearMemory
	ldr r2, [sp]
	adds r1, r2, #0
	lsls r1, r6
	ldr r0, [r5, #0x38]
	orrs r0, r1
	str r0, [r5, #0x38]
	strb r6, [r7]
	adds r0, r4, #0
	b _081F722C
_081F721E:
	ldr r0, _081F7234 @ =0x000006EC
	adds r7, r7, r0
	adds r4, r4, r0
	adds r6, #1
	cmp r6, #0
	ble _081F71E4
	movs r0, #0
_081F722C:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081F7234: .4byte 0x000006EC
