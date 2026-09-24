	push {r4, r5, r6, lr}
	sub sp, #0x24
	adds r5, r1, #0
	movs r0, #0xab
	lsls r0, r0, #1
	adds r3, r5, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081D618C
	adds r0, r5, #0
	adds r0, #0x1c
	ldrh r1, [r5, #0x1c]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r6, r0, #0
	cmp r2, #0
	blt _081D6104
	cmp r1, #0
	blt _081D6104
	ldr r0, _081D6108 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D6104
	ldr r0, _081D610C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D6110
_081D6104:
	movs r4, #0
	b _081D611E
	.align 2, 0
_081D6108: .4byte 0x030046A8
_081D610C: .4byte 0x030046AC
_081D6110:
	ldr r0, _081D6130 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081D611E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D6134
	adds r0, #4
	b _081D6140
	.align 2, 0
_081D6130: .4byte 0x030046A4
_081D6134:
	ldr r0, _081D6154 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D6140:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r3, r0, #8
	cmp r2, #1
	beq _081D6158
	cmp r2, #2
	beq _081D615C
	b _081D6160
	.align 2, 0
_081D6154: .4byte 0x030046A4
_081D6158:
	ldrb r0, [r6, #4]
	b _081D615E
_081D615C:
	ldrb r0, [r6]
_081D615E:
	subs r3, r3, r0
_081D6160:
	movs r2, #0x9f
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #0
	movs r2, #0
	strh r3, [r1]
	movs r3, #0xab
	lsls r3, r3, #1
	adds r1, r5, r3
	strb r0, [r1]
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r1, r5, r0
	str r2, [sp, #0x20]
	add r0, sp, #0x20
	ldr r2, _081D6188 @ =0x05000002
	bl CpuSet
	b _081D61F6
	.align 2, 0
_081D6188: .4byte 0x05000002
_081D618C:
	movs r1, #0x8f
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r0, [r5, #0x1e]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r5, #0x1e]
	ldrh r0, [r2]
	adds r0, #2
	strh r0, [r2]
	movs r2, #0x9f
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r1, [r0]
	movs r2, #0x1e
	ldrsh r0, [r5, r2]
	cmp r1, r0
	blt _081D61F6
	strh r1, [r5, #0x1e]
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #4
	strh r1, [r0]
	movs r0, #1
	strb r0, [r3]
	movs r4, #0
	adds r6, r5, #0
	adds r6, #0x1c
	movs r5, #1
_081D61C8:
	movs r0, #0xc
	str r0, [sp]
	movs r0, #0x12
	str r0, [sp, #4]
	lsls r0, r4, #5
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	movs r0, #0x40
	str r0, [sp, #0x10]
	str r5, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #0
	str r0, [sp, #0x1c]
	adds r0, r6, #0
	movs r1, #8
	movs r2, #0x10
	movs r3, #4
	bl FUN_081ee584
	adds r4, #1
	cmp r4, #7
	ble _081D61C8
_081D61F6:
	add sp, #0x24
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
