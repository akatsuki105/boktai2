	push {r4, r5, lr}
	bl FUN_080d7bac
	ldr r1, _080D7C14 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	bne _080D7BF0
	b _080D7F3C
_080D7BF0:
	movs r0, #0x54
	bl VM_SeekToKeyword
	cmp r0, #0
	bne _080D7BFC
	b _080D7F3C
_080D7BFC:
	bl Script_GetValue
	subs r0, #2
	cmp r0, #0x15
	bls _080D7C08
	b _080D7F3C
_080D7C08:
	lsls r0, r0, #2
	ldr r1, _080D7C18 @ =_080D7C1C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D7C14: .4byte 0x03002BE0
_080D7C18: .4byte _080D7C1C
_080D7C1C: @ jump table
	.4byte _080D7D60 @ case 0
	.4byte _080D7D8C @ case 1
	.4byte _080D7F3C @ case 2
	.4byte _080D7F3C @ case 3
	.4byte _080D7DB8 @ case 4
	.4byte _080D7DF0 @ case 5
	.4byte _080D7F00 @ case 6
	.4byte _080D7E18 @ case 7
	.4byte _080D7E40 @ case 8
	.4byte _080D7E84 @ case 9
	.4byte _080D7F3C @ case 10
	.4byte _080D7F3C @ case 11
	.4byte _080D7EBC @ case 12
	.4byte _080D7CA8 @ case 13
	.4byte _080D7C74 @ case 14
	.4byte _080D7CDC @ case 15
	.4byte _080D7F3C @ case 16
	.4byte _080D7F3C @ case 17
	.4byte _080D7F3C @ case 18
	.4byte _080D7F3C @ case 19
	.4byte _080D7CF8 @ case 20
	.4byte _080D7D2C @ case 21
_080D7C74:
	ldr r0, _080D7CA4 @ =0x00000366
	adds r4, r5, r0
	ldrh r1, [r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0x64
	bl Div
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r2, r5, r1
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	ldrh r4, [r4]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, r4
	bhi _080D7C9E
	b _080D7E6A
_080D7C9E:
	strh r4, [r2]
	b _080D7E6A
	.align 2, 0
_080D7CA4: .4byte 0x00000366
_080D7CA8:
	ldr r0, _080D7CD8 @ =0x00000366
	adds r4, r5, r0
	ldrh r1, [r4]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0x64
	bl Div
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r2, r5, r1
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	ldrh r4, [r4]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, r4
	bhi _080D7CD2
	b _080D7E6A
_080D7CD2:
	strh r4, [r2]
	b _080D7E6A
	.align 2, 0
_080D7CD8: .4byte 0x00000366
_080D7CDC:
	ldr r0, _080D7CF4 @ =0x00000366
	adds r4, r5, r0
	ldrh r1, [r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0x64
	bl Div
	movs r1, #0xd9
	lsls r1, r1, #2
	b _080D7ED2
	.align 2, 0
_080D7CF4: .4byte 0x00000366
_080D7CF8:
	ldr r0, _080D7D28 @ =0x00000366
	adds r4, r5, r0
	ldrh r1, [r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	movs r1, #0x64
	bl Div
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r2, r5, r1
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	ldrh r4, [r4]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, r4
	bhi _080D7D22
	b _080D7E6A
_080D7D22:
	strh r4, [r2]
	b _080D7E6A
	.align 2, 0
_080D7D28: .4byte 0x00000366
_080D7D2C:
	ldr r0, _080D7D5C @ =0x0000036A
	adds r4, r5, r0
	ldrh r1, [r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	movs r1, #0x64
	bl Div
	movs r1, #0xda
	lsls r1, r1, #2
	adds r2, r5, r1
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	ldrh r4, [r4]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, r4
	bhi _080D7D56
	b _080D7E6A
_080D7D56:
	strh r4, [r2]
	b _080D7E6A
	.align 2, 0
_080D7D5C: .4byte 0x0000036A
_080D7D60:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D7D6E
	b _080D7EE6
_080D7D6E:
	cmp r0, #3
	bne _080D7D74
	b _080D7EE6
_080D7D74:
	ldr r0, _080D7D84 @ =0x00000442
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	ldr r0, _080D7D88 @ =0x00000444
	adds r1, r5, r0
	movs r0, #2
	b _080D7E5E
	.align 2, 0
_080D7D84: .4byte 0x00000442
_080D7D88: .4byte 0x00000444
_080D7D8C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D7D9A
	b _080D7EE6
_080D7D9A:
	cmp r0, #3
	bne _080D7DA0
	b _080D7EE6
_080D7DA0:
	ldr r0, _080D7DB0 @ =0x00000442
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	ldr r0, _080D7DB4 @ =0x00000444
	adds r1, r5, r0
	movs r0, #3
	b _080D7E5E
	.align 2, 0
_080D7DB0: .4byte 0x00000442
_080D7DB4: .4byte 0x00000444
_080D7DB8:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D7DC6
	b _080D7EE6
_080D7DC6:
	cmp r0, #3
	bne _080D7DCC
	b _080D7EE6
_080D7DCC:
	ldr r0, _080D7DE4 @ =0x00000442
	adds r1, r5, r0
	movs r0, #3
	strh r0, [r1]
	ldr r0, _080D7DE8 @ =0x00000444
	adds r1, r5, r0
	movs r0, #6
	strh r0, [r1]
	ldr r0, _080D7DEC @ =0x00000446
	adds r1, r5, r0
	subs r0, #0xc2
	b _080D7E68
	.align 2, 0
_080D7DE4: .4byte 0x00000442
_080D7DE8: .4byte 0x00000444
_080D7DEC: .4byte 0x00000446
_080D7DF0:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080D7EE6
	cmp r0, #3
	beq _080D7EE6
	ldr r0, _080D7E10 @ =0x00000442
	adds r1, r5, r0
	movs r0, #4
	strh r0, [r1]
	ldr r0, _080D7E14 @ =0x00000444
	adds r1, r5, r0
	movs r0, #7
	b _080D7E5E
	.align 2, 0
_080D7E10: .4byte 0x00000442
_080D7E14: .4byte 0x00000444
_080D7E18:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080D7EE6
	cmp r0, #3
	beq _080D7EE6
	ldr r0, _080D7E38 @ =0x00000442
	adds r1, r5, r0
	movs r0, #5
	strh r0, [r1]
	ldr r0, _080D7E3C @ =0x00000444
	adds r1, r5, r0
	movs r0, #9
	b _080D7E5E
	.align 2, 0
_080D7E38: .4byte 0x00000442
_080D7E3C: .4byte 0x00000444
_080D7E40:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080D7EE6
	cmp r0, #3
	beq _080D7EE6
	ldr r0, _080D7E74 @ =0x00000442
	adds r1, r5, r0
	movs r0, #6
	strh r0, [r1]
	ldr r0, _080D7E78 @ =0x00000444
	adds r1, r5, r0
	movs r0, #0xa
_080D7E5E:
	strh r0, [r1]
	ldr r0, _080D7E7C @ =0x00000446
	adds r1, r5, r0
	movs r0, #0xe1
	lsls r0, r0, #3
_080D7E68:
	strh r0, [r1]
_080D7E6A:
	ldr r1, _080D7E80 @ =0x00000121
	adds r0, r5, #0
	bl FUN_080d7bc4
	b _080D7F3C
	.align 2, 0
_080D7E74: .4byte 0x00000442
_080D7E78: .4byte 0x00000444
_080D7E7C: .4byte 0x00000446
_080D7E80: .4byte 0x00000121
_080D7E84:
	ldr r1, _080D7EB8 @ =0x0000036A
	adds r4, r5, r1
	ldrh r1, [r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	movs r1, #0x64
	bl Div
	movs r1, #0xda
	lsls r1, r1, #2
	adds r2, r5, r1
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	ldrh r4, [r4]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, r4
	bls _080D7EAE
	strh r4, [r2]
_080D7EAE:
	movs r2, #0x96
	lsls r2, r2, #2
	adds r0, r5, #0
	movs r1, #2
	b _080D7EEE
	.align 2, 0
_080D7EB8: .4byte 0x0000036A
_080D7EBC:
	ldr r0, _080D7EFC @ =0x0000036A
	adds r4, r5, r0
	ldrh r1, [r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	movs r1, #0x64
	bl Div
	movs r1, #0xda
	lsls r1, r1, #2
_080D7ED2:
	adds r2, r5, r1
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	ldrh r4, [r4]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, r4
	bls _080D7EE6
	strh r4, [r2]
_080D7EE6:
	movs r2, #0x96
	lsls r2, r2, #2
	adds r0, r5, #0
	movs r1, #0
_080D7EEE:
	bl FUN_08063574
	adds r0, r5, #0
	movs r1, #0x21
	bl FUN_080d7bc4
	b _080D7F3C
	.align 2, 0
_080D7EFC: .4byte 0x0000036A
_080D7F00:
	ldr r0, _080D7F44 @ =0x00000366
	adds r4, r5, r0
	ldrh r1, [r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0x64
	bl Div
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r2, r5, r1
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	ldrh r4, [r4]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, r4
	bls _080D7F28
	strh r4, [r2]
_080D7F28:
	movs r2, #0x96
	lsls r2, r2, #2
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08063574
	adds r0, r5, #0
	movs r1, #0x21
	bl FUN_080d7bc4
_080D7F3C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D7F44: .4byte 0x00000366
