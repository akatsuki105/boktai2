	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _08073B58 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bls _08073B4C
	b _08073E0E
_08073B4C:
	lsls r0, r0, #2
	ldr r1, _08073B5C @ =_08073B60
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08073B58: .4byte 0x0000037D
_08073B5C: .4byte _08073B60
_08073B60: @ jump table
	.4byte _08073B78 @ case 0
	.4byte _08073BB4 @ case 1
	.4byte _08073CD8 @ case 2
	.4byte _08073D7C @ case 3
	.4byte _08073DC4 @ case 4
	.4byte _08073E0E @ case 5
_08073B78:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r5, _08073BB0 @ =0x0000037E
	adds r1, r4, r5
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi _08073BA4
	b _08073E0E
_08073BA4:
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #1
	bl FUN_08060b84
	b _08073E0E
	.align 2, 0
_08073BB0: .4byte 0x0000037E
_08073BB4:
	ldr r1, _08073C14 @ =0x0000037E
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08073BC8
	ldr r2, _08073C18 @ =0x000003F6
	adds r1, r4, r2
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
_08073BC8:
	movs r5, #0xd6
	lsls r5, r5, #2
	adds r0, r4, r5
	ldrb r0, [r0]
	movs r1, #0x2b
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _08073C1C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r5, _08073C20 @ =0x000004A4
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _08073C24
	asrs r0, r0, #0xc
	b _08073C2A
	.align 2, 0
_08073C14: .4byte 0x0000037E
_08073C18: .4byte 0x000003F6
_08073C1C: .4byte 0x085B0A08
_08073C20: .4byte 0x000004A4
_08073C24:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08073C2A:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	ldr r1, _08073C48 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r5, _08073C4C @ =0x000004A4
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _08073C50
	asrs r0, r0, #0xc
	b _08073C56
	.align 2, 0
_08073C48: .4byte 0x085B0A08
_08073C4C: .4byte 0x000004A4
_08073C50:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08073C56:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
	ldr r0, _08073C84 @ =0x000004A4
	adds r2, r4, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	ldr r1, _08073C88 @ =0x0000037E
	adds r3, r4, r1
	ldrh r0, [r3]
	cmp r0, #3
	bls _08073C94
	ldr r2, _08073C8C @ =0x000003F6
	adds r1, r4, r2
	ldrh r2, [r1]
	lsls r0, r0, #3
	cmp r2, r0
	blt _08073C90
	subs r0, r2, r0
	b _08073C92
	.align 2, 0
_08073C84: .4byte 0x000004A4
_08073C88: .4byte 0x0000037E
_08073C8C: .4byte 0x000003F6
_08073C90:
	movs r0, #0
_08073C92:
	strh r0, [r1]
_08073C94:
	ldr r5, _08073CCC @ =0x0000037E
	adds r1, r4, r5
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r1, _08073CD0 @ =0x000004A4
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0x13
	bls _08073CAA
	b _08073E0E
_08073CAA:
	ldr r2, _08073CD4 @ =0x000003F6
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08073CB6
	b _08073E0E
_08073CB6:
	strh r0, [r1]
	movs r0, #0xaa
	lsls r0, r0, #2
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #2
	bl FUN_08060b84
	b _08073E0E
	.align 2, 0
_08073CCC: .4byte 0x0000037E
_08073CD0: .4byte 0x000004A4
_08073CD4: .4byte 0x000003F6
_08073CD8:
	movs r5, #0xba
	lsls r5, r5, #2
	adds r0, r4, r5
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _08073D0C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	ldr r5, _08073D10 @ =0x000004A4
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _08073D14
	asrs r0, r0, #0xc
	b _08073D1A
	.align 2, 0
_08073D0C: .4byte 0x085B0A08
_08073D10: .4byte 0x000004A4
_08073D14:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08073D1A:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r5, _08073D38 @ =0x000004A4
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _08073D3C
	asrs r0, r0, #0xc
	b _08073D42
	.align 2, 0
_08073D38: .4byte 0x000004A4
_08073D3C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08073D42:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x2c
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08073E0E
	ldr r2, _08073D78 @ =0x000004A4
	adds r1, r4, r2
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #3
	bl FUN_08060b84
	b _08073E0E
	.align 2, 0
_08073D78: .4byte 0x000004A4
_08073D7C:
	ldr r5, _08073DB0 @ =0x0000037E
	adds r1, r4, r5
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x13
	bls _08073E0E
	ldr r0, _08073DB4 @ =0x000004A6
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08073DB8
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #5
	bl FUN_08060b84
	adds r0, r4, #0
	bl FUN_080726b4
	b _08073E0E
	.align 2, 0
_08073DB0: .4byte 0x0000037E
_08073DB4: .4byte 0x000004A6
_08073DB8:
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #4
	bl FUN_08060b84
	b _08073E0E
_08073DC4:
	ldr r1, _08073E14 @ =0x0000037E
	adds r5, r4, r1
	ldrh r0, [r5]
	cmp r0, #0
	bne _08073DDA
	movs r0, #0xdb
	bl PlaySound_082406e0
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_08073DDA:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0x2d
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08073E0E
	movs r0, #0xd0
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	bl FUN_08072620
	adds r0, r4, #0
	bl FUN_080726b4
_08073E0E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08073E14: .4byte 0x0000037E
