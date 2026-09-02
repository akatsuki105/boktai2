	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08052290
FUN_08052290: @ 0x08052290
	push {lr}
	movs r2, #0
	strb r1, [r0, #0x1c]
	movs r1, #1
	strb r1, [r0, #0x1d]
	str r2, [r0, #0x18]
	strb r2, [r0, #0x1e]
	adds r1, r0, #0
	adds r1, #0x40
	movs r3, #1
	movs r2, #3
_080522A6:
	ldr r0, [r1, #8]
	orrs r0, r3
	str r0, [r1, #8]
	subs r2, #1
	adds r1, #0x60
	cmp r2, #0
	bge _080522A6
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080522bc
FUN_080522bc: @ 0x080522BC
	movs r1, #1
	strb r1, [r0, #0x1e]
	movs r0, #0
	bx lr

	thumb_func_start FUN_080522c4
FUN_080522c4: @ 0x080522C4
	ldr r0, _080522CC @ =0x0300011C
	ldr r0, [r0]
	bx lr
	.align 2, 0
_080522CC: .4byte 0x0300011C

	thumb_func_start FUN_080522d0
FUN_080522d0: @ 0x080522D0
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	str r1, [sp, #0xc]
	ldr r0, _08052324 @ =0x0000C091
	ldr r1, _08052328 @ =0x0000CD91
	bl GetFile
	adds r2, r0, #0
	str r2, [r4, #0x2c]
	movs r4, #0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _0805232C @ =0x000092B3
	ldr r1, _08052330 @ =0x000026BB
	bl GetFile
	adds r0, #0x14
	ldr r1, _08052334 @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08052324: .4byte 0x0000C091
_08052328: .4byte 0x0000CD91
_0805232C: .4byte 0x000092B3
_08052330: .4byte 0x000026BB
_08052334: .4byte 0x03004250

	thumb_func_start FUN_08052338
FUN_08052338: @ 0x08052338
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #0x1d]
	cmp r0, #0
	beq _08052346
	movs r0, #0
	strb r0, [r1, #0x1d]
_08052346:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805234c
FUN_0805234c: @ 0x0805234C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	adds r7, r0, #0
	ldrb r0, [r7, #0x1d]
	cmp r0, #0
	beq _08052364
	movs r0, #0
	strb r0, [r7, #0x1d]
_08052364:
	ldr r0, _080523B0 @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _080523B4 @ =0x0000030F
	ands r0, r1
	cmp r0, #0
	beq _08052374
	movs r0, #0x64
	str r0, [r7, #0x18]
_08052374:
	ldr r0, [r7, #0x18]
	cmp r0, #0x1d
	bhi _080523C4
	ldr r0, _080523B8 @ =0x0203B400
	mov r8, r0
	ldr r1, _080523BC @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r4, _080523C0 @ =0x000003FF
	ands r0, r4
	str r0, [r1]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0x63
	bl Mod
	str r0, [sp, #0x14]
	ldr r1, _080523BC @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ands r0, r4
	str r0, [r1]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0x63
	bl Mod
	b _080523CE
	.align 2, 0
_080523B0: .4byte 0x030044E0
_080523B4: .4byte 0x0000030F
_080523B8: .4byte 0x0203B400
_080523BC: .4byte 0x030046B8
_080523C0: .4byte 0x000003FF
_080523C4:
	ldrb r0, [r7, #0x1e]
	str r0, [sp, #0x14]
	adds r0, r7, #0
	adds r0, #0x21
	ldrb r0, [r0]
_080523CE:
	str r0, [sp, #0x1c]
	ldr r0, [r7, #0x18]
	cmp r0, #0x3b
	bhi _08052420
	ldr r1, _08052414 @ =0x0203B400
	mov sb, r1
	ldr r1, _08052418 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _0805241C @ =0x000003FF
	mov r8, r1
	ands r0, r1
	ldr r1, _08052418 @ =0x030046B8
	str r0, [r1]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	movs r1, #0x3c
	bl Mod
	str r0, [sp, #0x18]
	ldr r1, _08052418 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	ldr r1, _08052418 @ =0x030046B8
	str r0, [r1]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	movs r1, #0x3c
	bl Mod
	b _0805242A
	.align 2, 0
_08052414: .4byte 0x0203B400
_08052418: .4byte 0x030046B8
_0805241C: .4byte 0x000003FF
_08052420:
	ldrb r0, [r7, #0x1f]
	str r0, [sp, #0x18]
	adds r0, r7, #0
	adds r0, #0x22
	ldrb r0, [r0]
_0805242A:
	str r0, [sp, #0x20]
	ldr r0, [r7, #0x18]
	cmp r0, #0x59
	bhi _0805247C
	ldr r1, _08052470 @ =0x0203B400
	mov sb, r1
	ldr r1, _08052474 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _08052478 @ =0x000003FF
	mov r8, r1
	ands r0, r1
	ldr r1, _08052474 @ =0x030046B8
	str r0, [r1]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	movs r1, #0x63
	bl Mod
	mov sl, r0
	ldr r1, _08052474 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	ldr r1, _08052474 @ =0x030046B8
	str r0, [r1]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	movs r1, #0x63
	bl Mod
	b _0805248A
	.align 2, 0
_08052470: .4byte 0x0203B400
_08052474: .4byte 0x030046B8
_08052478: .4byte 0x000003FF
_0805247C:
	adds r0, r7, #0
	adds r0, #0x20
	ldrb r0, [r0]
	mov sl, r0
	adds r0, r7, #0
	adds r0, #0x23
	ldrb r0, [r0]
_0805248A:
	str r0, [sp, #0x24]
	ldr r0, [r7, #0x18]
	cmp r0, #0x59
	bhi _080524A2
	movs r1, #2
	bl Mod
	cmp r0, #0
	bne _080524A2
	ldr r0, _080525B8 @ =0x000002A5
	bl PlaySound_082406e0
_080524A2:
	ldr r0, [sp, #0x14]
	cmp r0, #0x63
	ble _080524AC
	movs r1, #0x63
	str r1, [sp, #0x14]
_080524AC:
	ldr r0, [sp, #0x1c]
	cmp r0, #0x63
	ble _080524B6
	movs r1, #0x63
	str r1, [sp, #0x1c]
_080524B6:
	ldr r0, [sp, #0x18]
	cmp r0, #0x3b
	ble _080524C0
	movs r1, #0x3b
	str r1, [sp, #0x18]
_080524C0:
	ldr r0, [sp, #0x20]
	cmp r0, #0x3b
	ble _080524CA
	movs r1, #0x3b
	str r1, [sp, #0x20]
_080524CA:
	mov r0, sl
	cmp r0, #0x63
	ble _080524D4
	movs r1, #0x63
	mov sl, r1
_080524D4:
	ldr r0, [sp, #0x24]
	cmp r0, #0x63
	ble _080524DE
	movs r1, #0x63
	str r1, [sp, #0x24]
_080524DE:
	adds r0, r7, #0
	adds r0, #0xd0
	adds r5, r7, #0
	adds r5, #0x30
	movs r6, #0
	str r6, [sp]
	movs r1, #0xa8
	str r1, [sp, #4]
	movs r1, #0x20
	str r1, [sp, #8]
	movs r1, #8
	mov sb, r1
	str r1, [sp, #0xc]
	str r6, [sp, #0x10]
	adds r1, r5, #0
	ldr r2, [sp, #0x14]
	movs r3, #2
	bl FUN_082376a4
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r7, r1
	str r6, [sp]
	movs r1, #0xc0
	str r1, [sp, #4]
	movs r1, #0x20
	str r1, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	str r6, [sp, #0x10]
	adds r1, r5, #0
	ldr r2, [sp, #0x18]
	movs r3, #2
	bl FUN_082376a4
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r7, r1
	str r6, [sp]
	movs r1, #0xd8
	mov r8, r1
	str r1, [sp, #4]
	movs r1, #0x20
	str r1, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	str r6, [sp, #0x10]
	adds r1, r5, #0
	mov r2, sl
	movs r3, #2
	bl FUN_082376a4
	movs r1, #0xc4
	lsls r1, r1, #2
	adds r0, r7, r1
	str r6, [sp]
	movs r1, #0xa8
	str r1, [sp, #4]
	movs r1, #0x38
	str r1, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	str r6, [sp, #0x10]
	adds r1, r5, #0
	ldr r2, [sp, #0x1c]
	movs r3, #2
	bl FUN_082376a4
	movs r1, #0xf4
	lsls r1, r1, #2
	adds r0, r7, r1
	str r6, [sp]
	movs r1, #0xc0
	str r1, [sp, #4]
	movs r1, #0x38
	str r1, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	str r6, [sp, #0x10]
	adds r1, r5, #0
	ldr r2, [sp, #0x20]
	movs r3, #2
	bl FUN_082376a4
	movs r1, #0x92
	lsls r1, r1, #3
	adds r0, r7, r1
	str r6, [sp]
	mov r1, r8
	str r1, [sp, #4]
	movs r1, #0x38
	str r1, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	str r6, [sp, #0x10]
	adds r1, r5, #0
	ldr r2, [sp, #0x24]
	movs r3, #2
	bl FUN_082376a4
	ldr r0, [r7, #0x18]
	cmp r0, #0x63
	bls _080525BC
	movs r0, #2
	strb r0, [r7, #0x1c]
	movs r0, #1
	strb r0, [r7, #0x1d]
	str r6, [r7, #0x18]
	b _080525C0
	.align 2, 0
_080525B8: .4byte 0x000002A5
_080525BC:
	adds r0, #1
	str r0, [r7, #0x18]
_080525C0:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080525d0
FUN_080525d0: @ 0x080525D0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r0, [r7, #0x1d]
	cmp r0, #0
	beq _08052668
	movs r0, #0
	strb r0, [r7, #0x1d]
	adds r0, r7, #0
	adds r0, #0x24
	ldrb r1, [r0]
	movs r5, #0x48
	adds r3, r0, #0
	cmp r1, #0
	beq _080525F4
	movs r5, #0x4a
	cmp r1, #1
	bne _080525F4
	movs r5, #0x49
_080525F4:
	ldr r0, _0805262C @ =gSystemSaveData
	ldr r1, [r0]
	ldrh r1, [r1, #0x14]
	adds r1, #1
	ldr r2, _08052630 @ =0x0000270F
	adds r4, r0, #0
	cmp r1, r2
	ble _08052606
	adds r1, r2, #0
_08052606:
	ldr r0, [r4]
	strh r1, [r0, #0x14]
	ldrb r0, [r3]
	cmp r0, #0
	bne _08052634
	movs r0, #0xb0
	bl sound_08240264
	ldr r0, [r4]
	ldrh r0, [r0, #0x16]
	adds r1, r0, #1
	ldr r0, _08052630 @ =0x0000270F
	cmp r1, r0
	ble _08052624
	adds r1, r0, #0
_08052624:
	ldr r0, _0805262C @ =gSystemSaveData
	ldr r0, [r0]
	strh r1, [r0, #0x16]
	b _08052646
	.align 2, 0
_0805262C: .4byte gSystemSaveData
_08052630: .4byte 0x0000270F
_08052634:
	cmp r0, #1
	bne _08052640
	movs r0, #0xb1
	bl sound_08240264
	b _08052646
_08052640:
	movs r0, #0xb1
	bl sound_08240264
_08052646:
	adds r6, r7, #0
	adds r6, #0x70
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	adds r1, r7, #0
	adds r1, #0x30
	adds r2, r5, #0
	adds r0, r6, #0
	movs r3, #0
	bl Sprite_SetSprite
	movs r0, #0
	strh r0, [r6, #0x20]
	strh r0, [r6, #0x22]
_08052668:
	ldr r0, [r7, #0x18]
	cmp r0, #7
	bhi _080526AC
	adds r6, r7, #0
	adds r6, #0x70
	ldr r5, _080526A0 @ =0x0203B400
	ldr r2, _080526A4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r4, _080526A8 @ =0x000003FF
	ands r0, r4
	str r0, [r2]
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	movs r3, #3
	ands r1, r3
	subs r1, #2
	strh r1, [r6, #0x20]
	adds r0, #1
	ands r0, r4
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r3
	subs r0, #2
	b _080526B8
	.align 2, 0
_080526A0: .4byte 0x0203B400
_080526A4: .4byte 0x030046B8
_080526A8: .4byte 0x000003FF
_080526AC:
	cmp r0, #8
	bne _080526BA
	adds r6, r7, #0
	adds r6, #0x70
	movs r0, #0
	strh r0, [r6, #0x20]
_080526B8:
	strh r0, [r6, #0x22]
_080526BA:
	ldr r0, [r7, #0x18]
	cmp r0, #0x1d
	bls _080526CE
	movs r0, #3
	movs r1, #0
	strb r0, [r7, #0x1c]
	movs r0, #1
	strb r0, [r7, #0x1d]
	str r1, [r7, #0x18]
	b _080526D2
_080526CE:
	adds r0, #1
	str r0, [r7, #0x18]
_080526D2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080526d8
FUN_080526d8: @ 0x080526D8
	push {r4, r5, lr}
	sub sp, #0x14
	adds r5, r0, #0
	ldrb r0, [r5, #0x1d]
	cmp r0, #0
	beq _080526E8
	movs r0, #0
	strb r0, [r5, #0x1d]
_080526E8:
	ldr r0, _08052728 @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _0805272C @ =0x0000030F
	ands r0, r1
	cmp r0, #0
	beq _080526F8
	movs r0, #0x80
	str r0, [r5, #0x18]
_080526F8:
	ldr r1, [r5, #0x18]
	cmp r1, #0x40
	bhi _08052738
	movs r2, #0x28
	ldrsh r0, [r5, r2]
	muls r0, r1, r0
	lsrs r4, r0, #6
	ldr r0, _08052730 @ =0x0000270F
	cmp r4, r0
	bls _0805270E
	adds r4, r0, #0
_0805270E:
	cmp r4, #0
	beq _0805273C
	adds r0, r1, #0
	movs r1, #2
	bl Mod
	cmp r0, #0
	bne _0805273C
	ldr r0, _08052734 @ =0x000002A5
	bl PlaySound_082406e0
	b _0805273C
	.align 2, 0
_08052728: .4byte 0x030044E0
_0805272C: .4byte 0x0000030F
_08052730: .4byte 0x0000270F
_08052734: .4byte 0x000002A5
_08052738:
	movs r0, #0x28
	ldrsh r4, [r5, r0]
_0805273C:
	movs r2, #0xaa
	lsls r2, r2, #3
	adds r3, r5, r2
	adds r2, r4, #0
	ldr r0, _08052750 @ =0x0000270F
	cmp r2, r0
	ble _08052754
	adds r2, r0, #0
	b _0805275A
	.align 2, 0
_08052750: .4byte 0x0000270F
_08052754:
	cmp r2, #0
	bge _0805275A
	movs r2, #0
_0805275A:
	adds r1, r5, #0
	adds r1, #0x30
	movs r4, #0
	str r4, [sp]
	movs r0, #0x68
	str r0, [sp, #4]
	movs r0, #0x60
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	str r4, [sp, #0x10]
	adds r0, r3, #0
	movs r3, #4
	bl FUN_082376a4
	ldr r0, [r5, #0x18]
	cmp r0, #0x7f
	bls _0805278A
	movs r0, #4
	strb r0, [r5, #0x1c]
	movs r0, #1
	strb r0, [r5, #0x1d]
	str r4, [r5, #0x18]
	b _0805278E
_0805278A:
	adds r0, #1
	str r0, [r5, #0x18]
_0805278E:
	add sp, #0x14
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08052798
FUN_08052798: @ 0x08052798
	push {r4, r5, lr}
	sub sp, #0x14
	adds r5, r0, #0
	ldrb r0, [r5, #0x1d]
	cmp r0, #0
	beq _080527B0
	movs r0, #0
	strb r0, [r5, #0x1d]
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #2
	strb r0, [r1]
_080527B0:
	movs r1, #0x28
	ldrsh r0, [r5, r1]
	adds r2, r5, #0
	adds r2, #0x25
	cmp r0, #8
	ble _080527CC
	ldr r0, _080527F8 @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _080527FC @ =0x0000030F
	ands r0, r1
	cmp r0, #0
	beq _080527CC
	movs r0, #8
	strb r0, [r2]
_080527CC:
	movs r1, #0x28
	ldrsh r0, [r5, r1]
	ldrb r1, [r2]
	cmp r0, r1
	blt _08052804
	ldrh r0, [r5, #0x28]
	subs r0, r0, r1
	strh r0, [r5, #0x28]
	ldrh r0, [r5, #0x2a]
	ldrb r2, [r2]
	adds r0, r0, r2
	strh r0, [r5, #0x2a]
	ldr r0, [r5, #0x18]
	movs r1, #2
	bl Mod
	cmp r0, #0
	bne _08052810
	ldr r0, _08052800 @ =0x000002A5
	bl PlaySound_082406e0
	b _08052810
	.align 2, 0
_080527F8: .4byte 0x030044E0
_080527FC: .4byte 0x0000030F
_08052800: .4byte 0x000002A5
_08052804:
	ldrh r0, [r5, #0x28]
	ldrh r2, [r5, #0x2a]
	adds r0, r0, r2
	movs r1, #0
	strh r0, [r5, #0x2a]
	strh r1, [r5, #0x28]
_08052810:
	movs r1, #0x2a
	ldrsh r0, [r5, r1]
	ldr r1, _0805283C @ =0x0000270F
	cmp r0, r1
	ble _0805281C
	strh r1, [r5, #0x2a]
_0805281C:
	movs r2, #0x28
	ldrsh r0, [r5, r2]
	cmp r0, #0
	bge _08052828
	movs r0, #0
	strh r0, [r5, #0x28]
_08052828:
	movs r0, #0xaa
	lsls r0, r0, #3
	adds r3, r5, r0
	movs r0, #0x28
	ldrsh r2, [r5, r0]
	cmp r2, r1
	ble _08052840
	adds r2, r1, #0
	b _08052846
	.align 2, 0
_0805283C: .4byte 0x0000270F
_08052840:
	cmp r2, #0
	bge _08052846
	movs r2, #0
_08052846:
	adds r4, r5, #0
	adds r4, #0x30
	movs r1, #0
	str r1, [sp]
	movs r0, #0x68
	str r0, [sp, #4]
	movs r0, #0x60
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	adds r0, r3, #0
	adds r1, r4, #0
	movs r3, #4
	bl FUN_082376a4
	movs r1, #0xda
	lsls r1, r1, #3
	adds r3, r5, r1
	movs r0, #0x2a
	ldrsh r2, [r5, r0]
	ldr r0, _0805287C @ =0x0000270F
	cmp r2, r0
	ble _08052880
	adds r2, r0, #0
	b _08052886
	.align 2, 0
_0805287C: .4byte 0x0000270F
_08052880:
	cmp r2, #0
	bge _08052886
	movs r2, #0
_08052886:
	movs r1, #0
	str r1, [sp]
	movs r0, #0x68
	str r0, [sp, #4]
	movs r0, #0x88
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	adds r0, r3, #0
	adds r1, r4, #0
	movs r3, #4
	bl FUN_082376a4
	movs r2, #0x28
	ldrsh r1, [r5, r2]
	cmp r1, #0
	bne _080528B6
	movs r0, #5
	strb r0, [r5, #0x1c]
	movs r0, #1
	strb r0, [r5, #0x1d]
	str r1, [r5, #0x18]
	b _080528BC
_080528B6:
	ldr r0, [r5, #0x18]
	adds r0, #1
	str r0, [r5, #0x18]
_080528BC:
	add sp, #0x14
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080528c4
FUN_080528c4: @ 0x080528C4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080528D2
	movs r0, #0
	strb r0, [r4, #0x1d]
_080528D2:
	ldr r2, [r4, #0x18]
	cmp r2, #0x1d
	bls _08052910
	ldr r0, _08052908 @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _0805290C @ =0x0000030F
	ands r0, r1
	cmp r0, #0
	beq _08052910
	movs r0, #4
	bl FUN_082403d0
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r1, #0x8b
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08052900
	bl _call_via_r0
_08052900:
	adds r0, r4, #0
	bl KillEntity
	b _08052914
	.align 2, 0
_08052908: .4byte 0x030044E0
_0805290C: .4byte 0x0000030F
_08052910:
	adds r0, r2, #1
	str r0, [r4, #0x18]
_08052914:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Entity723E_Update
Entity723E_Update: @ 0x0805291C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl FUN_0804e59c
	cmp r0, #0
	beq _08052948
	ldr r0, _08052944 @ =0x000008B8
	adds r6, r5, r0
	movs r4, #3
_0805292E:
	ldm r6!, {r0}
	bl FUN_0804a16c
	subs r4, #1
	cmp r4, #0
	bge _0805292E
	adds r0, r5, #0
	bl KillEntity
	b _08052958
	.align 2, 0
_08052944: .4byte 0x000008B8
_08052948:
	ldr r0, _08052960 @ =0x085AB724
	ldrb r1, [r5, #0x1c]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r5, #0
	bl _call_via_r1
_08052958:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08052960: .4byte 0x085AB724

	thumb_func_start Entity723E_Destroy
Entity723E_Destroy: @ 0x08052964
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x70
	movs r5, #0x14
_0805296E:
	adds r0, r4, #0
	bl FUN_0822f1c0
	subs r5, #1
	adds r4, #0x60
	cmp r5, #0
	bge _0805296E
	movs r0, #0x85
	lsls r0, r0, #4
	adds r4, r6, r0
	adds r0, r4, #0
	bl FUN_0822f1c0
	ldr r0, _080529A8 @ =0x000008B8
	adds r4, r6, r0
	movs r5, #3
_0805298E:
	ldm r4!, {r0}
	bl FUN_0804a16c
	subs r5, #1
	cmp r5, #0
	bge _0805298E
	ldr r1, _080529AC @ =0x0300011C
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080529A8: .4byte 0x000008B8
_080529AC: .4byte 0x0300011C

	thumb_func_start Entity723E_Init
Entity723E_Init: @ 0x080529B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r0, _080529E0 @ =0x0300011C
	str r7, [r0]
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _080529DA
	bl FUN_0823d340
	ldr r2, _080529E4 @ =0x000008B4
	adds r1, r7, r2
	str r0, [r1]
	cmp r0, #0
	bne _080529E8
_080529DA:
	movs r0, #1
	rsbs r0, r0, #0
	b _08052AC6
	.align 2, 0
_080529E0: .4byte 0x0300011C
_080529E4: .4byte 0x000008B4
_080529E8:
	ldr r5, _08052AD8 @ =0x0000CB05
	ldr r1, _08052ADC @ =0x0000DCC1
	adds r0, r5, #0
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	beq _080529DA
	adds r1, r7, #0
	adds r1, #0x30
	adds r0, r2, #0
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r4, r7, #0
	adds r4, #0x30
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	ldr r1, _08052AE0 @ =0x0000D27A
	adds r0, r5, #0
	bl GetFile
	adds r2, r0, #0
	mov sb, r4
	cmp r2, #0
	beq _080529DA
	adds r0, r7, #0
	adds r0, #0x50
	adds r1, r2, #0
	ldm r1!, {r3, r5, r6}
	stm r0!, {r3, r5, r6}
	ldm r1!, {r4, r5, r6}
	stm r0!, {r4, r5, r6}
	ldm r1!, {r3, r4}
	stm r0!, {r3, r4}
	adds r4, r7, #0
	adds r4, #0x50
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	adds r6, r7, #0
	adds r6, #0x70
	mov sl, r4
	movs r4, #0
	movs r5, #0x14
_08052A4E:
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #0x3c
	mov r8, r0
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r6, #0
	mov r1, sb
	movs r2, #0
	ldr r3, _08052AE4 @ =0x00002011
	bl FUN_0822f3fc
	subs r5, #1
	adds r6, #0x60
	cmp r5, #0
	bge _08052A4E
	movs r1, #0x85
	lsls r1, r1, #4
	adds r6, r7, r1
	ldr r3, _08052AE4 @ =0x00002011
	movs r5, #0
	str r5, [sp]
	str r5, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r6, #0
	mov r1, sl
	movs r2, #0
	bl FUN_0822f3fc
	ldr r3, _08052AE8 @ =0x000008C8
	adds r4, r7, r3
	movs r0, #0
	bl FUN_0804f814
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x10
	bl FUN_08230ab0
	ldr r6, _08052AEC @ =0x000008D8
	adds r4, r7, r6
	movs r0, #1
	bl FUN_0804f814
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x10
	bl FUN_08230ab0
	strb r5, [r7, #0x1c]
	movs r0, #1
	strb r0, [r7, #0x1d]
	str r5, [r7, #0x18]
	movs r1, #0x8b
	lsls r1, r1, #4
	adds r0, r7, r1
	str r5, [r0]
	movs r0, #0
_08052AC6:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08052AD8: .4byte 0x0000CB05
_08052ADC: .4byte 0x0000DCC1
_08052AE0: .4byte 0x0000D27A
_08052AE4: .4byte 0x00002011
_08052AE8: .4byte 0x000008C8
_08052AEC: .4byte 0x000008D8

	thumb_func_start Entity723E_Create
Entity723E_Create: @ 0x08052AF0
	push {r4, lr}
	bl FUN_080522c4
	adds r4, r0, #0
	cmp r4, #0
	bne _08052B36
	ldr r1, _08052B28 @ =0x000008E8
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08052B34
	ldr r1, _08052B2C @ =Entity723E_Update
	ldr r2, _08052B30 @ =Entity723E_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity723E_Init
	cmp r0, #0
	bge _08052B34
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08052B36
	.align 2, 0
_08052B28: .4byte 0x000008E8
_08052B2C: .4byte Entity723E_Update
_08052B30: .4byte Entity723E_Destroy
_08052B34:
	adds r0, r4, #0
_08052B36:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08052b3c
FUN_08052b3c: @ 0x08052B3C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r4, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	mov r8, r3
	bl FUN_080522c4
	adds r5, r0, #0
	cmp r5, #0
	bne _08052B5C
	b _08052EA4
_08052B5C:
	adds r0, r5, #0
	adds r0, #0x26
	movs r1, #0
	mov sb, r1
	strb r4, [r0]
	subs r0, #2
	strb r6, [r0]
	movs r0, #0x8b
	lsls r0, r0, #4
	adds r1, r5, r0
	ldr r0, [sp, #0x3c]
	str r0, [r1]
	ldr r2, _08052C34 @ =0x03003E78
	ldr r0, _08052C38 @ =0xFFFFF3FF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #7
	bl FUN_0809c08c
	movs r0, #0
	bl FUN_0822b644
	adds r0, r5, #0
	movs r1, #0xc
	bl FUN_080522d0
	ldr r1, _08052C3C @ =FUN_0822e424
	ldr r2, _08052C40 @ =FUN_0822af38
	ldr r3, _08052C44 @ =FUN_0822f264
	movs r0, #0
	bl FUN_0822a448
	movs r0, #1
	strb r0, [r5, #0x1c]
	strb r0, [r5, #0x1d]
	mov r1, sb
	str r1, [r5, #0x18]
	movs r4, #0xe1
	lsls r4, r4, #4
	adds r0, r7, #0
	adds r1, r4, #0
	bl Div
	strb r0, [r5, #0x1e]
	adds r0, r7, #0
	adds r1, r4, #0
	bl Mod
	adds r6, r0, #0
	movs r1, #0x3c
	bl Div
	strb r0, [r5, #0x1f]
	adds r0, r6, #0
	movs r1, #0x3c
	bl Mod
	movs r7, #0x64
	muls r0, r7, r0
	movs r1, #0x3c
	bl Div
	adds r1, r5, #0
	adds r1, #0x20
	strb r0, [r1]
	mov r0, r8
	adds r1, r4, #0
	bl Div
	adds r1, r5, #0
	adds r1, #0x21
	strb r0, [r1]
	mov r0, r8
	adds r1, r4, #0
	bl Mod
	adds r6, r0, #0
	movs r1, #0x3c
	bl Div
	adds r1, r5, #0
	adds r1, #0x22
	strb r0, [r1]
	adds r0, r6, #0
	movs r1, #0x3c
	bl Mod
	muls r0, r7, r0
	movs r1, #0x3c
	bl Div
	adds r1, r5, #0
	adds r1, #0x23
	strb r0, [r1]
	mov r0, sp
	ldrh r0, [r0, #0x34]
	strh r0, [r5, #0x28]
	ldr r0, [sp, #0x38]
	strh r0, [r5, #0x2a]
	ldr r1, [sp, #0x34]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	ldr r1, _08052C48 @ =0x0000270F
	cmp r0, r1
	ble _08052C4C
	strh r1, [r5, #0x28]
	b _08052C54
	.align 2, 0
_08052C34: .4byte 0x03003E78
_08052C38: .4byte 0xFFFFF3FF
_08052C3C: .4byte FUN_0822e424
_08052C40: .4byte FUN_0822af38
_08052C44: .4byte FUN_0822f264
_08052C48: .4byte 0x0000270F
_08052C4C:
	cmp r0, #0
	bge _08052C54
	mov r0, sb
	strh r0, [r5, #0x28]
_08052C54:
	movs r1, #0x2a
	ldrsh r0, [r5, r1]
	ldr r1, _08052C64 @ =0x0000270F
	cmp r0, r1
	ble _08052C68
	strh r1, [r5, #0x2a]
	b _08052C70
	.align 2, 0
_08052C64: .4byte 0x0000270F
_08052C68:
	cmp r0, #0
	bge _08052C70
	movs r0, #0
	strh r0, [r5, #0x2a]
_08052C70:
	adds r7, r5, #0
	adds r7, #0xd0
	movs r0, #0x30
	adds r0, r0, r5
	mov r8, r0
	movs r4, #0
	str r4, [sp]
	movs r1, #0xa8
	str r1, [sp, #4]
	movs r0, #0x20
	mov sb, r0
	str r0, [sp, #8]
	movs r6, #8
	str r6, [sp, #0xc]
	str r4, [sp, #0x10]
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0
	movs r3, #2
	bl FUN_082376a4
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r7, r5, r1
	str r4, [sp]
	movs r0, #0xc0
	str r0, [sp, #4]
	mov r1, sb
	str r1, [sp, #8]
	str r6, [sp, #0xc]
	str r4, [sp, #0x10]
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0
	movs r3, #2
	bl FUN_082376a4
	movs r0, #0x94
	lsls r0, r0, #2
	adds r7, r5, r0
	str r4, [sp]
	movs r1, #0xd8
	str r1, [sp, #4]
	mov r0, sb
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	str r4, [sp, #0x10]
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0
	movs r3, #2
	bl FUN_082376a4
	movs r1, #0xc4
	lsls r1, r1, #2
	adds r7, r5, r1
	str r4, [sp]
	movs r0, #0xa8
	str r0, [sp, #4]
	movs r1, #0x38
	mov sl, r1
	str r1, [sp, #8]
	str r6, [sp, #0xc]
	str r4, [sp, #0x10]
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0
	movs r3, #2
	bl FUN_082376a4
	movs r0, #0xf4
	lsls r0, r0, #2
	adds r7, r5, r0
	str r4, [sp]
	movs r1, #0xc0
	str r1, [sp, #4]
	mov r0, sl
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	str r4, [sp, #0x10]
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0
	movs r3, #2
	bl FUN_082376a4
	movs r1, #0x92
	lsls r1, r1, #3
	adds r7, r5, r1
	str r4, [sp]
	movs r0, #0xd8
	str r0, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	str r6, [sp, #0xc]
	str r4, [sp, #0x10]
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0
	movs r3, #2
	bl FUN_082376a4
	movs r0, #0xaa
	lsls r0, r0, #3
	adds r7, r5, r0
	str r4, [sp]
	movs r0, #0x68
	str r0, [sp, #4]
	movs r0, #0x60
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	str r4, [sp, #0x10]
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0
	movs r3, #4
	bl FUN_082376a4
	movs r1, #0xda
	lsls r1, r1, #3
	adds r7, r5, r1
	movs r0, #0x2a
	ldrsh r2, [r5, r0]
	ldr r0, _08052D74 @ =0x0000270F
	mov r3, r8
	cmp r2, r0
	ble _08052D78
	adds r2, r0, #0
	b _08052D7E
	.align 2, 0
_08052D74: .4byte 0x0000270F
_08052D78:
	cmp r2, #0
	bge _08052D7E
	movs r2, #0
_08052D7E:
	movs r1, #0
	str r1, [sp]
	movs r0, #0x68
	str r0, [sp, #4]
	movs r0, #0x88
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	adds r0, r7, #0
	adds r1, r3, #0
	movs r3, #4
	bl FUN_082376a4
	ldr r1, _08052E8C @ =0x000008B8
	adds r4, r5, r1
	movs r0, #0xa
	movs r1, #4
	movs r2, #0xa
	movs r3, #2
	bl FUN_0804a084
	str r0, [r4]
	cmp r0, #0
	blt _08052EA4
	ldr r1, _08052E90 @ =0x000008B4
	adds r6, r5, r1
	ldr r1, [r6]
	bl FUN_0804a240
	ldr r0, [r4]
	ldr r1, _08052E94 @ =0x000008C8
	adds r2, r5, r1
	movs r1, #0
	bl FUN_0804a40c
	ldr r0, [r4]
	movs r1, #3
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	ldr r0, _08052E98 @ =0x000008BC
	adds r4, r5, r0
	movs r0, #0xa
	movs r1, #7
	movs r2, #0xa
	movs r3, #2
	bl FUN_0804a084
	str r0, [r4]
	cmp r0, #0
	blt _08052EA4
	ldr r1, [r6]
	bl FUN_0804a240
	ldr r0, [r4]
	ldr r1, _08052E9C @ =0x000008D8
	adds r2, r5, r1
	movs r1, #1
	bl FUN_0804a40c
	ldr r0, [r4]
	movs r1, #4
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	movs r0, #0x8c
	lsls r0, r0, #4
	adds r4, r5, r0
	movs r0, #1
	movs r1, #0xa
	movs r2, #0x1c
	movs r3, #2
	bl FUN_0804a084
	str r0, [r4]
	cmp r0, #0
	blt _08052EA4
	ldr r1, [r6]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #0xb
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	ldr r1, _08052EA0 @ =0x000008C4
	adds r4, r5, r1
	movs r0, #1
	movs r1, #0xf
	movs r2, #0x1c
	movs r3, #2
	bl FUN_0804a084
	str r0, [r4]
	cmp r0, #0
	blt _08052EA4
	ldr r1, [r6]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #0xc
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	movs r0, #0x85
	lsls r0, r0, #4
	adds r7, r5, r0
	ldr r0, [r7, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #8]
	adds r1, r5, #0
	adds r1, #0x50
	adds r0, r7, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_SetSprite
	movs r0, #0x18
	strh r0, [r7, #0x20]
	movs r0, #0x20
	strh r0, [r7, #0x22]
	movs r0, #0
	b _08052EA8
	.align 2, 0
_08052E8C: .4byte 0x000008B8
_08052E90: .4byte 0x000008B4
_08052E94: .4byte 0x000008C8
_08052E98: .4byte 0x000008BC
_08052E9C: .4byte 0x000008D8
_08052EA0: .4byte 0x000008C4
_08052EA4:
	movs r0, #1
	rsbs r0, r0, #0
_08052EA8:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

