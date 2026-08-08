	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08065F5E
	cmp r1, #0
	blt _08065F5E
	ldr r0, _08065F64 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08065F5E
	ldr r0, _08065F68 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08065F6C
_08065F5E:
	movs r4, #0
	b _08065F7A
	.align 2, 0
_08065F64: .4byte 0x030046A8
_08065F68: .4byte 0x030046AC
_08065F6C:
	ldr r0, _08065F8C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08065F7A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08065F90
	adds r0, #4
	b _08065F9C
	.align 2, 0
_08065F8C: .4byte 0x030046A4
_08065F90:
	ldr r0, _08065FB0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08065F9C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08065FB4
	cmp r2, #2
	beq _08065FB8
	b _08065FBC
	.align 2, 0
_08065FB0: .4byte 0x030046A4
_08065FB4:
	ldrb r0, [r5, #4]
	b _08065FBA
_08065FB8:
	ldrb r0, [r5]
_08065FBA:
	subs r1, r1, r0
_08065FBC:
	movs r2, #0x2e
	ldrsh r0, [r6, r2]
	cmp r1, r0
	bne _08066038
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08065FE8
	cmp r1, #0
	blt _08065FE8
	ldr r0, _08065FEC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08065FE8
	ldr r0, _08065FF0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08065FF4
_08065FE8:
	movs r4, #0
	b _08066002
	.align 2, 0
_08065FEC: .4byte 0x030046A8
_08065FF0: .4byte 0x030046AC
_08065FF4:
	ldr r0, _08066014 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08066002:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08066018
	adds r0, #4
	b _08066024
	.align 2, 0
_08066014: .4byte 0x030046A4
_08066018:
	ldr r0, _08066034 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08066024:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08066038
	movs r0, #0
	b _0806603A
	.align 2, 0
_08066034: .4byte 0x030046A4
_08066038:
	movs r0, #1
_0806603A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
