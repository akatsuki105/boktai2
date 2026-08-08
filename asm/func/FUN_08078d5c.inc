	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0x80
	lsls r0, r0, #7
	ldr r1, [r5, #0x20]
	orrs r1, r0
	str r1, [r5, #0x20]
	ldr r0, [r5, #0x1c]
	cmp r0, #2
	bne _08078D74
	b _08079104
_08078D74:
	cmp r0, #2
	bhi _08078D7E
	cmp r0, #1
	beq _08078D86
	b _0807912E
_08078D7E:
	cmp r0, #4
	bne _08078D84
	b _080790B0
_08078D84:
	b _0807912E
_08078D86:
	adds r0, r5, #0
	bl FUN_0807858c
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08078DAA
	adds r0, r5, #0
	bl FUN_0806680c
	cmp r0, #0
	beq _08078DDC
	adds r0, r5, #0
	bl FUN_0806687c
	b _08078DDC
_08078DAA:
	ldr r0, [r5, #0x20]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08078DC6
	ldr r0, _08078E1C @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _08078E20 @ =0x00000942
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl FUN_080667b0
_08078DC6:
	adds r0, r5, #0
	bl FUN_0806680c
	cmp r0, #0
	beq _08078DDC
	adds r0, r5, #0
	bl FUN_0806687c
	adds r0, r5, #0
	bl FUN_0806692c
_08078DDC:
	adds r0, r5, #0
	bl FUN_080784fc
	adds r0, r5, #0
	bl FUN_080788d0
	adds r4, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08066d7c
	ldr r1, _08078E24 @ =0x085ABCAC
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	movs r4, #0xe9
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _08078E28
	movs r1, #0xea
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x34]
	str r1, [r5, #0x38]
	b _08078E2E
	.align 2, 0
_08078E1C: .4byte 0x030046A0
_08078E20: .4byte 0x00000942
_08078E24: .4byte 0x085ABCAC
_08078E28:
	adds r0, r5, #0
	bl FUN_08066408
_08078E2E:
	adds r0, r5, #0
	bl FUN_08078bc0
	ldr r2, _08078F14 @ =0x000003CE
	adds r0, r5, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	beq _08078E46
	adds r0, r5, #0
	bl FUN_08066df8
_08078E46:
	adds r0, r5, #0
	bl FUN_08065b7c
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #1
	bne _08078E5E
	adds r0, r5, #0
	bl FUN_08065dac
_08078E5E:
	adds r0, r5, #0
	bl FUN_0806623c
	ldr r1, _08078F18 @ =0x00000446
	adds r0, r5, r1
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _08078E7C
	ldr r2, _08078F1C @ =0x00000442
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #5
	bne _08078E7C
	movs r1, #1
_08078E7C:
	cmp r1, #0
	beq _08078E82
	b _0807912E
_08078E82:
	movs r4, #0
	movs r3, #0xe5
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	bl FUN_08065b44
	cmp r0, #0
	bne _08078EC0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r2, [r0]
	cmp r2, #1
	bne _08078EC0
	movs r3, #0xde
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _08078EC0
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r1, [r0]
	ands r1, r2
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r4, r0, #0x1f
_08078EC0:
	cmp r4, #0
	bne _08078EC6
	b _080790A4
_08078EC6:
	ldr r0, _08078F20 @ =0x000003BE
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	beq _08078EDA
	b _0807912E
_08078EDA:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _08078F24 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x32
	muls r0, r1, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _08078F28
	asrs r2, r0, #0xc
	b _08078F2E
	.align 2, 0
_08078F14: .4byte 0x000003CE
_08078F18: .4byte 0x00000446
_08078F1C: .4byte 0x00000442
_08078F20: .4byte 0x000003BE
_08078F24: .4byte 0x085B0A08
_08078F28:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08078F2E:
	mov r0, sp
	ldrh r1, [r0]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08078F58 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	lsls r0, r3, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _08078F5C
	asrs r2, r0, #0xc
	b _08078F62
	.align 2, 0
_08078F58: .4byte 0xFFFF0000
_08078F5C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08078F62:
	mov r0, sp
	ldrh r1, [r0, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08078FA4 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	mov r6, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08078F9E
	cmp r1, #0
	blt _08078F9E
	ldr r0, _08078FA8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08078F9E
	ldr r0, _08078FAC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08078FB0
_08078F9E:
	movs r4, #0
	b _08078FBE
	.align 2, 0
_08078FA4: .4byte 0xFFFF0000
_08078FA8: .4byte 0x030046A8
_08078FAC: .4byte 0x030046AC
_08078FB0:
	ldr r0, _08078FD0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08078FBE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08078FD4
	adds r0, #4
	b _08078FE0
	.align 2, 0
_08078FD0: .4byte 0x030046A4
_08078FD4:
	ldr r0, _08078FF4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08078FE0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08078FF8
	cmp r2, #2
	beq _08078FFC
	b _08079000
	.align 2, 0
_08078FF4: .4byte 0x030046A4
_08078FF8:
	ldrb r0, [r6, #4]
	b _08078FFE
_08078FFC:
	ldrb r0, [r6]
_08078FFE:
	subs r1, r1, r0
_08079000:
	movs r3, #0x2e
	ldrsh r0, [r5, r3]
	adds r0, #0xc8
	cmp r1, r0
	bhs _0807900C
	b _0807912E
_0807900C:
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08079034
	cmp r1, #0
	blt _08079034
	ldr r0, _08079038 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08079034
	ldr r0, _0807903C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08079040
_08079034:
	movs r4, #0
	b _0807904E
	.align 2, 0
_08079038: .4byte 0x030046A8
_0807903C: .4byte 0x030046AC
_08079040:
	ldr r0, _08079060 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0807904E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08079064
	adds r0, #4
	b _08079070
	.align 2, 0
_08079060: .4byte 0x030046A4
_08079064:
	ldr r0, _0807909C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08079070:
	ldrh r2, [r0, #2]
	movs r0, #4
	ands r2, r0
	cmp r2, #0
	bne _0807912E
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r1, [r0]
	ldr r3, _080790A0 @ =0x000003BD
	adds r0, r5, r3
	strb r1, [r0]
	adds r4, #0xd4
	adds r0, r5, r4
	strb r2, [r0]
	adds r0, r5, #0
	movs r1, #4
	movs r2, #0
	bl FUN_08060b84
	b _0807912E
	.align 2, 0
_0807909C: .4byte 0x030046A4
_080790A0: .4byte 0x000003BD
_080790A4:
	ldr r1, _080790AC @ =0x000003BE
	adds r0, r5, r1
	strh r4, [r0]
	b _0807912E
	.align 2, 0
_080790AC: .4byte 0x000003BE
_080790B0:
	movs r0, #0x80
	lsls r0, r0, #0xb
	orrs r1, r0
	str r1, [r5, #0x20]
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08060c40
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrb r0, [r1]
	subs r0, #0x1c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _080790D6
	ldrb r4, [r1]
	b _080790E4
_080790D6:
	ldr r3, _080790FC @ =0x000003D2
	adds r0, r5, r3
	ldrb r0, [r0]
	movs r4, #0x1a
	cmp r0, #0
	beq _080790E4
	movs r4, #0x1b
_080790E4:
	ldr r0, _08079100 @ =0x085ABCAC
	lsls r1, r4, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	bl FUN_08078bc0
	b _0807912E
	.align 2, 0
_080790FC: .4byte 0x000003D2
_08079100: .4byte 0x085ABCAC
_08079104:
	movs r0, #0x80
	lsls r0, r0, #0xb
	orrs r1, r0
	str r1, [r5, #0x20]
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08060c40
	movs r4, #0x93
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	bl FUN_08078bc0
	adds r0, r5, #0
	bl FUN_080726ec
_0807912E:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
