	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x34
	adds r6, r0, #0
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrh r0, [r0]
	adds r0, #0xf7
	mov r8, r0
	ldr r2, _08107AB8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	subs r1, #0x81
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08107ABC @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r4, sp, #0x2c
	movs r5, #0xa
	ldr r1, _08107AC0 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08107AC4
	asrs r1, r0, #0xc
	b _08107ACA
	.align 2, 0
_08107AB8: .4byte 0x030046B8
_08107ABC: .4byte 0x0203B400
_08107AC0: .4byte gSineTable
_08107AC4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08107ACA:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _08107AE4 @ =gSineTable
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08107AE8
	asrs r0, r0, #0xc
	b _08107AEE
	.align 2, 0
_08107AE4: .4byte gSineTable
_08107AE8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08107AEE:
	movs r1, #0
	strh r0, [r4, #4]
	add r2, sp, #0x2c
	movs r0, #0x64
	strh r0, [r2, #2]
	adds r4, r6, #0
	adds r4, #8
	ldr r2, _08107B5C @ =0x0000D45E
	ldr r3, _08107B60 @ =0x00001DC3
	movs r0, #5
	str r0, [sp]
	movs r0, #0x1a
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r0, r8
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	adds r0, r4, #0
	add r1, sp, #0x2c
	bl Entity081efa9c_Spawn
	ldr r2, _08107B64 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08107B68 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08107B6C @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r5, sp, #0x2c
	movs r6, #0xa
	ldr r1, _08107B70 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	adds r7, r4, #0
	cmp r0, #0
	blt _08107B74
	asrs r1, r0, #0xc
	b _08107B7A
	.align 2, 0
_08107B5C: .4byte 0x0000D45E
_08107B60: .4byte 0x00001DC3
_08107B64: .4byte 0x030046B8
_08107B68: .4byte 0x000003FF
_08107B6C: .4byte 0x0203B400
_08107B70: .4byte gSineTable
_08107B74:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08107B7A:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _08107B94 @ =gSineTable
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08107B98
	asrs r0, r0, #0xc
	b _08107B9E
	.align 2, 0
_08107B94: .4byte gSineTable
_08107B98:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08107B9E:
	movs r1, #0
	strh r0, [r5, #4]
	add r0, sp, #0x2c
	movs r4, #0x64
	strh r4, [r0, #2]
	ldr r2, _08107C04 @ =0x0000D45E
	ldr r3, _08107C08 @ =0x00001DC3
	movs r0, #6
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r0, r8
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	adds r0, r7, #0
	add r1, sp, #0x2c
	bl Entity081efa9c_Spawn
	ldr r2, _08107C0C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08107C10 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08107C14 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r4, sp, #0x2c
	movs r5, #0xa
	ldr r1, _08107C18 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08107C1C
	asrs r1, r0, #0xc
	b _08107C22
	.align 2, 0
_08107C04: .4byte 0x0000D45E
_08107C08: .4byte 0x00001DC3
_08107C0C: .4byte 0x030046B8
_08107C10: .4byte 0x000003FF
_08107C14: .4byte 0x0203B400
_08107C18: .4byte gSineTable
_08107C1C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08107C22:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _08107C3C @ =gSineTable
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08107C40
	asrs r0, r0, #0xc
	b _08107C46
	.align 2, 0
_08107C3C: .4byte gSineTable
_08107C40:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08107C46:
	movs r1, #0
	strh r0, [r4, #4]
	add r2, sp, #0x2c
	movs r0, #0x3c
	strh r0, [r2, #2]
	ldr r2, _08107CB0 @ =0x0000D45E
	ldr r3, _08107CB4 @ =0x00001DC3
	movs r0, #0xa
	str r0, [sp]
	movs r0, #0x64
	str r0, [sp, #4]
	ldr r0, _08107CB8 @ =0x00000202
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r0, r8
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	adds r0, r7, #0
	add r1, sp, #0x2c
	bl Entity081efa9c_Spawn
	ldr r2, _08107CBC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08107CC0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08107CC4 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r4, sp, #0x2c
	movs r5, #0xa
	ldr r1, _08107CC8 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08107CCC
	asrs r1, r0, #0xc
	b _08107CD2
	.align 2, 0
_08107CB0: .4byte 0x0000D45E
_08107CB4: .4byte 0x00001DC3
_08107CB8: .4byte 0x00000202
_08107CBC: .4byte 0x030046B8
_08107CC0: .4byte 0x000003FF
_08107CC4: .4byte 0x0203B400
_08107CC8: .4byte gSineTable
_08107CCC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08107CD2:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _08107CEC @ =gSineTable
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08107CF0
	asrs r0, r0, #0xc
	b _08107CF6
	.align 2, 0
_08107CEC: .4byte gSineTable
_08107CF0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08107CF6:
	movs r1, #0
	strh r0, [r4, #4]
	add r2, sp, #0x2c
	movs r0, #0x46
	strh r0, [r2, #2]
	ldr r2, _08107D60 @ =0x0000D45E
	ldr r3, _08107D64 @ =0x00001DC3
	movs r0, #0xa
	str r0, [sp]
	movs r0, #0x64
	str r0, [sp, #4]
	ldr r0, _08107D68 @ =0x00000202
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r0, r8
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	adds r0, r7, #0
	add r1, sp, #0x2c
	bl Entity081efa9c_Spawn
	ldr r2, _08107D6C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08107D70 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08107D74 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r4, sp, #0x2c
	movs r5, #0xa
	ldr r1, _08107D78 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08107D7C
	asrs r1, r0, #0xc
	b _08107D82
	.align 2, 0
_08107D60: .4byte 0x0000D45E
_08107D64: .4byte 0x00001DC3
_08107D68: .4byte 0x00000202
_08107D6C: .4byte 0x030046B8
_08107D70: .4byte 0x000003FF
_08107D74: .4byte 0x0203B400
_08107D78: .4byte gSineTable
_08107D7C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08107D82:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _08107D9C @ =gSineTable
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08107DA0
	asrs r0, r0, #0xc
	b _08107DA6
	.align 2, 0
_08107D9C: .4byte gSineTable
_08107DA0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08107DA6:
	movs r1, #0
	strh r0, [r4, #4]
	add r2, sp, #0x2c
	movs r0, #0x32
	strh r0, [r2, #2]
	ldr r2, _08107E10 @ =0x0000D45E
	ldr r3, _08107E14 @ =0x00001DC3
	movs r0, #7
	str r0, [sp]
	movs r0, #0x64
	str r0, [sp, #4]
	ldr r0, _08107E18 @ =0x00000202
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r0, r8
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	adds r0, r7, #0
	add r1, sp, #0x2c
	bl Entity081efa9c_Spawn
	ldr r2, _08107E1C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08107E20 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08107E24 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r4, sp, #0x2c
	movs r5, #0xa
	ldr r1, _08107E28 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08107E2C
	asrs r1, r0, #0xc
	b _08107E32
	.align 2, 0
_08107E10: .4byte 0x0000D45E
_08107E14: .4byte 0x00001DC3
_08107E18: .4byte 0x00000202
_08107E1C: .4byte 0x030046B8
_08107E20: .4byte 0x000003FF
_08107E24: .4byte 0x0203B400
_08107E28: .4byte gSineTable
_08107E2C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08107E32:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _08107E4C @ =gSineTable
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08107E50
	asrs r0, r0, #0xc
	b _08107E56
	.align 2, 0
_08107E4C: .4byte gSineTable
_08107E50:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08107E56:
	movs r1, #0
	strh r0, [r4, #4]
	add r2, sp, #0x2c
	movs r0, #0x3c
	strh r0, [r2, #2]
	ldr r2, _08107EC0 @ =0x0000D45E
	ldr r3, _08107EC4 @ =0x00001DC3
	movs r0, #7
	str r0, [sp]
	movs r0, #0x64
	str r0, [sp, #4]
	ldr r0, _08107EC8 @ =0x00000202
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r0, r8
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	adds r0, r7, #0
	add r1, sp, #0x2c
	bl Entity081efa9c_Spawn
	ldr r2, _08107ECC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08107ED0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08107ED4 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r4, sp, #0x2c
	movs r5, #0xa
	ldr r1, _08107ED8 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08107EDC
	asrs r1, r0, #0xc
	b _08107EE2
	.align 2, 0
_08107EC0: .4byte 0x0000D45E
_08107EC4: .4byte 0x00001DC3
_08107EC8: .4byte 0x00000202
_08107ECC: .4byte 0x030046B8
_08107ED0: .4byte 0x000003FF
_08107ED4: .4byte 0x0203B400
_08107ED8: .4byte gSineTable
_08107EDC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08107EE2:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _08107EFC @ =gSineTable
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08107F00
	asrs r0, r0, #0xc
	b _08107F06
	.align 2, 0
_08107EFC: .4byte gSineTable
_08107F00:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08107F06:
	movs r1, #0
	strh r0, [r4, #4]
	add r2, sp, #0x2c
	movs r0, #0x28
	strh r0, [r2, #2]
	ldr r2, _08107F70 @ =0x0000D45E
	ldr r3, _08107F74 @ =0x00001DC3
	movs r0, #8
	str r0, [sp]
	movs r0, #0x64
	str r0, [sp, #4]
	ldr r0, _08107F78 @ =0x00000202
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r0, r8
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	adds r0, r7, #0
	add r1, sp, #0x2c
	bl Entity081efa9c_Spawn
	ldr r2, _08107F7C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08107F80 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08107F84 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r4, sp, #0x2c
	movs r5, #0xa
	ldr r1, _08107F88 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08107F8C
	asrs r1, r0, #0xc
	b _08107F92
	.align 2, 0
_08107F70: .4byte 0x0000D45E
_08107F74: .4byte 0x00001DC3
_08107F78: .4byte 0x00000202
_08107F7C: .4byte 0x030046B8
_08107F80: .4byte 0x000003FF
_08107F84: .4byte 0x0203B400
_08107F88: .4byte gSineTable
_08107F8C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08107F92:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _08107FAC @ =gSineTable
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08107FB0
	asrs r0, r0, #0xc
	b _08107FB6
	.align 2, 0
_08107FAC: .4byte gSineTable
_08107FB0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08107FB6:
	movs r1, #0
	strh r0, [r4, #4]
	add r2, sp, #0x2c
	movs r0, #0x5a
	strh r0, [r2, #2]
	ldr r2, _08108020 @ =0x0000D45E
	ldr r3, _08108024 @ =0x00001DC3
	movs r0, #9
	str r0, [sp]
	movs r0, #0x64
	str r0, [sp, #4]
	ldr r0, _08108028 @ =0x00000202
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r0, r8
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	adds r0, r7, #0
	add r1, sp, #0x2c
	bl Entity081efa9c_Spawn
	ldr r2, _0810802C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08108030 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08108034 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r4, sp, #0x2c
	movs r5, #0xa
	ldr r1, _08108038 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0810803C
	asrs r1, r0, #0xc
	b _08108042
	.align 2, 0
_08108020: .4byte 0x0000D45E
_08108024: .4byte 0x00001DC3
_08108028: .4byte 0x00000202
_0810802C: .4byte 0x030046B8
_08108030: .4byte 0x000003FF
_08108034: .4byte 0x0203B400
_08108038: .4byte gSineTable
_0810803C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08108042:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _0810805C @ =gSineTable
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08108060
	asrs r0, r0, #0xc
	b _08108066
	.align 2, 0
_0810805C: .4byte gSineTable
_08108060:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08108066:
	movs r1, #0
	strh r0, [r4, #4]
	add r2, sp, #0x2c
	movs r0, #0x32
	strh r0, [r2, #2]
	ldr r2, _081080A8 @ =0x0000D45E
	ldr r3, _081080AC @ =0x00001DC3
	movs r0, #0xb
	str r0, [sp]
	movs r0, #0x64
	str r0, [sp, #4]
	ldr r0, _081080B0 @ =0x00000202
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r0, r8
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	adds r0, r7, #0
	add r1, sp, #0x2c
	bl Entity081efa9c_Spawn
	add sp, #0x34
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081080A8: .4byte 0x0000D45E
_081080AC: .4byte 0x00001DC3
_081080B0: .4byte 0x00000202
