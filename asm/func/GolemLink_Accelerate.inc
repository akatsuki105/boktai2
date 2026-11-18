	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r4, _081B90C4 @ =0x00000256
	adds r0, r5, r4
	ldrh r4, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B90C8
	adds r0, #4
	b _081B90D4
	.align 2, 0
_081B90C4: .4byte 0x00000256
_081B90C8:
	ldr r0, _081B90F4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B90D4:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #0
	beq _081B9116
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #1
	beq _081B9100
	cmp r0, #1
	bgt _081B90F8
	cmp r0, #0
	beq _081B9108
	b _081B910E
	.align 2, 0
_081B90F4: .4byte 0x030046A4
_081B90F8:
	cmp r0, #3
	beq _081B9100
	cmp r0, #5
	bne _081B910E
_081B9100:
	movs r2, #0xa0
	lsls r2, r2, #1
	movs r3, #0xb
	b _081B914A
_081B9108:
	movs r2, #0xa0
	movs r3, #5
	b _081B914A
_081B910E:
	movs r2, #0x80
	lsls r2, r2, #1
	movs r3, #8
	b _081B914A
_081B9116:
	movs r4, #0x90
	lsls r4, r4, #3
	adds r0, r5, r4
	ldrh r0, [r0]
	cmp r0, #1
	beq _081B9134
	cmp r0, #1
	bgt _081B912C
	cmp r0, #0
	beq _081B913C
	b _081B9144
_081B912C:
	cmp r0, #3
	beq _081B9134
	cmp r0, #5
	bne _081B9144
_081B9134:
	movs r2, #0xe0
	lsls r2, r2, #1
	movs r3, #0x16
	b _081B914A
_081B913C:
	movs r2, #0xa0
	lsls r2, r2, #1
	movs r3, #0xa
	b _081B914A
_081B9144:
	movs r2, #0xc0
	lsls r2, r2, #1
	movs r3, #0x10
_081B914A:
	ldr r0, _081B9160 @ =0x000006B6
	adds r1, r6, r0
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, r2
	bge _081B9164
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	b _081B9166
	.align 2, 0
_081B9160: .4byte 0x000006B6
_081B9164:
	strh r2, [r1]
_081B9166:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
