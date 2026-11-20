	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0xf2
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	bge _081DC144
	ldr r0, _081DC140 @ =0x000003D1
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #2
	bne _081DC11E
	b _081DC2D4
_081DC11E:
	bl Marquee_Clear
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #2
	bl GetStringByID
	bl Marquee_SetText
	movs r0, #2
	strb r0, [r5]
	b _081DC2D4
	.align 2, 0
_081DC140: .4byte 0x000003D1
_081DC144:
	bl FUN_081dfa04
	adds r2, r0, #0
	subs r0, r2, #5
	cmp r0, #1
	bhi _081DC184
	ldr r0, _081DC180 @ =0x000003D1
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #4
	bne _081DC15E
	b _081DC2D4
_081DC15E:
	bl Marquee_Clear
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #4
	bl GetStringByID
	bl Marquee_SetText
	movs r0, #4
	strb r0, [r5]
	b _081DC2D4
	.align 2, 0
_081DC180: .4byte 0x000003D1
_081DC184:
	ldr r0, _081DC198 @ =0x03002C68
	ldr r1, [r0]
	adds r3, r0, #0
	cmp r1, #0
	beq _081DC19C
	ldrb r0, [r1, #0x1d]
	cmp r0, #0
	beq _081DC19C
	movs r0, #1
	b _081DC19E
	.align 2, 0
_081DC198: .4byte 0x03002C68
_081DC19C:
	movs r0, #0
_081DC19E:
	cmp r0, #0
	beq _081DC1D8
	cmp r2, #8
	bne _081DC1D8
	ldr r0, _081DC1D4 @ =0x000003D1
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #6
	bne _081DC1B4
	b _081DC2D4
_081DC1B4:
	bl Marquee_Clear
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #6
	bl GetStringByID
	bl Marquee_SetText
	movs r0, #6
	strb r0, [r5]
	b _081DC2D4
	.align 2, 0
_081DC1D4: .4byte 0x000003D1
_081DC1D8:
	movs r1, #0xf2
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r0, [r3]
	cmp r0, #0
	bne _081DC1EA
	movs r6, #0
	b _081DC1F0
_081DC1EA:
	adds r0, #0x68
	adds r0, r0, r1
	ldrb r6, [r0]
_081DC1F0:
	cmp r6, #2
	beq _081DC234
	cmp r6, #2
	ble _081DC1FE
	cmp r6, #3
	beq _081DC264
	b _081DC2D4
_081DC1FE:
	cmp r6, #0
	blt _081DC2D4
	ldr r0, _081DC230 @ =0x000003D1
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #1
	beq _081DC2D4
	bl Marquee_Clear
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #1
	bl GetStringByID
	bl Marquee_SetText
	movs r0, #1
	strb r0, [r5]
	b _081DC2D4
	.align 2, 0
_081DC230: .4byte 0x000003D1
_081DC234:
	ldr r0, _081DC260 @ =0x000003D1
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #2
	beq _081DC2D4
	bl Marquee_Clear
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #2
	bl GetStringByID
	bl Marquee_SetText
	strb r6, [r5]
	b _081DC2D4
	.align 2, 0
_081DC260: .4byte 0x000003D1
_081DC264:
	movs r0, #0xf3
	lsls r0, r0, #2
	adds r5, r4, r0
	adds r0, #6
	adds r1, r4, r0
	ldr r0, [r5]
	ldrb r1, [r1]
	cmp r0, r1
	beq _081DC2A4
	bl Marquee_Clear
	ldr r1, [r5]
	movs r0, #0
	bl Marquee_SetVarValue
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #3
	bl GetStringByID
	bl Marquee_SetText
	ldr r1, _081DC2A0 @ =0x000003D1
	adds r0, r4, r1
	strb r6, [r0]
	b _081DC2D4
	.align 2, 0
_081DC2A0: .4byte 0x000003D1
_081DC2A4:
	ldr r0, _081DC2DC @ =0x000003D1
	adds r7, r4, r0
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r0, #3
	beq _081DC2D4
	bl Marquee_Clear
	ldr r1, [r5]
	movs r0, #0
	bl Marquee_SetVarValue
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #3
	bl GetStringByID
	bl Marquee_SetText
	strb r6, [r7]
_081DC2D4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DC2DC: .4byte 0x000003D1
