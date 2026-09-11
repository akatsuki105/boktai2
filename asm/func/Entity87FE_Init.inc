	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080A9F84 @ =0x03002BE0
	ldr r0, [r0]
	str r0, [r4, #0x18]
	cmp r0, #0
	bne _080A9F88
	movs r0, #1
	rsbs r0, r0, #0
	b _080AA044
	.align 2, 0
_080A9F84: .4byte 0x03002BE0
_080A9F88:
	movs r0, #0x6c
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080A9F9A
	bl Script_GetValue
	adds r5, r0, #0
	b _080A9F9C
_080A9F9A:
	movs r5, #0
_080A9F9C:
	movs r0, #0x65
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080A9FAE
	bl Script_GetValue
	adds r6, r0, #0
	b _080A9FB0
_080A9FAE:
	movs r6, #0
_080A9FB0:
	cmp r5, #0
	beq _080A9FE4
	ldr r0, [r4, #0x18]
	movs r2, #0xd9
	lsls r2, r2, #2
	adds r1, r0, r2
	ldr r3, _080A9FE0 @ =0x00000366
	adds r2, r0, r3
	ldrh r0, [r1]
	ldrh r1, [r2]
	cmp r0, r1
	bhs _080A9FE4
	ldrh r0, [r2]
	movs r1, #0x5a
	bl Div
	strh r0, [r4, #0x20]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080A9FDC
	movs r0, #1
	strh r0, [r4, #0x20]
_080A9FDC:
	movs r0, #0
	b _080A9FE6
	.align 2, 0
_080A9FE0: .4byte 0x00000366
_080A9FE4:
	movs r0, #1
_080A9FE6:
	strb r0, [r4, #0x1c]
	cmp r6, #0
	beq _080AA01C
	ldr r0, [r4, #0x18]
	movs r2, #0xda
	lsls r2, r2, #2
	adds r1, r0, r2
	ldr r3, _080AA018 @ =0x0000036A
	adds r2, r0, r3
	ldrh r0, [r1]
	ldrh r1, [r2]
	cmp r0, r1
	bhs _080AA01C
	ldrh r0, [r2]
	movs r1, #0x5a
	bl Div
	strh r0, [r4, #0x22]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080AA014
	movs r0, #1
	strh r0, [r4, #0x22]
_080AA014:
	movs r0, #0
	b _080AA01E
	.align 2, 0
_080AA018: .4byte 0x0000036A
_080AA01C:
	movs r0, #1
_080AA01E:
	strb r0, [r4, #0x1d]
	ldrb r0, [r4, #0x1c]
	cmp r0, #0
	beq _080AA02C
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	bne _080AA032
_080AA02C:
	ldr r0, _080AA04C @ =0x00000259
	bl PlaySound_082406e0
_080AA032:
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080AA040
	bl Script_GetValue
_080AA040:
	str r0, [r4, #0x24]
	movs r0, #0
_080AA044:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080AA04C: .4byte 0x00000259
