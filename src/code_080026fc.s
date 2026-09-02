	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08004668
FUN_08004668: @ 0x08004668
	push {r4, lr}
	ldr r1, [r0, #0x70]
	movs r2, #0
	ldrh r0, [r0, #0x18]
	cmp r2, r0
	bge _0800468C
	movs r4, #0xce
	lsls r4, r4, #1
	adds r3, r0, #0
_0800467A:
	ldrb r0, [r1, #0x1e]
	cmp r0, #0
	bne _08004684
	adds r0, r1, #0
	b _0800468E
_08004684:
	adds r1, r1, r4
	adds r2, #1
	cmp r2, r3
	blt _0800467A
_0800468C:
	movs r0, #0
_0800468E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08004694
FUN_08004694: @ 0x08004694
	push {r4, r5, lr}
	adds r4, r1, #0
	ldr r2, [r0, #0x70]
	movs r3, #0
	ldrh r0, [r0, #0x18]
	cmp r3, r0
	bge _080046C0
	movs r5, #0xce
	lsls r5, r5, #1
	adds r1, r0, #0
_080046A8:
	ldrb r0, [r2, #0x1e]
	cmp r0, #0
	beq _080046B8
	ldrh r0, [r2, #0x2c]
	cmp r0, r4
	bne _080046B8
	adds r0, r2, #0
	b _080046C2
_080046B8:
	adds r2, r2, r5
	adds r3, #1
	cmp r3, r1
	blt _080046A8
_080046C0:
	movs r0, #0
_080046C2:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080046c8
FUN_080046c8: @ 0x080046C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	mov sl, r0
	adds r5, r1, #0
	adds r6, r2, #0
	mov sb, r3
	ldr r0, _080046F8 @ =0x03000020
	ldr r4, [r0]
	cmp r4, #0
	beq _080046F0
	adds r0, r4, #0
	bl FUN_08004668
	adds r7, r0, #0
	cmp r7, #0
	bne _080046FC
_080046F0:
	movs r0, #1
	rsbs r0, r0, #0
	b _080049F4
	.align 2, 0
_080046F8: .4byte 0x03000020
_080046FC:
	movs r1, #0xce
	lsls r1, r1, #1
	adds r0, r7, #0
	bl ClearMemory
	movs r2, #0
	movs r1, #1
	strb r1, [r7, #0x1e]
	strb r5, [r7]
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bne _08004718
	strb r1, [r4, #0x1e]
_08004718:
	strb r6, [r7, #1]
	strh r2, [r7, #2]
	strh r2, [r7, #4]
	adds r6, r7, #0
	adds r6, #0x70
	adds r0, r6, #0
	ldr r1, [sp, #0x44]
	bl Video_GetActorSprite
	adds r4, r7, #0
	adds r4, #0x8c
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_0822a470
	ldr r0, [sp, #0x48]
	strh r0, [r4, #0x10]
	movs r0, #0xa8
	adds r0, r0, r7
	mov r8, r0
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	mov r3, r8
	str r0, [r3]
	str r1, [r3, #4]
	adds r5, r7, #0
	adds r5, #0x2c
	mov r0, sl
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	movs r0, #7
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0823b400
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823b46c
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	movs r1, #0x10
	ldrb r0, [r7, #1]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r6, [sp, #0x20]
	str r5, [sp, #0x1c]
	cmp r0, #0
	beq _08004798
	subs r4, #0x58
	adds r0, r4, #0
	bl FUN_08241574
	str r0, [r7, #8]
	mov sl, r4
	b _080047A0
_08004798:
	str r0, [r7, #8]
	movs r3, #0x34
	adds r3, r3, r7
	mov sl, r3
_080047A0:
	movs r0, #0
	movs r3, #0
	strh r3, [r7, #0xc]
	strh r3, [r7, #0xe]
	strb r0, [r7, #0x10]
	movs r1, #4
	ldrb r0, [r7, #1]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _080047CC
	ldr r0, _080047C8 @ =0x080042B9
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r1, r7, r2
	str r0, [r1]
	strh r3, [r7, #2]
	b _080047D8
	.align 2, 0
_080047C8: .4byte 0x080042B9
_080047CC:
	ldr r0, _08004808 @ =FUN_08003f38
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r1, r7, r3
	str r0, [r1]
	strh r2, [r7, #2]
_080047D8:
	movs r0, #1
	strb r0, [r7, #0x11]
	ldrh r0, [r7, #0x34]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r1, sl
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08004802
	cmp r1, #0
	blt _08004802
	ldr r0, _0800480C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08004802
	ldr r0, _08004810 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08004814
_08004802:
	movs r5, #0
	b _08004822
	.align 2, 0
_08004808: .4byte FUN_08003f38
_0800480C: .4byte 0x030046A8
_08004810: .4byte 0x030046AC
_08004814:
	ldr r0, _08004834 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08004822:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08004838
	adds r0, #4
	b _08004844
	.align 2, 0
_08004834: .4byte 0x030046A4
_08004838:
	ldr r0, _08004964 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08004844:
	ldrb r0, [r0]
	movs r4, #0xf
	ands r4, r0
	cmp r4, #0xe
	bgt _08004850
	adds r4, #1
_08004850:
	adds r0, r7, #0
	adds r0, #0xb8
	movs r1, #0xff
	str r1, [sp]
	movs r2, #0
	mov sb, r2
	str r2, [sp, #4]
	adds r1, r5, #0
	adds r3, r4, #0
	bl FUN_08234270
	lsls r0, r4, #8
	movs r6, #0
	strh r0, [r7, #0x12]
	ldr r2, _08004968 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x82
	orrs r0, r3
	ldr r1, _0800496C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	mov r8, r0
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r5, sp, #0x14
	ldr r0, [r5, #4]
	ands r0, r2
	str r0, [r5, #4]
	adds r4, r7, #0
	adds r4, #0xc8
	ldrh r1, [r7, #0x2c]
	ldr r2, _08004970 @ =0x00004041
	movs r0, #0x10
	str r0, [sp]
	add r3, sp, #0xc
	str r3, [sp, #4]
	str r5, [sp, #8]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r4, #0
	mov r1, sl
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _08004974 @ =FUN_080034c8
	adds r0, r4, #0
	adds r2, r7, #0
	bl FUN_0823651c
	adds r0, r4, #0
	bl FUN_08236400
	movs r0, #0x80
	add r1, sp, #0xc
	strh r0, [r1]
	mov r1, r8
	strh r0, [r1, #2]
	strh r0, [r1, #4]
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r4, r7, r2
	ldrh r1, [r7, #0x2c]
	ldr r2, _08004978 @ =0x00002801
	movs r0, #1
	str r0, [sp]
	add r3, sp, #0xc
	str r3, [sp, #4]
	str r5, [sp, #8]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r4, #0
	mov r1, sl
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _0800497C @ =FUN_080035e0
	adds r0, r4, #0
	adds r2, r7, #0
	bl FUN_0823651c
	ldr r1, _08004980 @ =0x000005DC
	adds r0, r4, #0
	movs r2, #0x32
	bl FUN_082364f0
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r4, #0x34]
	mov r0, sb
	str r0, [r4, #0x38]
	ldr r0, [sp, #0x4c]
	strh r0, [r7, #0x16]
	strb r6, [r7, #0x18]
	strb r6, [r7, #0x19]
	strb r6, [r7, #0x1f]
	adds r0, r7, #0
	adds r0, #0x20
	strb r6, [r0]
	adds r0, #1
	strb r6, [r0]
	adds r1, r7, #0
	adds r1, #0x23
	movs r0, #4
	strb r0, [r1]
	ldr r2, _08004984 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08004988 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0800498C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x10
	bl Mod
	adds r1, r7, #0
	adds r1, #0x22
	strb r0, [r1]
	ldr r2, [sp, #0x50]
	cmp r2, #0
	blt _08004990
	strh r2, [r7, #0x1a]
	b _08004998
	.align 2, 0
_08004964: .4byte 0x030046A4
_08004968: .4byte 0xFFFF0000
_0800496C: .4byte 0x0000FFFF
_08004970: .4byte 0x00004041
_08004974: .4byte FUN_080034c8
_08004978: .4byte 0x00002801
_0800497C: .4byte FUN_080035e0
_08004980: .4byte 0x000005DC
_08004984: .4byte 0x030046B8
_08004988: .4byte 0x000003FF
_0800498C: .4byte 0x0203B400
_08004990:
	adds r0, r7, #0
	adds r0, #0x76
	ldrh r0, [r0]
	strh r0, [r7, #0x1a]
_08004998:
	ldrh r1, [r7, #0x1a]
	ldr r0, [sp, #0x20]
	bl FUN_0822b20c
	ldr r0, [sp, #0x54]
	strh r0, [r7, #0x1c]
	ldrh r1, [r7, #0x2c]
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	movs r3, #0xb6
	lsls r3, r3, #1
	adds r0, r7, r3
	mov r1, sl
	str r1, [r0]
	ldr r0, [sp, #0x58]
	str r0, [r7, #0x28]
	ldrb r1, [r7, #1]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080049D8
	ldr r0, [sp, #0x1c]
	bl FUN_08002a48
	cmp r0, #0
	bge _080049D8
	ldrb r1, [r7, #1]
	movs r0, #2
	orrs r0, r1
	strb r0, [r7, #1]
_080049D8:
	ldrb r0, [r7]
	cmp r0, #5
	bne _080049E6
	adds r0, r7, #0
	adds r0, #0x24
	movs r1, #1
	b _080049EC
_080049E6:
	adds r0, r7, #0
	adds r0, #0x24
	movs r1, #0
_080049EC:
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r0, #0
_080049F4:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08004a04
FUN_08004a04: @ 0x08004A04
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [sp, #0x20]
	movs r0, #0x74
	movs r1, #0
	bl Script_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	mov sb, r0
	movs r0, #0x4d
	bl prepare_08231510
	cmp r0, #0
	beq _08004A48
	bl Script_GetValue
	cmp r0, #0
	beq _08004A48
	movs r0, #0x10
	mov r1, sb
	orrs r1, r0
	mov sb, r1
_08004A48:
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08004A90
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08004A88 @ =0xFFFF0000
	ldr r1, [sp, #0x18]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x18]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08004A8C @ =0x0000FFFF
	ldr r1, [sp, #0x18]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x18]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x1c]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x1c]
	b _08004A9A
	.align 2, 0
_08004A88: .4byte 0xFFFF0000
_08004A8C: .4byte 0x0000FFFF
_08004A90:
	ldr r1, _08004AA8 @ =0xFFFF0000
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x1c]
	ands r0, r1
	str r0, [sp, #0x1c]
_08004A9A:
	cmp r7, #0
	beq _08004AEC
	cmp r7, #1
	bne _08004AB0
	ldr r1, _08004AAC @ =0x000084EE
	b _08004AEE
	.align 2, 0
_08004AA8: .4byte 0xFFFF0000
_08004AAC: .4byte 0x000084EE
_08004AB0:
	cmp r7, #2
	bne _08004ABC
	ldr r1, _08004AB8 @ =0x00009D40
	b _08004AEE
	.align 2, 0
_08004AB8: .4byte 0x00009D40
_08004ABC:
	cmp r7, #3
	bne _08004AC8
	ldr r1, _08004AC4 @ =0x00009D43
	b _08004AEE
	.align 2, 0
_08004AC4: .4byte 0x00009D43
_08004AC8:
	cmp r7, #4
	bne _08004AD4
	ldr r1, _08004AD0 @ =0x00002097
	b _08004AEE
	.align 2, 0
_08004AD0: .4byte 0x00002097
_08004AD4:
	cmp r7, #5
	bne _08004AE0
	ldr r1, _08004ADC @ =0x000005A2
	b _08004AEE
	.align 2, 0
_08004ADC: .4byte 0x000005A2
_08004AE0:
	cmp r7, #6
	bne _08004AEC
	ldr r1, _08004AE8 @ =0x0000B306
	b _08004AEE
	.align 2, 0
_08004AE8: .4byte 0x0000B306
_08004AEC:
	ldr r1, _08004B14 @ =0x00009D41
_08004AEE:
	movs r0, #0x61
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	mov r8, r0
	movs r0, #0x6c
	movs r1, #0x80
	bl Script_GetKeywordValue
	mov sl, r0
	cmp r7, #0
	bne _08004B1C
	ldr r5, _08004B18 @ =0x0000023D
	b _08004B6A
	.align 2, 0
_08004B14: .4byte 0x00009D41
_08004B18: .4byte 0x0000023D
_08004B1C:
	cmp r7, #1
	bne _08004B28
	ldr r5, _08004B24 @ =0x00000241
	b _08004B6A
	.align 2, 0
_08004B24: .4byte 0x00000241
_08004B28:
	cmp r7, #2
	beq _08004B38
	cmp r7, #3
	bne _08004B34
	movs r5, #0x4f
	b _08004B6A
_08004B34:
	cmp r7, #4
	bne _08004B40
_08004B38:
	ldr r5, _08004B3C @ =0x000001FD
	b _08004B6A
	.align 2, 0
_08004B3C: .4byte 0x000001FD
_08004B40:
	cmp r7, #5
	bne _08004B48
	movs r5, #0x8b
	b _08004B6A
_08004B48:
	cmp r7, #6
	bne _08004B5E
	mov r0, r8
	cmp r0, #0
	beq _08004B56
	cmp r0, #2
	bne _08004B5A
_08004B56:
	movs r5, #2
	b _08004B6A
_08004B5A:
	movs r5, #3
	b _08004B6A
_08004B5E:
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0x64
	bl Script_GetKeywordValue
	adds r5, r0, #0
_08004B6A:
	movs r4, #0x99
	lsls r4, r4, #1
	movs r0, #0x62
	movs r1, #0
	bl Script_GetKeywordValue
	str r6, [sp]
	mov r1, r8
	str r1, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	str r5, [sp, #0xc]
	str r4, [sp, #0x10]
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x20]
	adds r1, r7, #0
	mov r2, sb
	add r3, sp, #0x18
	bl FUN_080046c8
	movs r0, #0
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08004ba4
FUN_08004ba4: @ 0x08004BA4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _08004BD8 @ =0x03000020
	ldr r7, [r0]
	cmp r7, #0
	beq _08004BD2
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r0, #0
	cmp r1, #0
	beq _08004BD2
	adds r0, r7, #0
	bl FUN_08004694
	adds r5, r0, #0
	cmp r5, #0
	beq _08004BD2
	ldrb r0, [r5]
	cmp r0, #6
	beq _08004BDC
_08004BD2:
	movs r0, #1
	rsbs r0, r0, #0
	b _08004C68
	.align 2, 0
_08004BD8: .4byte 0x03000020
_08004BDC:
	adds r6, r5, #0
	adds r6, #0x8c
	movs r0, #0x73
	movs r1, #0
	bl Script_GetKeywordValue
	adds r4, r0, #0
	movs r0, #0x53
	movs r1, #1
	bl Script_GetKeywordValue
	mov r8, r0
	cmp r4, #0
	bne _08004C24
	movs r1, #0x10
	ldrsh r0, [r6, r1]
	cmp r0, #0
	beq _08004C04
	cmp r0, #2
	bne _08004C14
_08004C04:
	movs r0, #2
	strh r0, [r5, #0x1a]
	adds r0, r5, #0
	adds r0, #0x70
	movs r1, #2
	bl FUN_0822b20c
	b _08004C68
_08004C14:
	movs r0, #3
	strh r0, [r5, #0x1a]
	adds r0, r5, #0
	adds r0, #0x70
	movs r1, #3
	bl FUN_0822b20c
	b _08004C68
_08004C24:
	movs r1, #0x10
	ldrsh r0, [r6, r1]
	cmp r0, #0
	beq _08004C30
	cmp r0, #2
	bne _08004C44
_08004C30:
	movs r0, #4
	strh r0, [r5, #0x1a]
	adds r0, r5, #0
	adds r0, #0x70
	movs r1, #4
	bl FUN_0822b20c
	adds r1, r7, #0
	adds r1, #0x30
	b _08004C56
_08004C44:
	movs r0, #5
	strh r0, [r5, #0x1a]
	adds r0, r5, #0
	adds r0, #0x70
	movs r1, #5
	bl FUN_0822b20c
	adds r1, r7, #0
	adds r1, #0x50
_08004C56:
	str r1, [r5, #0x7c]
	movs r1, #1
	strb r1, [r7, #0x1f]
	mov r1, r8
	cmp r1, #0
	beq _08004C68
	ldr r0, _08004C74 @ =0x00000149
	bl PlaySound_082406e0
_08004C68:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08004C74: .4byte 0x00000149

	thumb_func_start FUN_08004c78
FUN_08004c78: @ 0x08004C78
	ldr r1, _08004C80 @ =0x03000024
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08004C80: .4byte 0x03000024

	thumb_func_start FUN_08004c84
FUN_08004c84: @ 0x08004C84
	push {lr}
	adds r1, r0, #0
	movs r0, #0
	str r0, [r1, #0x1c]
	ldr r2, _08004CA4 @ =0x03000024
	ldr r0, [r2]
	ldr r0, [r0, #0x18]
	str r0, [r1, #0x20]
	cmp r0, #0
	beq _08004C9A
	str r1, [r0, #0x1c]
_08004C9A:
	ldr r0, [r2]
	str r1, [r0, #0x18]
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08004CA4: .4byte 0x03000024

	thumb_func_start FUN_08004ca8
FUN_08004ca8: @ 0x08004CA8
	push {lr}
	ldr r2, [r0, #0x1c]
	ldr r1, [r0, #0x20]
	cmp r2, #0
	beq _08004CB6
	str r1, [r2, #0x20]
	b _08004CBC
_08004CB6:
	ldr r0, _08004CC8 @ =0x03000024
	ldr r0, [r0]
	str r1, [r0, #0x18]
_08004CBC:
	cmp r1, #0
	beq _08004CC2
	str r2, [r1, #0x1c]
_08004CC2:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08004CC8: .4byte 0x03000024

	thumb_func_start FUN_08004ccc
FUN_08004ccc: @ 0x08004CCC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	adds r4, r1, #0
	adds r7, r2, #0
	mov r8, r3
	ldr r0, _08004D04 @ =0x03000024
	ldr r0, [r0]
	cmp r0, #0
	bne _08004CF0
	ldr r0, _08004D08 @ =0x00002153
	movs r1, #0
	bl Entity08004fac_Create
	cmp r0, #0
	beq _08004D98
_08004CF0:
	movs r0, #0x24
	bl Malloc
	adds r5, r0, #0
	cmp r5, #0
	bne _08004D0C
	movs r0, #1
	rsbs r0, r0, #0
	b _08004D9A
	.align 2, 0
_08004D04: .4byte 0x03000024
_08004D08: .4byte 0x00002153
_08004D0C:
	adds r0, r5, #0
	movs r1, #0x24
	bl ClearMemory
	strh r6, [r5]
	movs r0, #1
	strb r0, [r5, #2]
	strb r7, [r5, #3]
	mov r0, r8
	strb r0, [r5, #4]
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08004D44
	cmp r1, #0
	blt _08004D44
	ldr r0, _08004D48 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08004D44
	ldr r0, _08004D4C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08004D50
_08004D44:
	movs r0, #0
	b _08004D5E
	.align 2, 0
_08004D48: .4byte 0x030046A8
_08004D4C: .4byte 0x030046AC
_08004D50:
	ldr r0, _08004D6C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_08004D5E:
	strh r0, [r5, #8]
	movs r1, #2
	ldrsh r0, [r4, r1]
	cmp r0, #0
	blt _08004D70
	asrs r0, r0, #8
	b _08004D76
	.align 2, 0
_08004D6C: .4byte 0x030046A4
_08004D70:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08004D76:
	strb r0, [r5, #5]
	ldr r0, [sp, #0x20]
	strh r0, [r5, #6]
	adds r0, r5, #0
	adds r0, #0xc
	ldrh r1, [r5, #8]
	ldrb r2, [r5, #4]
	ldrb r3, [r5, #5]
	movs r4, #0xff
	str r4, [sp]
	ldrh r4, [r5, #6]
	str r4, [sp, #4]
	bl FUN_08234270
	adds r0, r5, #0
	bl FUN_08004c84
_08004D98:
	movs r0, #0
_08004D9A:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08004da8
FUN_08004da8: @ 0x08004DA8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #2]
	cmp r0, #0
	beq _08004DBE
	adds r0, r4, #0
	adds r0, #0xc
	bl FUN_082342a8
	movs r0, #0
	strb r0, [r4, #2]
_08004DBE:
	ldr r0, _08004DDC @ =0x03000024
	ldr r0, [r0]
	cmp r0, #0
	beq _08004DCC
	adds r0, r4, #0
	bl FUN_08004ca8
_08004DCC:
	adds r0, r4, #0
	bl Free
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08004DDC: .4byte 0x03000024

	thumb_func_start FUN_08004de0
FUN_08004de0: @ 0x08004DE0
	push {r4, lr}
	ldr r0, _08004DF0 @ =0x03000024
	ldr r0, [r0]
	cmp r0, #0
	bne _08004DF4
	movs r0, #1
	rsbs r0, r0, #0
	b _08004E08
	.align 2, 0
_08004DF0: .4byte 0x03000024
_08004DF4:
	ldr r0, [r0, #0x18]
	cmp r0, #0
	beq _08004E06
_08004DFA:
	ldr r4, [r0, #0x20]
	bl FUN_08004da8
	adds r0, r4, #0
	cmp r0, #0
	bne _08004DFA
_08004E06:
	movs r0, #0
_08004E08:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08004e10
FUN_08004e10: @ 0x08004E10
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, _08004E24 @ =0x03000024
	ldr r0, [r0]
	cmp r0, #0
	bne _08004E28
	movs r0, #1
	rsbs r0, r0, #0
	b _08004E44
	.align 2, 0
_08004E24: .4byte 0x03000024
_08004E28:
	ldr r1, [r0, #0x18]
	cmp r1, #0
	beq _08004E42
_08004E2E:
	ldr r4, [r1, #0x20]
	ldrh r0, [r1]
	cmp r0, r5
	bne _08004E3C
	adds r0, r1, #0
	bl FUN_08004da8
_08004E3C:
	adds r1, r4, #0
	cmp r1, #0
	bne _08004E2E
_08004E42:
	movs r0, #0
_08004E44:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08004e4c
FUN_08004e4c: @ 0x08004E4C
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, _08004E60 @ =0x03000024
	ldr r0, [r0]
	cmp r0, #0
	bne _08004E64
	movs r0, #1
	rsbs r0, r0, #0
	b _08004E8C
	.align 2, 0
_08004E60: .4byte 0x03000024
_08004E64:
	ldr r1, [r0, #0x18]
	cmp r1, #0
	beq _08004E8A
_08004E6A:
	ldr r4, [r1, #0x20]
	ldrh r0, [r1]
	cmp r0, r5
	bne _08004E84
	ldrb r0, [r1, #2]
	cmp r0, #0
	beq _08004E84
	movs r0, #0
	strb r0, [r1, #2]
	adds r0, r1, #0
	adds r0, #0xc
	bl FUN_082342a8
_08004E84:
	adds r1, r4, #0
	cmp r1, #0
	bne _08004E6A
_08004E8A:
	movs r0, #0
_08004E8C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08004e94
FUN_08004e94: @ 0x08004E94
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r0, _08004EAC @ =0x03000024
	ldr r0, [r0]
	cmp r0, #0
	bne _08004EB0
	movs r0, #1
	rsbs r0, r0, #0
	b _08004EE6
	.align 2, 0
_08004EAC: .4byte 0x03000024
_08004EB0:
	ldr r5, [r0, #0x18]
	cmp r5, #0
	beq _08004EE4
_08004EB6:
	ldr r6, [r5, #0x20]
	ldrh r0, [r5]
	cmp r0, r7
	bne _08004EDE
	ldrb r0, [r5, #2]
	cmp r0, #0
	bne _08004EDE
	movs r0, #1
	strb r0, [r5, #2]
	adds r0, r5, #0
	adds r0, #0xc
	ldrh r1, [r5, #8]
	ldrb r2, [r5, #4]
	ldrb r3, [r5, #5]
	movs r4, #0xff
	str r4, [sp]
	ldrh r4, [r5, #6]
	str r4, [sp, #4]
	bl FUN_08234270
_08004EDE:
	adds r5, r6, #0
	cmp r5, #0
	bne _08004EB6
_08004EE4:
	movs r0, #0
_08004EE6:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08004ef0
FUN_08004ef0: @ 0x08004EF0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp, #8]
	mov sb, r1
	mov r8, r2
	adds r7, r3, #0
	ldr r0, [sp, #0x30]
	mov sl, r0
	ldr r0, _08004F18 @ =0x03000024
	ldr r0, [r0]
	cmp r0, #0
	bne _08004F1C
	movs r0, #1
	rsbs r0, r0, #0
	b _08004F74
	.align 2, 0
_08004F18: .4byte 0x03000024
_08004F1C:
	ldr r5, [r0, #0x18]
	cmp r5, #0
	beq _08004F72
_08004F22:
	ldr r6, [r5, #0x20]
	ldrh r0, [r5]
	ldr r1, [sp, #8]
	cmp r0, r1
	bne _08004F6C
	movs r0, #1
	rsbs r0, r0, #0
	cmp r8, r0
	beq _08004F38
	mov r2, r8
	strb r2, [r5, #3]
_08004F38:
	cmp sb, r0
	beq _08004F40
	mov r1, sb
	strb r1, [r5, #4]
_08004F40:
	ldr r2, [sp, #0x2c]
	cmp r2, r0
	beq _08004F48
	strh r2, [r5, #8]
_08004F48:
	cmp sl, r0
	beq _08004F50
	mov r2, sl
	strb r2, [r5, #5]
_08004F50:
	cmp r7, r0
	beq _08004F56
	strh r7, [r5, #6]
_08004F56:
	adds r0, r5, #0
	adds r0, #0xc
	ldrh r1, [r5, #8]
	ldrb r2, [r5, #4]
	ldrb r3, [r5, #5]
	movs r4, #0xff
	str r4, [sp]
	ldrh r4, [r5, #6]
	str r4, [sp, #4]
	bl FUN_08234208
_08004F6C:
	adds r5, r6, #0
	cmp r5, #0
	bne _08004F22
_08004F72:
	movs r0, #0
_08004F74:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity08004fac_Update
Entity08004fac_Update: @ 0x08004F84
	movs r0, #0
	bx lr

	thumb_func_start Entity08004fac_Destroy
Entity08004fac_Destroy: @ 0x08004F88
	push {lr}
	bl FUN_08004de0
	ldr r1, _08004F98 @ =0x03000024
	movs r0, #0
	str r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_08004F98: .4byte 0x03000024

	thumb_func_start Entity08004fac_Init
Entity08004fac_Init: @ 0x08004F9C
	ldr r1, _08004FA8 @ =0x03000024
	str r0, [r1]
	movs r1, #0
	str r1, [r0, #0x18]
	movs r0, #0
	bx lr
	.align 2, 0
_08004FA8: .4byte 0x03000024

	thumb_func_start Entity08004fac_Create
Entity08004fac_Create: @ 0x08004FAC
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #8
	movs r1, #0x1c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08004FE4
	ldr r1, _08004FDC @ =Entity08004fac_Update
	ldr r2, _08004FE0 @ =Entity08004fac_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity08004fac_Init
	cmp r0, #0
	bge _08004FE4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08004FE6
	.align 2, 0
_08004FDC: .4byte Entity08004fac_Update
_08004FE0: .4byte Entity08004fac_Destroy
_08004FE4:
	adds r0, r4, #0
_08004FE6:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start VM_Sub3E1F
VM_Sub3E1F: @ 0x08004FEC
	push {lr}
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl FUN_08004e10
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08005004
FUN_08005004: @ 0x08005004
	push {lr}
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl FUN_08004e4c
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800501c
FUN_0800501c: @ 0x0800501C
	push {lr}
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl FUN_08004e94
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08005034
FUN_08005034: @ 0x08005034
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	movs r4, #1
	rsbs r4, r4, #0
	movs r0, #0x6e
	adds r1, r4, #0
	bl Script_GetKeywordValue
	mov r8, r0
	movs r0, #0x74
	adds r1, r4, #0
	bl Script_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x66
	adds r1, r4, #0
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x65
	adds r1, r4, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0800510A
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080050D0 @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080050D4 @ =0x0000FFFF
	ldr r1, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r2, sp, #8
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	adds r0, r2, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _080050CC
	cmp r1, #0
	blt _080050CC
	ldr r0, _080050D8 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _080050CC
	ldr r0, _080050DC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080050E0
_080050CC:
	movs r2, #0
	b _080050EE
	.align 2, 0
_080050D0: .4byte 0xFFFF0000
_080050D4: .4byte 0x0000FFFF
_080050D8: .4byte 0x030046A8
_080050DC: .4byte 0x030046AC
_080050E0:
	ldr r0, _080050FC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r2, r0, r3
_080050EE:
	add r0, sp, #8
	movs r1, #2
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _08005100
	asrs r0, r0, #8
	b _08005106
	.align 2, 0
_080050FC: .4byte 0x030046A4
_08005100:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08005106:
	adds r1, r0, #0
	b _0800510E
_0800510A:
	adds r1, r4, #0
	adds r2, r1, #0
_0800510E:
	str r2, [sp]
	str r1, [sp, #4]
	mov r0, r8
	adds r1, r7, #0
	adds r2, r6, #0
	adds r3, r5, #0
	bl FUN_08004ef0
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800512c
FUN_0800512c: @ 0x0800512C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	mov r8, r0
	movs r0, #0x74
	movs r1, #0
	bl Script_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x65
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080051A4
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0800519C @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080051A0 @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	b _080051AE
	.align 2, 0
_0800519C: .4byte 0xFFFF0000
_080051A0: .4byte 0x0000FFFF
_080051A4:
	ldr r1, _080051CC @ =0xFFFF0000
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	str r0, [sp, #8]
_080051AE:
	str r5, [sp]
	mov r0, r8
	add r1, sp, #4
	adds r2, r6, #0
	adds r3, r7, #0
	bl FUN_08004ccc
	movs r0, #0
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080051CC: .4byte 0xFFFF0000

	thumb_func_start FUN_080051d0
FUN_080051d0: @ 0x080051D0
	ldr r1, _080051D8 @ =0x03000028
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080051D8: .4byte 0x03000028

	thumb_func_start FUN_080051dc
FUN_080051dc: @ 0x080051DC
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r2, r0, #0
	adds r3, r1, #0
	adds r0, #0x35
	ldrb r0, [r0]
	cmp r0, #0
	beq _08005228
	str r3, [sp]
	movs r1, #0
	add r5, sp, #0x14
	ldr r4, [r2, #0x54]
	adds r3, r2, #0
	adds r3, #0x44
	add r2, sp, #4
_080051FA:
	ldm r3!, {r0}
	stm r2!, {r0}
	adds r1, #1
	cmp r1, #3
	ble _080051FA
	ldr r0, _08005224 @ =0xFFFF0000
	ldr r1, [sp, #0x14]
	ands r1, r0
	movs r0, #5
	orrs r1, r0
	str r1, [sp, #0x14]
	mov r0, sp
	str r0, [r5, #4]
	cmp r4, #0
	beq _08005230
	adds r0, r4, #0
	adds r1, r5, #0
	bl Script_ExecById
	b _08005230
	.align 2, 0
_08005224: .4byte 0xFFFF0000
_08005228:
	ldr r1, [r2, #0x58]
	adds r0, r3, #0
	bl _call_via_r1
_08005230:
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08005238
FUN_08005238: @ 0x08005238
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	cmp r5, #0
	blt _08005278
	ldrb r0, [r4, #0x1b]
	cmp r5, r0
	blt _0800524A
	subs r5, r0, #1
_0800524A:
	lsls r0, r5, #2
	adds r0, #0x64
	adds r3, r4, r0
	movs r0, #0x86
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	ldr r2, _08005274 @ =0xFFFFFDFF
	ands r0, r2
	str r0, [r1]
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldrb r0, [r3]
	subs r0, #7
	movs r2, #0x92
	lsls r2, r2, #1
	b _080052A4
	.align 2, 0
_08005274: .4byte 0xFFFFFDFF
_08005278:
	movs r0, #0x19
	ldrsb r0, [r4, r0]
	lsls r0, r0, #2
	adds r0, #0x64
	adds r3, r4, r0
	movs r0, #0x86
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #2
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrb r0, [r3]
	subs r0, #7
	subs r2, #0xdc
_080052A4:
	adds r1, r4, r2
	strh r0, [r1]
	ldrb r0, [r3, #1]
	adds r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	ldrb r1, [r3]
	adds r1, #1
	ldrb r0, [r3, #2]
	lsls r0, r0, #3
	adds r1, r1, r0
	adds r2, #0x5e
	adds r0, r4, r2
	strh r1, [r0]
	ldrb r0, [r3, #1]
	adds r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	movs r0, #0x18
	ldrsb r0, [r4, r0]
	cmp r5, r0
	beq _080052D6
	movs r0, #0xdc
	bl PlaySound_082406e0
_080052D6:
	strb r5, [r4, #0x18]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080052e0
FUN_080052e0: @ 0x080052E0
	push {r4, r5, r6, lr}
	mov ip, r0
	adds r5, r1, #0
	adds r4, r2, #0
	adds r3, r5, #0
	movs r1, #0
	adds r0, #0x34
	ldrb r2, [r0]
	cmp r1, r2
	bge _08005322
	mov r2, ip
	adds r2, #0x2c
_080052F8:
	adds r3, r3, r4
	ldrb r0, [r0]
	cmp r3, r0
	ble _08005304
	adds r3, r0, #0
	b _0800530A
_08005304:
	cmp r3, #0
	bge _0800530A
	movs r3, #0
_0800530A:
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08005316
	adds r0, r3, #0
	b _08005324
_08005316:
	adds r1, #1
	mov r0, ip
	adds r0, #0x34
	ldrb r6, [r0]
	cmp r1, r6
	blt _080052F8
_08005322:
	adds r0, r5, #0
_08005324:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800532c
FUN_0800532c: @ 0x0800532C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r0, #0x86
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r0, #0x18
	ldrsb r0, [r5, r0]
	cmp r0, #0
	bge _08005394
	ldr r0, _0800538C @ =0x030044E0
	ldrh r2, [r0, #2]
	movs r0, #0xf0
	ands r0, r2
	cmp r0, #0
	bne _08005378
	adds r1, r5, #0
	adds r1, #0x3d
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800539E
	movs r0, #3
	ands r0, r2
	cmp r0, #0
	bne _08005378
	b _08005522
_08005378:
	movs r1, #0x19
	ldrsb r1, [r5, r1]
	adds r0, r5, #0
	bl FUN_08005238
	ldr r0, _08005390 @ =0x00000107
	bl PlaySound_082406e0
	b _08005522
	.align 2, 0
_0800538C: .4byte 0x030044E0
_08005390: .4byte 0x00000107
_08005394:
	adds r1, r5, #0
	adds r1, #0x3d
	ldrb r0, [r1]
	cmp r0, #0
	beq _080053A4
_0800539E:
	subs r0, #1
	strb r0, [r1]
	b _08005522
_080053A4:
	ldr r0, _080053C4 @ =0x030044E0
	ldrh r0, [r0]
	ldr r1, [r5, #0x40]
	ands r1, r0
	cmp r1, #0
	beq _080053C8
	adds r0, r5, #0
	adds r0, #0x3e
	ldrb r1, [r0]
	mov r8, r0
	cmp r1, #0
	beq _080053D0
	subs r0, r1, #1
	mov r1, r8
	strb r0, [r1]
	b _080053D0
	.align 2, 0
_080053C4: .4byte 0x030044E0
_080053C8:
	adds r0, r5, #0
	adds r0, #0x3e
	strb r1, [r0]
	mov r8, r0
_080053D0:
	ldr r0, _08005408 @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	str r0, [r5, #0x40]
	mov r2, r8
	ldrb r0, [r2]
	cmp r0, #0
	bne _080054C8
	movs r2, #0x18
	ldrsb r2, [r5, r2]
	lsls r0, r2, #2
	adds r0, #0x64
	adds r7, r5, r0
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0800540C
	subs r1, r2, #1
	adds r0, r5, #0
	adds r0, #0x1c
	ldrb r7, [r7, #3]
	adds r0, r0, r7
	ldrb r0, [r0]
	cmp r1, r0
	bge _08005468
	b _08005466
	.align 2, 0
_08005408: .4byte 0x030044E0
_0800540C:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08005420
	adds r1, r2, #1
	adds r0, r5, #0
	adds r0, #0x24
	ldrb r7, [r7, #3]
	adds r0, r0, r7
	b _080054B4
_08005420:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08005476
	ldrb r1, [r7, #3]
	adds r4, r5, #0
	adds r4, #0x1c
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r6, r2, r0
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r5, #0
	bl FUN_080052e0
	adds r2, r0, #0
	ldrb r0, [r7, #3]
	cmp r0, r2
	bne _0800544C
	movs r1, #0x18
	ldrsb r1, [r5, r1]
	b _08005452
_0800544C:
	adds r0, r4, r2
	ldrb r0, [r0]
	adds r1, r0, r6
_08005452:
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r1, r0
	blt _08005466
	adds r0, r5, #0
	adds r0, #0x24
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r1, r0
	ble _08005468
_08005466:
	adds r1, r0, #0
_08005468:
	adds r0, r5, #0
	bl FUN_08005238
	movs r0, #0x1e
	mov r1, r8
	strb r0, [r1]
	b _080054C8
_08005476:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080054C8
	ldrb r1, [r7, #3]
	adds r4, r5, #0
	adds r4, #0x1c
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r6, r2, r0
	adds r0, r5, #0
	movs r2, #1
	bl FUN_080052e0
	adds r2, r0, #0
	ldrb r0, [r7, #3]
	cmp r0, r2
	bne _080054A0
	movs r1, #0x18
	ldrsb r1, [r5, r1]
	b _080054A6
_080054A0:
	adds r0, r4, r2
	ldrb r0, [r0]
	adds r1, r0, r6
_080054A6:
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r1, r0
	blt _080054BA
	adds r0, r5, #0
	adds r0, #0x24
	adds r0, r0, r2
_080054B4:
	ldrb r0, [r0]
	cmp r1, r0
	ble _080054BC
_080054BA:
	adds r1, r0, #0
_080054BC:
	adds r0, r5, #0
	bl FUN_08005238
	movs r0, #0x1e
	mov r2, r8
	strb r0, [r2]
_080054C8:
	ldr r0, _080054FC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08005500
	adds r0, r5, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #0
	beq _08005522
	movs r0, #0xde
	bl PlaySound_082406e0
	bl FUN_08047864
	movs r1, #1
	rsbs r1, r1, #0
	adds r0, r5, #0
	bl FUN_080051dc
	adds r0, r5, #0
	bl KillEntity
	b _08005522
	.align 2, 0
_080054FC: .4byte 0x030044E0
_08005500:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08005522
	movs r0, #0xdd
	bl PlaySound_082406e0
	bl FUN_08047864
	movs r1, #0x18
	ldrsb r1, [r5, r1]
	adds r0, r5, #0
	bl FUN_080051dc
	adds r0, r5, #0
	bl KillEntity
_08005522:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0800552c
FUN_0800552c: @ 0x0800552C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	beq _0800556C
	bl FUN_08048914
	cmp r0, #0
	beq _0800556C
	ldrb r0, [r5, #0x1a]
	cmp r0, #0
	bne _0800554C
	adds r0, r5, #0
	bl FUN_0800532c
	b _08005550
_0800554C:
	subs r0, #1
	strb r0, [r5, #0x1a]
_08005550:
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0xe4
	adds r1, r4, #0
	bl FUN_082372cc
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r4, #0
	bl FUN_082372cc
_0800556C:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08005574
FUN_08005574: @ 0x08005574
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_0822f1c0
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_0822f1c0
	ldr r1, _08005598 @ =0x03000028
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08005598: .4byte 0x03000028

	thumb_func_start FUN_0800559c
FUN_0800559c: @ 0x0800559C
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x36
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x37
	ldrb r1, [r1]
	adds r2, r4, #0
	adds r2, #0x38
	ldrb r2, [r2]
	adds r3, r4, #0
	adds r3, #0x39
	ldrb r3, [r3]
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	ldr r0, [r4, #0x5c]
	bl FUN_080478f0
	ldr r0, [r4, #0x60]
	bl FUN_08047a28
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080055d4
FUN_080055d4: @ 0x080055D4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r4, #0
	ldrb r0, [r4]
	cmp r0, #0x2f
	bne _080055EE
	b _080057E2
_080055EE:
	ldr r1, _08005638 @ =0x08251B3C
	adds r0, r4, #0
	movs r2, #5
	bl FUN_08048bf4
	cmp r0, #0
	bne _080056D0
	movs r0, #0
	mov ip, r0
	movs r3, #0
	ldrb r0, [r4]
	adds r2, r6, #0
	adds r2, #0xa4
	movs r1, #0x3f
	adds r1, r1, r6
	mov sb, r1
	adds r1, r6, #0
	adds r1, #0x36
	str r1, [sp]
	movs r1, #0x3b
	adds r1, r1, r6
	mov r8, r1
	adds r1, r6, #0
	adds r1, #0x37
	str r1, [sp, #4]
	movs r1, #0x34
	adds r1, r1, r6
	mov sl, r1
	adds r7, r6, #0
	adds r7, #0x3a
	cmp r0, #0x3e
	beq _08005662
	cmp r0, #0
	bne _0800563C
	adds r5, r4, #1
	b _08005662
	.align 2, 0
_08005638: .4byte 0x08251B3C
_0800563C:
	ldrb r1, [r5]
	cmp r1, #0x3d
	bne _08005648
	movs r4, #1
	mov ip, r4
	b _08005654
_08005648:
	mov r0, ip
	cmp r0, #0
	beq _08005654
	adds r0, r2, r3
	strb r1, [r0]
	adds r3, #1
_08005654:
	adds r5, #1
	ldrb r0, [r5]
	cmp r0, #0x3e
	beq _08005662
	cmp r0, #0
	bne _0800563C
	adds r5, #1
_08005662:
	adds r1, r2, r3
	movs r0, #0
	strb r0, [r1]
	mov r1, ip
	cmp r1, #0
	beq _08005680
	cmp r3, #0
	beq _08005680
	adds r0, r2, #0
	adds r1, r3, #0
	bl FUN_08048c2c
	mov r2, sb
	strb r0, [r2]
	b _08005686
_08005680:
	movs r0, #0
	mov r3, sb
	strb r0, [r3]
_08005686:
	adds r0, r5, #0
	movs r1, #0x3e
	bl FUN_08048cc8
	adds r5, r0, #0
	ldrb r0, [r6, #0x1b]
	lsls r0, r0, #2
	adds r0, r6, r0
	mov r4, r8
	ldrb r1, [r4]
	ldr r2, [sp]
	ldrb r2, [r2]
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r0, #0x64
	movs r3, #0
	strb r1, [r0]
	ldrb r1, [r6, #0x1b]
	lsls r1, r1, #2
	adds r1, r6, r1
	ldr r4, [sp, #4]
	ldrb r2, [r4]
	lsls r2, r2, #3
	mov r4, sl
	ldrb r0, [r4]
	lsls r0, r0, #4
	adds r2, r2, r0
	adds r1, #0x65
	strb r2, [r1]
	ldrb r0, [r6, #0x1b]
	lsls r0, r0, #2
	adds r0, r6, r0
	ldrb r1, [r4]
	adds r0, #0x67
	strb r1, [r0]
	strb r3, [r7]
	b _08005854
_080056D0:
	ldr r1, _08005700 @ =0x08251B44
	adds r0, r4, #0
	movs r2, #6
	bl FUN_08048bf4
	cmp r0, #0
	bne _0800574C
	movs r0, #0
	mov ip, r0
	movs r3, #0
	ldrb r0, [r4]
	adds r2, r6, #0
	adds r2, #0xa4
	movs r1, #0x3b
	adds r1, r1, r6
	mov r8, r1
	adds r7, r6, #0
	adds r7, #0x3a
	cmp r0, #0x3e
	beq _0800572A
	cmp r0, #0
	bne _08005704
	adds r5, r4, #1
	b _0800572A
	.align 2, 0
_08005700: .4byte 0x08251B44
_08005704:
	ldrb r1, [r5]
	cmp r1, #0x3d
	bne _08005710
	movs r4, #1
	mov ip, r4
	b _0800571C
_08005710:
	mov r0, ip
	cmp r0, #0
	beq _0800571C
	adds r0, r2, r3
	strb r1, [r0]
	adds r3, #1
_0800571C:
	adds r5, #1
	ldrb r0, [r5]
	cmp r0, #0x3e
	beq _0800572A
	cmp r0, #0
	bne _08005704
	adds r5, #1
_0800572A:
	adds r1, r2, r3
	movs r0, #0
	strb r0, [r1]
	mov r1, ip
	cmp r1, #0
	beq _08005744
	cmp r3, #0
	beq _08005744
	adds r0, r2, #0
	adds r1, r3, #0
	bl FUN_08048c2c
	b _08005746
_08005744:
	movs r0, #0
_08005746:
	bl FUN_080488bc
	b _080057C6
_0800574C:
	ldr r1, _0800577C @ =0x08251B4C
	adds r0, r4, #0
	movs r2, #3
	bl FUN_08048bf4
	cmp r0, #0
	bne _08005848
	movs r3, #0
	mov ip, r3
	ldrb r0, [r4]
	adds r2, r6, #0
	adds r2, #0xa4
	movs r1, #0x3b
	adds r1, r1, r6
	mov r8, r1
	adds r7, r6, #0
	adds r7, #0x3a
	cmp r0, #0x3e
	beq _080057A6
	cmp r0, #0
	bne _08005780
	adds r5, r4, #1
	b _080057A6
	.align 2, 0
_0800577C: .4byte 0x08251B4C
_08005780:
	ldrb r1, [r5]
	cmp r1, #0x3d
	bne _0800578C
	movs r4, #1
	mov ip, r4
	b _08005798
_0800578C:
	mov r0, ip
	cmp r0, #0
	beq _08005798
	adds r0, r2, r3
	strb r1, [r0]
	adds r3, #1
_08005798:
	adds r5, #1
	ldrb r0, [r5]
	cmp r0, #0x3e
	beq _080057A6
	cmp r0, #0
	bne _08005780
	adds r5, #1
_080057A6:
	adds r1, r2, r3
	movs r0, #0
	strb r0, [r1]
	mov r1, ip
	cmp r1, #0
	beq _080057C0
	cmp r3, #0
	beq _080057C0
	adds r0, r2, #0
	adds r1, r3, #0
	bl FUN_08048c2c
	b _080057C2
_080057C0:
	movs r0, #0
_080057C2:
	bl FUN_0804889c
_080057C6:
	adds r1, r0, #0
	ldrb r0, [r7]
	adds r0, r0, r1
	strb r0, [r7]
	mov r2, r8
	ldrb r0, [r2]
	adds r0, r0, r1
	strb r0, [r2]
	adds r0, r5, #0
	movs r1, #0x3e
	bl FUN_08048cc8
	adds r5, r0, #0
	b _08005854
_080057E2:
	ldr r1, _08005814 @ =0x08251B50
	adds r0, r4, #0
	movs r2, #6
	bl FUN_08048bf4
	cmp r0, #0
	bne _08005848
	adds r0, r4, #0
	movs r1, #0x3e
	bl FUN_08048cc8
	adds r5, r0, #0
	adds r0, r6, #0
	adds r0, #0x3f
	ldrb r1, [r0]
	cmp r1, #0
	beq _08005818
	ldrb r0, [r6, #0x1b]
	lsls r0, r0, #2
	adds r0, r6, r0
	adds r0, #0x66
	strb r1, [r0]
	adds r7, r6, #0
	adds r7, #0x3a
	b _0800582A
	.align 2, 0
_08005814: .4byte 0x08251B50
_08005818:
	ldrb r0, [r6, #0x1b]
	lsls r0, r0, #2
	adds r0, r6, r0
	adds r2, r6, #0
	adds r2, #0x3a
	ldrb r1, [r2]
	adds r0, #0x66
	strb r1, [r0]
	adds r7, r2, #0
_0800582A:
	ldrb r0, [r6, #0x1b]
	adds r0, #1
	movs r1, #0
	strb r0, [r6, #0x1b]
	strb r1, [r7]
	adds r0, r6, #0
	adds r0, #0x34
	adds r1, r6, #0
	adds r1, #0x2c
	ldrb r0, [r0]
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08005854
_08005848:
	adds r0, r4, #0
	movs r1, #0x3e
	bl FUN_08048cc8
	adds r4, r0, #0
	b _08005858
_08005854:
	adds r4, r5, #1
	adds r0, r4, #0
_08005858:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08005868
FUN_08005868: @ 0x08005868
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r0, r1, #0
	bl VM_ParseStringRef
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	bl Textbox_LookupString
	adds r2, r0, #0
	movs r0, #0
	strb r0, [r4, #0x1b]
	adds r1, r4, #0
	adds r1, #0x3a
	strb r0, [r1]
	movs r3, #0
	adds r7, r4, #0
	adds r7, #0x1c
	movs r0, #0x24
	adds r0, r0, r4
	mov r8, r0
	adds r0, r7, #0
	movs r1, #7
_0800589A:
	strb r3, [r0]
	strb r3, [r0, #8]
	strb r3, [r0, #0x10]
	adds r0, #1
	subs r1, #1
	cmp r1, #0
	bge _0800589A
	adds r0, r4, #0
	adds r0, #0x34
	movs r1, #0
	strb r1, [r0]
	ldrb r1, [r2]
	lsls r1, r1, #0x18
	adds r5, r0, #0
	adds r6, r4, #0
	adds r6, #0x39
	cmp r1, #0
	blt _08005984
	lsrs r1, r1, #0x18
	cmp r1, #0
	beq _080059B2
	cmp r1, #0x3c
	bne _080058DC
	b _080059AA
_080058CA:
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_080055d4
	adds r2, r0, #0
	ldrb r0, [r2]
	cmp r0, #0
	beq _080059B2
	b _08005998
_080058DC:
	ldrb r0, [r2]
	cmp r0, #0xa
	bne _08005922
	adds r1, r4, #0
	adds r1, #0x3b
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	ldrb r0, [r5]
	ldrb r1, [r6]
	cmp r0, r1
	bhs _08005980
	mov r3, r8
	adds r1, r3, r0
	ldrb r0, [r4, #0x1b]
	cmp r0, #0
	beq _08005904
	subs r0, #1
	b _08005906
_08005904:
	movs r0, #0
_08005906:
	strb r0, [r1]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r6]
	cmp r0, r1
	bhs _08005980
	ldrb r0, [r5]
	adds r0, r7, r0
	ldrb r1, [r4, #0x1b]
	strb r1, [r0]
	b _08005980
_08005922:
	cmp r0, #0x1f
	bne _0800596E
	adds r0, r2, #0
	bl FUN_08048afc
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _0800594C @ =0x0000FFFF
	cmp r1, r0
	bne _08005950
_08005936:
	adds r1, r4, #0
	adds r1, #0x3a
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	adds r1, #1
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	b _080059B2
	.align 2, 0
_0800594C: .4byte 0x0000FFFF
_08005950:
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08005936
	adds r1, r4, #0
	adds r1, #0x3a
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	adds r1, #1
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _080059B2
_0800596E:
	adds r1, r4, #0
	adds r1, #0x3a
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	adds r1, #1
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08005980:
	adds r2, #1
	b _08005998
_08005984:
	adds r1, r4, #0
	adds r1, #0x3a
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	adds r1, #1
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	adds r2, #2
_08005998:
	ldrb r0, [r2]
	lsls r0, r0, #0x18
	cmp r0, #0
	blt _08005984
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _080059B2
	cmp r0, #0x3c
	bne _080058DC
_080059AA:
	adds r2, #1
	ldrb r0, [r2]
	cmp r0, #0
	bne _080058CA
_080059B2:
	ldrb r0, [r5]
	ldrb r6, [r6]
	cmp r0, r6
	bhs _080059CC
	mov r3, r8
	adds r2, r3, r0
	ldrb r0, [r4, #0x1b]
	cmp r0, #0
	beq _080059C8
	subs r1, r0, #1
	b _080059CA
_080059C8:
	movs r1, #0
_080059CA:
	strb r1, [r2]
_080059CC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080059d8
FUN_080059d8: @ 0x080059D8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	mov r8, r1
	mov sb, r2
	adds r5, r3, #0
	ldr r0, _08005A04 @ =0x03000028
	str r7, [r0]
	ldr r0, _08005A08 @ =0x0000CB05
	ldr r1, _08005A0C @ =0x0000B343
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _08005A10
	movs r0, #1
	rsbs r0, r0, #0
	b _08005B34
	.align 2, 0
_08005A04: .4byte 0x03000028
_08005A08: .4byte 0x0000CB05
_08005A0C: .4byte 0x0000B343
_08005A10:
	adds r0, r7, #0
	adds r0, #0xe4
	str r0, [sp, #0x18]
	adds r1, r0, #0
	adds r0, r2, #0
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	ldr r0, [sp, #0x18]
	adds r1, r2, #0
	bl OpenSpriteSetFile
	mov r6, r8
	str r6, [r7, #0x5c]
	mov r0, sb
	str r0, [r7, #0x60]
	ldr r0, [r5, #4]
	ldr r1, [sp, #0x18]
	mov sb, r1
	cmp r0, #0
	beq _08005A48
	movs r0, #0xff
	strb r0, [r7, #0x18]
	ldr r0, [r5]
	b _08005A4C
_08005A48:
	ldr r0, [r5]
	strb r0, [r7, #0x18]
_08005A4C:
	cmp r0, #0
	bge _08005A52
	movs r0, #0
_08005A52:
	strb r0, [r7, #0x19]
	ldr r1, [r5, #8]
	adds r0, r7, #0
	adds r0, #0x3c
	strb r1, [r0]
	adds r1, r7, #0
	adds r1, #0x3d
	movs r0, #0xa
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x3e
	movs r3, #0
	strb r3, [r0]
	ldr r0, _08005B44 @ =0x030044E0
	ldrh r0, [r0]
	str r0, [r7, #0x40]
	ldr r0, [r5, #0xc]
	subs r1, #7
	strb r0, [r1]
	ldr r0, [r5, #0x10]
	adds r1, #1
	strb r0, [r1]
	ldr r1, [r5, #0x14]
	adds r0, r7, #0
	adds r0, #0x38
	strb r1, [r0]
	ldr r0, [r5, #0x18]
	adds r1, r7, #0
	adds r1, #0x39
	strb r0, [r1]
	movs r0, #2
	strb r0, [r7, #0x1a]
	ldr r2, _08005B48 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #1
	orrs r0, r1
	ldr r1, _08005B4C @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	str r0, [sp, #0x14]
	movs r4, #0x82
	lsls r4, r4, #1
	adds r4, r4, r7
	mov r8, r4
	movs r6, #0
	str r6, [sp]
	str r6, [sp, #4]
	movs r5, #0x3c
	str r5, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	mov r0, r8
	mov r1, sb
	movs r2, #0x8b
	movs r3, #0x11
	bl FUN_0822f3fc
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r6, r7, r1
	movs r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	str r5, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	adds r0, r6, #0
	mov r1, sb
	movs r2, #0x8f
	movs r3, #0x11
	bl FUN_0822f3fc
	movs r0, #0
	str r0, [sp]
	mov r0, r8
	mov r1, sb
	movs r2, #6
	movs r3, #1
	bl FUN_082370cc
	movs r1, #0
	str r1, [sp]
	adds r0, r6, #0
	mov r1, sb
	movs r2, #7
	movs r3, #1
	bl FUN_082370cc
	ldr r1, [r7, #0x5c]
	cmp r1, #0
	beq _08005B24
	adds r0, r7, #0
	bl FUN_08005868
	movs r1, #0x18
	ldrsb r1, [r7, r1]
	adds r0, r7, #0
	bl FUN_08005238
	adds r0, r7, #0
	bl FUN_0800559c
_08005B24:
	bl FUN_080488fc
	cmp r0, #0
	bne _08005B32
	ldr r0, _08005B50 @ =0x00000107
	bl PlaySound_082406e0
_08005B32:
	movs r0, #0
_08005B34:
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08005B44: .4byte 0x030044E0
_08005B48: .4byte 0xFFFF0000
_08005B4C: .4byte 0x0000FFFF
_08005B50: .4byte 0x00000107

	thumb_func_start FUN_08005b54
FUN_08005b54: @ 0x08005B54
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	mov sb, r1
	adds r6, r2, #0
	adds r7, r3, #0
	ldr r0, _08005B70 @ =0x03000028
	ldr r5, [r0]
	cmp r5, #0
	beq _08005B74
	movs r0, #0
	b _08005BBA
	.align 2, 0
_08005B70: .4byte 0x03000028
_08005B74:
	movs r1, #0xe2
	lsls r1, r1, #1
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08005BB8
	ldr r1, _08005BB0 @ =FUN_0800552c
	ldr r2, _08005BB4 @ =FUN_08005574
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r0, #0x35
	strb r5, [r0]
	str r6, [r4, #0x58]
	adds r0, r4, #0
	mov r1, r8
	mov r2, sb
	adds r3, r7, #0
	bl FUN_080059d8
	cmp r0, #0
	bge _08005BB8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08005BBA
	.align 2, 0
_08005BB0: .4byte FUN_0800552c
_08005BB4: .4byte FUN_08005574
_08005BB8:
	adds r0, r4, #0
_08005BBA:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08005bc8
FUN_08005bc8: @ 0x08005BC8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x3c
	ldr r0, _08005BDC @ =0x03000028
	ldr r0, [r0]
	cmp r0, #0
	beq _08005BE0
	movs r0, #0
	b _08005D0E
	.align 2, 0
_08005BDC: .4byte 0x03000028
_08005BE0:
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _08005BF2
	bl FUN_0823d340
	adds r6, r0, #0
	b _08005BF4
_08005BF2:
	movs r6, #0
_08005BF4:
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0
	mov r8, r0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08005C12
	bl Script_GetValue
	mov r8, r0
_08005C12:
	movs r0, #0x6c
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [sp, #4]
	movs r0, #0x77
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [sp]
	movs r0, #0x63
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [sp, #8]
	movs r0, #0x61
	bl prepare_08231510
	adds r5, r0, #0
	cmp r5, #0
	beq _08005C54
	bl Script_GetValue
	str r0, [sp, #0xc]
	bl Script_GetValue
	str r0, [sp, #0x10]
	bl Script_GetValue
	str r0, [sp, #0x14]
	bl Script_GetValue
	b _08005C7A
_08005C54:
	add r4, sp, #0x2c
	adds r0, r4, #0
	bl FUN_08048870
	cmp r0, #0
	bne _08005C70
	ldr r0, [sp, #0x2c]
	str r0, [sp, #0xc]
	ldr r0, [r4, #4]
	str r0, [sp, #0x10]
	ldr r0, [r4, #8]
	str r0, [sp, #0x14]
	ldr r0, [r4, #0xc]
	b _08005C7A
_08005C70:
	str r5, [sp, #0xc]
	str r5, [sp, #0x10]
	movs r0, #0x18
	str r0, [sp, #0x14]
	movs r0, #3
_08005C7A:
	str r0, [sp, #0x18]
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _08005CA4
	add r5, sp, #0x1c
	adds r4, r5, #0
_08005C8A:
	bl VM_GetPC
	cmp r0, #0
	beq _08005C96
	bl Script_GetValue
_08005C96:
	str r0, [r4]
	adds r4, #4
	adds r0, r5, #0
	adds r0, #0xc
	cmp r4, r0
	ble _08005C8A
	b _08005CB4
_08005CA4:
	add r5, sp, #0x1c
	adds r1, r5, #0
	movs r2, #0
	add r0, sp, #0x28
_08005CAC:
	str r2, [r0]
	subs r0, #4
	cmp r0, r1
	bge _08005CAC
_08005CB4:
	movs r1, #0xe2
	lsls r1, r1, #1
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08005D0C
	ldr r1, _08005D04 @ =FUN_0800552c
	ldr r2, _08005D08 @ =FUN_08005574
	bl SetEntityRoutine
	adds r1, r4, #0
	adds r1, #0x35
	movs r0, #1
	strb r0, [r1]
	mov r0, r8
	str r0, [r4, #0x54]
	adds r3, r5, #0
	adds r2, r4, #0
	adds r2, #0x44
	movs r1, #3
_08005CE0:
	ldm r3!, {r0}
	stm r2!, {r0}
	subs r1, #1
	cmp r1, #0
	bge _08005CE0
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, sp
	bl FUN_080059d8
	cmp r0, #0
	bge _08005D0C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08005D0E
	.align 2, 0
_08005D04: .4byte FUN_0800552c
_08005D08: .4byte FUN_08005574
_08005D0C:
	adds r0, r4, #0
_08005D0E:
	add sp, #0x3c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08005d1c
FUN_08005d1c: @ 0x08005D1C
	push {r4, lr}
	ldr r0, _08005D74 @ =0x03000028
	ldr r4, [r0]
	cmp r4, #0
	beq _08005D6C
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _08005D6C
	bl FUN_0823d340
	str r0, [r4, #0x5c]
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [r4, #0x60]
	movs r0, #0x77
	bl prepare_08231510
	cmp r0, #0
	beq _08005D50
	bl Script_GetValue
	strb r0, [r4, #0x18]
_08005D50:
	ldr r1, [r4, #0x5c]
	cmp r1, #0
	beq _08005D6C
	adds r0, r4, #0
	bl FUN_08005868
	movs r1, #0x18
	ldrsb r1, [r4, r1]
	adds r0, r4, #0
	bl FUN_08005238
	adds r0, r4, #0
	bl FUN_0800559c
_08005D6C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08005D74: .4byte 0x03000028

	thumb_func_start FUN_08005d78
FUN_08005d78: @ 0x08005D78
	ldr r1, _08005D80 @ =0x0300002C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08005D80: .4byte 0x0300002C

	thumb_func_start FUN_08005d84
FUN_08005d84: @ 0x08005D84
	push {r4, r5, r6, r7, lr}
	sub sp, #0x30
	adds r4, r0, #0
	adds r7, r2, #0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	cmp r6, #0
	beq _08005DB4
	movs r1, #4
	ldrsb r1, [r4, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08005DB4
	adds r2, r1, #0
	movs r3, #0xc
	ldr r1, _08005DBC @ =0x03002BC0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ands r0, r3
	adds r5, r2, #0
	cmp r0, #0
	beq _08005DC0
_08005DB4:
	movs r0, #1
	rsbs r0, r0, #0
	b _08005E24
	.align 2, 0
_08005DBC: .4byte 0x03002BC0
_08005DC0:
	ldrb r0, [r4, #5]
	cmp r0, #1
	bne _08005DD6
	ldr r1, [r4, #0x2c]
	movs r2, #0
	ldrsh r0, [r1, r2]
	str r0, [sp]
	movs r2, #2
	ldrsh r0, [r1, r2]
	adds r0, #0x40
	b _08005DE2
_08005DD6:
	ldr r1, [r4, #0x2c]
	movs r2, #0
	ldrsh r0, [r1, r2]
	str r0, [sp]
	movs r2, #2
	ldrsh r0, [r1, r2]
_08005DE2:
	str r0, [sp, #4]
	movs r2, #4
	ldrsh r0, [r1, r2]
	str r0, [sp, #8]
	movs r1, #0
	ldrsh r0, [r4, r1]
	str r0, [sp, #0xc]
	movs r2, #2
	ldrsh r0, [r4, r2]
	str r0, [sp, #0x10]
	add r2, sp, #0x28
	adds r4, #0x38
	add r3, sp, #0x14
	movs r1, #2
_08005DFE:
	ldm r4!, {r0}
	stm r3!, {r0}
	subs r1, #1
	cmp r1, #0
	bge _08005DFE
	str r5, [sp, #0x20]
	str r7, [sp, #0x24]
	ldr r1, _08005E2C @ =0xFFFF0000
	ldr r0, [sp, #0x28]
	ands r0, r1
	movs r1, #0xa
	orrs r0, r1
	str r0, [sp, #0x28]
	mov r0, sp
	str r0, [r2, #4]
	adds r0, r6, #0
	adds r1, r2, #0
	bl Script_ExecById
_08005E24:
	add sp, #0x30
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08005E2C: .4byte 0xFFFF0000

	thumb_func_start FUN_08005e30
FUN_08005e30: @ 0x08005E30
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0xb4
	movs r0, #0
	str r0, [r1]
	adds r1, #4
	ldr r3, _08005E58 @ =0x0300002C
	ldr r0, [r3]
	ldr r0, [r0, #0x28]
	str r0, [r1]
	cmp r0, #0
	beq _08005E4E
	adds r0, #0xb4
	str r2, [r0]
_08005E4E:
	ldr r0, [r3]
	str r2, [r0, #0x28]
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08005E58: .4byte 0x0300002C

	thumb_func_start FUN_08005e5c
FUN_08005e5c: @ 0x08005E5C
	push {lr}
	adds r1, r0, #0
	adds r1, #0xb4
	ldr r1, [r1]
	adds r0, #0xb8
	ldr r2, [r0]
	cmp r1, #0
	beq _08005E74
	adds r0, r1, #0
	adds r0, #0xb8
	str r2, [r0]
	b _08005E7A
_08005E74:
	ldr r0, _08005E8C @ =0x0300002C
	ldr r0, [r0]
	str r2, [r0, #0x28]
_08005E7A:
	cmp r2, #0
	beq _08005E84
	adds r0, r2, #0
	adds r0, #0xb4
	str r1, [r0]
_08005E84:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08005E8C: .4byte 0x0300002C

	thumb_func_start FUN_08005e90
FUN_08005e90: @ 0x08005E90
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08005e5c
	adds r0, r4, #0
	adds r0, #0x48
	bl FUN_08013c70
	ldr r0, [r4, #0x24]
	cmp r0, #0
	beq _08005EAA
	bl Free
_08005EAA:
	ldr r0, [r4, #0x28]
	cmp r0, #0
	beq _08005EB4
	bl Free
_08005EB4:
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _08005EC4
	bl FUN_0822dabc
	ldr r0, [r4, #0x1c]
	bl Free
_08005EC4:
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _08005ED4
	bl FUN_0822a4e0
	ldr r0, [r4, #0x20]
	bl Free
_08005ED4:
	adds r0, r4, #0
	bl Free
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08005ee4
FUN_08005ee4: @ 0x08005EE4
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r0, [r7, #0xf]
	cmp r0, #0
	beq _08005F42
	subs r0, #1
	strb r0, [r7, #0xf]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08005F06
	ldr r1, [r7, #0x2c]
	ldrh r0, [r7, #0x10]
	strh r0, [r1]
	ldr r1, [r7, #0x2c]
	ldrh r0, [r7, #0x12]
	strh r0, [r1, #4]
	b _08005F42
_08005F06:
	ldr r6, _08005F48 @ =0x0203B400
	ldr r3, _08005F4C @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r5, _08005F50 @ =0x000003FF
	ands r1, r5
	str r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ldr r4, [r7, #0x2c]
	movs r2, #0xf
	ands r0, r2
	ldrh r2, [r7, #0x10]
	adds r0, r0, r2
	subs r0, #4
	strh r0, [r4]
	adds r1, #1
	ands r1, r5
	str r1, [r3]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	ldr r2, [r7, #0x2c]
	movs r1, #7
	ands r0, r1
	ldrh r7, [r7, #0x12]
	adds r0, r0, r7
	subs r0, #4
	strh r0, [r2, #4]
_08005F42:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08005F48: .4byte 0x0203B400
_08005F4C: .4byte 0x030046B8
_08005F50: .4byte 0x000003FF

	thumb_func_start FUN_08005f54
FUN_08005f54: @ 0x08005F54
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	mov sl, r0
	adds r5, r1, #0
	add r7, sp, #0x10
	ldr r3, [r5, #0x2c]
	ldrh r1, [r3]
	lsls r1, r1, #0x10
	asrs r6, r1, #0x11
	ldrh r1, [r3, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x11
	subs r2, r6, r4
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #4
	cmp r1, #0
	blt _08005F84
	asrs r1, r1, #8
	b _08005F8A
_08005F84:
	rsbs r1, r1, #0
	asrs r1, r1, #8
	rsbs r1, r1, #0
_08005F8A:
	strh r1, [r7]
	adds r2, r6, r4
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #4
	cmp r1, #0
	blt _08005F9C
	asrs r1, r1, #8
	b _08005FA2
_08005F9C:
	rsbs r1, r1, #0
	asrs r1, r1, #8
	rsbs r1, r1, #0
_08005FA2:
	adds r4, r1, #0
	movs r1, #2
	ldrsh r2, [r3, r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	cmp r1, #0
	blt _08005FB6
	asrs r2, r1, #8
	b _08005FBC
_08005FB6:
	rsbs r1, r1, #0
	asrs r1, r1, #8
	rsbs r2, r1, #0
_08005FBC:
	subs r1, r4, r2
	strh r1, [r7, #2]
	adds r1, r4, r2
	strh r1, [r7, #4]
	ldrb r1, [r5, #0xd]
	cmp r1, #0
	beq _08005FE2
	subs r1, #1
	strb r1, [r5, #0xd]
	lsls r1, r1, #0x18
	cmp r1, #0
	bne _08005FE2
	movs r1, #4
	strb r1, [r5, #0xf]
	ldr r2, [r5, #0x2c]
	ldrh r1, [r2]
	strh r1, [r5, #0x10]
	ldrh r1, [r2, #4]
	strh r1, [r5, #0x12]
_08005FE2:
	movs r2, #1
	str r2, [sp, #0x20]
	movs r6, #0
	mov r8, r6
	mov r7, sl
	adds r7, #0x2c
	str r7, [sp, #0x24]
	add r1, sp, #0x10
	mov sb, r1
_08005FF4:
	mov r2, r8
	lsls r3, r2, #2
	ldr r6, [sp, #0x24]
	adds r1, r6, r3
	ldr r6, [r1]
	cmp r6, #0
	bne _08006004
	b _08006170
_08006004:
	movs r1, #0xc
	ldr r2, _080060F4 @ =0x03002BC0
	adds r2, r3, r2
	ldr r2, [r2]
	ands r2, r1
	cmp r2, #0
	beq _08006014
	b _08006170
_08006014:
	ldr r3, [r5, #0x2c]
	mov r7, r8
	lsls r1, r7, #3
	mov r2, sl
	adds r4, r1, r2
	adds r4, #0x3c
	mov r7, sb
	movs r1, #2
	ldrsh r2, [r7, r1]
	movs r7, #2
	ldrsh r1, [r4, r7]
	subs r2, r2, r1
	mov ip, r2
	movs r1, #2
	ldrsh r2, [r3, r1]
	movs r7, #0x2e
	ldrsh r1, [r6, r7]
	subs r1, r2, r1
	cmp r1, #0
	bge _0800603E
	rsbs r1, r1, #0
_0800603E:
	cmp r1, #0x7f
	bgt _08006068
	mov r1, sb
	movs r6, #0
	ldrsh r2, [r1, r6]
	movs r7, #0
	ldrsh r1, [r4, r7]
	subs r1, r2, r1
	cmp r1, #0
	bge _08006054
	rsbs r1, r1, #0
_08006054:
	cmp r1, #0xe
	bgt _08006068
	movs r1, #0x18
	rsbs r1, r1, #0
	cmp ip, r1
	blt _08006068
	movs r1, #1
	mov r2, ip
	cmp r2, #4
	ble _0800606A
_08006068:
	movs r1, #0
_0800606A:
	cmp r1, #0
	bne _08006070
	b _08006170
_08006070:
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r2, [sp, #0x18]
	asrs r1, r2, #0x10
	adds r1, #0x80
	lsls r1, r1, #0x10
	ldr r0, _080060F8 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r0, _080060FC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08006100
	movs r6, #0
	ldrsh r0, [r5, r6]
	movs r7, #2
	ldrsh r1, [r5, r7]
	bl CheckEmptySlotExist
	adds r1, r0, #0
	cmp r1, #0
	bne _08006100
	ldrb r1, [r5, #0xe]
	cmp r1, #0
	beq _0800616C
	ldrb r1, [r5, #0xd]
	cmp r1, #0
	bne _0800616C
	movs r2, #0
	ldrsh r1, [r5, r2]
	cmp r1, #3
	bgt _080060DE
	adds r0, r1, #0
	movs r7, #2
	ldrsh r1, [r5, r7]
	add r2, sp, #0x18
	str r2, [sp]
	str r2, [sp, #4]
	movs r2, #0x18
	str r2, [sp, #8]
	str r5, [sp, #0xc]
	movs r2, #1
	mov r3, r8
	bl FUN_080177b4
	movs r0, #0x88
	lsls r0, r0, #1
	bl PlaySound_0824078c
_080060DE:
	movs r1, #0x24
	strb r1, [r5, #0xd]
	movs r1, #4
	strb r1, [r5, #0xf]
	ldr r2, [r5, #0x2c]
	ldrh r1, [r2]
	strh r1, [r5, #0x10]
	ldrh r1, [r2, #4]
	strh r1, [r5, #0x12]
	b _0800616C
	.align 2, 0
_080060F4: .4byte 0x03002BC0
_080060F8: .4byte 0x0000FFFF
_080060FC: .4byte 0x030047A4
_08006100:
	mov r0, r8
	strb r0, [r5, #4]
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #3
	bgt _08006124
	movs r6, #2
	ldrsh r1, [r5, r6]
	add r2, sp, #0x18
	str r2, [sp]
	str r2, [sp, #4]
	movs r2, #0x18
	str r2, [sp, #8]
	str r5, [sp, #0xc]
	movs r2, #0
	mov r3, r8
	bl FUN_080177b4
_08006124:
	ldr r6, _08006168 @ =0x030047A4
	ldr r0, [r6]
	movs r4, #0x80
	lsls r4, r4, #4
	ands r0, r4
	cmp r0, #0
	bne _08006154
	movs r0, #0x88
	lsls r0, r0, #1
	bl PlaySound_0824078c
	ldr r0, [r6]
	ands r0, r4
	cmp r0, #0
	bne _08006154
	movs r7, #0
	ldrsh r0, [r5, r7]
	movs r2, #2
	ldrsh r1, [r5, r2]
	bl CheckEmptySlotExist
	movs r2, #0
	cmp r0, #1
	bne _08006156
_08006154:
	movs r2, #1
_08006156:
	ldrh r1, [r5, #0x34]
	adds r0, r5, #0
	bl FUN_08005d84
	ldrb r2, [r5, #6]
	movs r1, #1
	orrs r1, r2
	strb r1, [r5, #6]
	b _0800617C
	.align 2, 0
_08006168: .4byte 0x030047A4
_0800616C:
	movs r6, #0
	str r6, [sp, #0x20]
_08006170:
	movs r7, #1
	add r8, r7
	mov r1, r8
	cmp r1, #3
	bgt _0800617C
	b _08005FF4
_0800617C:
	add r2, sp, #0x20
	ldrb r2, [r2]
	strb r2, [r5, #0xe]
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08006194
FUN_08006194: @ 0x08006194
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, _08006254 @ =0x0300002C
	ldr r6, [r0]
	cmp r6, #0
	bne _080061AA
	b _080062C2
_080061AA:
	ldrb r0, [r7, #4]
	mov r8, r0
	ldr r4, [r6, #0x28]
	cmp r4, #0
	bne _080061B6
	b _080062C2
_080061B6:
	movs r1, #0
	mov sb, r1
_080061BA:
	ldrb r1, [r4, #6]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0800624C
	ldrh r1, [r4, #4]
	ldr r0, _08006258 @ =0x000001FF
	cmp r1, r0
	bne _0800624C
	adds r3, r7, #0
	adds r3, #8
	ldr r2, [r4, #0x2c]
	movs r5, #0
	ldrsh r1, [r2, r5]
	movs r5, #8
	ldrsh r0, [r7, r5]
	subs r1, r1, r0
	cmp r1, #0
	bge _080061E2
	rsbs r1, r1, #0
_080061E2:
	cmp r1, #0x5f
	bgt _08006210
	movs r0, #2
	ldrsh r1, [r2, r0]
	movs r5, #2
	ldrsh r0, [r3, r5]
	subs r1, r1, r0
	cmp r1, #0
	bge _080061F6
	rsbs r1, r1, #0
_080061F6:
	cmp r1, #0x7f
	bgt _08006210
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #4
	ldrsh r0, [r3, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _0800620A
	rsbs r1, r1, #0
_0800620A:
	movs r0, #1
	cmp r1, #0x5f
	ble _08006212
_08006210:
	movs r0, #0
_08006212:
	cmp r0, #0
	beq _0800624C
	ldr r1, _0800625C @ =0x03002BE0
	mov r5, r8
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08006260
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _08006260
	ldrb r0, [r4, #0x15]
	cmp r0, #1
	bne _08006260
	adds r5, r6, #0
	adds r5, #0x24
	ldrb r0, [r5]
	cmp r0, #0
	bne _0800624C
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #0xf
	strb r0, [r5]
_0800624C:
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r4, [r0]
	b _080062BC
	.align 2, 0
_08006254: .4byte 0x0300002C
_08006258: .4byte 0x000001FF
_0800625C: .4byte 0x03002BE0
_08006260:
	mov r2, r8
	strb r2, [r4, #4]
	ldr r0, _080062B0 @ =0x0000010F
	bl PlaySound_0824078c
	ldr r0, _080062B4 @ =FUN_0800676c
	str r0, [r4, #0x44]
	mov r5, sb
	str r5, [r4, #0x18]
	strb r5, [r4, #9]
	ldr r0, [r4, #0x28]
	ldr r1, [r6, #0x1c]
	str r5, [sp]
	movs r2, #5
	movs r3, #0
	bl FUN_08236fac
	ldr r0, _080062B8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080062A2
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r2, #2
	ldrsh r1, [r4, r2]
	bl CheckEmptySlotExist
	movs r2, #0
	cmp r0, #1
	bne _080062A4
_080062A2:
	movs r2, #1
_080062A4:
	ldrh r1, [r4, #0x30]
	adds r0, r4, #0
	bl FUN_08005d84
	movs r0, #1
	b _080062C4
	.align 2, 0
_080062B0: .4byte 0x0000010F
_080062B4: .4byte FUN_0800676c
_080062B8: .4byte 0x030047A4
_080062BC:
	cmp r4, #0
	beq _080062C2
	b _080061BA
_080062C2:
	movs r0, #0
_080062C4:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080062d4
FUN_080062d4: @ 0x080062D4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r5, r1, #0
	ldr r0, [r5, #0x2c]
	movs r1, #2
	ldrsh r7, [r0, r1]
	adds r6, r0, #0
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0800630A
	cmp r1, #0
	blt _0800630A
	ldr r0, _08006310 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800630A
	ldr r0, _08006314 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08006318
_0800630A:
	movs r4, #0
	b _08006326
	.align 2, 0
_08006310: .4byte 0x030046A8
_08006314: .4byte 0x030046AC
_08006318:
	ldr r0, _08006338 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08006326:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0800633C
	adds r0, #4
	b _08006348
	.align 2, 0
_08006338: .4byte 0x030046A4
_0800633C:
	ldr r0, _0800635C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08006348:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08006360
	cmp r3, #2
	beq _08006364
	b _08006368
	.align 2, 0
_0800635C: .4byte 0x030046A4
_08006360:
	ldrb r0, [r6, #4]
	b _08006366
_08006364:
	ldrb r0, [r6]
_08006366:
	subs r2, r2, r0
_08006368:
	subs r0, r7, r2
	cmp r0, #0
	ble _0800638E
	ldr r2, [r5, #0x2c]
	adds r1, r0, #0
	cmp r1, #0x20
	ble _08006378
	movs r1, #0x20
_08006378:
	ldrh r0, [r2, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	mov r0, r8
	adds r1, r5, #0
	bl FUN_08005f54
	ldr r0, [r5, #0x18]
	adds r0, #1
	str r0, [r5, #0x18]
	b _0800639C
_0800638E:
	ldr r1, [r5, #0x2c]
	adds r0, r2, #1
	movs r2, #0
	strh r0, [r1, #2]
	ldr r0, _080063A8 @ =FUN_080063ac
	str r0, [r5, #0x44]
	str r2, [r5, #0x18]
_0800639C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080063A8: .4byte FUN_080063ac

	thumb_func_start FUN_080063ac
FUN_080063ac: @ 0x080063AC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	ldr r6, [r4, #0x2c]
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080063D8
	cmp r1, #0
	blt _080063D8
	ldr r0, _080063DC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080063D8
	ldr r0, _080063E0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080063E4
_080063D8:
	movs r5, #0
	b _080063F2
	.align 2, 0
_080063DC: .4byte 0x030046A8
_080063E0: .4byte 0x030046AC
_080063E4:
	ldr r0, _08006404 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_080063F2:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08006408
	adds r0, #4
	b _08006414
	.align 2, 0
_08006404: .4byte 0x030046A4
_08006408:
	ldr r0, _08006428 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08006414:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0800642C
	cmp r3, #2
	beq _08006430
	b _08006434
	.align 2, 0
_08006428: .4byte 0x030046A4
_0800642C:
	ldrb r0, [r6, #4]
	b _08006432
_08006430:
	ldrb r0, [r6]
_08006432:
	subs r2, r2, r0
_08006434:
	ldr r0, [r4, #0x18]
	cmp r0, #2
	bhi _08006442
	ldr r1, [r4, #0x2c]
	ldrh r0, [r1, #2]
	adds r0, #8
	b _0800646A
_08006442:
	cmp r0, #5
	bls _08006464
	ldr r0, _08006460 @ =FUN_080065a4
	str r0, [r4, #0x44]
	movs r0, #0
	str r0, [r4, #0x18]
	ldr r1, [r4, #0x2c]
	adds r0, r2, #1
	strh r0, [r1, #2]
	adds r0, r4, #0
	adds r0, #0x48
	bl FUN_080139a0
	b _08006480
	.align 2, 0
_08006460: .4byte FUN_080065a4
_08006464:
	ldr r1, [r4, #0x2c]
	ldrh r0, [r1, #2]
	subs r0, #8
_0800646A:
	strh r0, [r1, #2]
	adds r0, r4, #0
	bl FUN_08005ee4
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_08005f54
	ldr r0, [r4, #0x18]
	adds r0, #1
	str r0, [r4, #0x18]
_08006480:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08006488
FUN_08006488: @ 0x08006488
	push {r4, r5, r6, r7, lr}
	adds r7, r1, #0
	ldr r5, [r7, #0x20]
	ldr r4, [r7, #0x28]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080064BC
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080064C4
_080064BC:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080064C4:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080064E8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080064F0
_080064E8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080064F0:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08006528 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08006560
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0800652C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08006520
	ldrb r0, [r4, #5]
_08006520:
	subs r0, #1
	strh r0, [r4, #8]
	b _0800653C
	.align 2, 0
_08006528: .4byte 0x0000FFFF
_0800652C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0800653C
	strh r1, [r4, #8]
_0800653C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08006560
	movs r0, #1
	strb r0, [r4, #7]
_08006560:
	ldrb r0, [r7, #7]
	cmp r0, #0
	beq _08006570
	ldr r0, [r7, #0x20]
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	str r1, [r0]
_08006570:
	ldr r0, [r7, #0x18]
	cmp r0, #3
	bhi _0800657E
	ldr r1, [r7, #0x2c]
	ldrh r0, [r1, #2]
	adds r0, #8
	b _08006596
_0800657E:
	cmp r0, #7
	bls _08006590
	ldr r0, _0800658C @ =FUN_08006678
	str r0, [r7, #0x44]
	movs r0, #0
	b _0800659C
	.align 2, 0
_0800658C: .4byte FUN_08006678
_08006590:
	ldr r1, [r7, #0x2c]
	ldrh r0, [r1, #2]
	subs r0, #8
_08006596:
	strh r0, [r1, #2]
	ldr r0, [r7, #0x18]
	adds r0, #1
_0800659C:
	str r0, [r7, #0x18]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080065a4
FUN_080065a4: @ 0x080065A4
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r2, [r4, #8]
	cmp r2, #0
	bne _080065C8
	ldr r1, [r4, #0x18]
	ldr r0, _080065C0 @ =0x00000383
	cmp r1, r0
	bls _080065C8
	ldr r0, _080065C4 @ =FUN_08006640
	str r0, [r4, #0x44]
	str r2, [r4, #0x18]
	b _08006636
	.align 2, 0
_080065C0: .4byte 0x00000383
_080065C4: .4byte FUN_08006640
_080065C8:
	ldr r0, [r4, #0x18]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0xf
	bne _08006622
	ldr r0, [r4, #0x2c]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080065F8
	cmp r1, #0
	blt _080065F8
	ldr r0, _080065FC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080065F8
	ldr r0, _08006600 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08006604
_080065F8:
	movs r0, #0
	b _08006612
	.align 2, 0
_080065FC: .4byte 0x030046A8
_08006600: .4byte 0x030046AC
_08006604:
	ldr r0, _0800663C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_08006612:
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08006622
	movs r0, #0xe1
	lsls r0, r0, #2
	str r0, [r4, #0x18]
_08006622:
	adds r0, r4, #0
	bl FUN_08005ee4
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08005f54
	ldr r0, [r4, #0x18]
	adds r0, #1
	str r0, [r4, #0x18]
_08006636:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800663C: .4byte 0x030046A4

	thumb_func_start FUN_08006640
FUN_08006640: @ 0x08006640
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, [r4, #0x1c]
	ldr r1, [r4, #0x18]
	movs r2, #0x2d
	movs r3, #0x5a
	bl FUN_082375c8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08006662
	ldrb r1, [r4, #6]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #6]
	b _0800666A
_08006662:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08005f54
_0800666A:
	ldr r0, [r4, #0x18]
	adds r0, #1
	str r0, [r4, #0x18]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08006678
FUN_08006678: @ 0x08006678
	push {r4, r5, r6, r7, lr}
	adds r7, r1, #0
	ldr r5, [r7, #0x20]
	ldr r4, [r7, #0x28]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080066AC
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080066B4
_080066AC:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080066B4:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080066D8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080066E0
_080066D8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080066E0:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08006718 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08006750
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0800671C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08006710
	ldrb r0, [r4, #5]
_08006710:
	subs r0, #1
	strh r0, [r4, #8]
	b _0800672C
	.align 2, 0
_08006718: .4byte 0x0000FFFF
_0800671C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0800672C
	strh r1, [r4, #8]
_0800672C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08006750
	movs r0, #1
	strb r0, [r4, #7]
_08006750:
	ldrb r0, [r7, #7]
	cmp r0, #0
	beq _08006760
	ldr r0, [r7, #0x20]
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	str r1, [r0]
_08006760:
	ldr r0, [r7, #0x18]
	adds r0, #1
	str r0, [r7, #0x18]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0800676c
FUN_0800676c: @ 0x0800676C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r6, r1, #0
	ldr r5, [r6, #0x20]
	ldr r4, [r6, #0x28]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080067A2
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080067AA
_080067A2:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080067AA:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080067CE
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080067D6
_080067CE:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080067D6:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08006810 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08006856
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0800681A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08006814
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r3, #1
	b _08006830
	.align 2, 0
_08006810: .4byte 0x0000FFFF
_08006814:
	subs r0, #1
	strh r0, [r4, #8]
	b _0800682E
_0800681A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0800682E
	strh r1, [r4, #8]
	movs r3, #1
	b _08006830
_0800682E:
	movs r3, #0
_08006830:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08006858
	movs r0, #1
	strb r0, [r4, #7]
	b _08006858
_08006856:
	movs r3, #0
_08006858:
	ldrb r0, [r6, #7]
	cmp r0, #0
	beq _08006868
	ldr r0, [r6, #0x20]
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	str r1, [r0]
_08006868:
	cmp r3, #0
	beq _08006920
	ldr r0, [r6, #0x2c]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r2, [sp, #0x10]
	asrs r1, r2, #0x10
	adds r1, #0x80
	lsls r1, r1, #0x10
	ldr r0, _080068CC @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, _080068D0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080068D8
	movs r1, #0
	ldrsh r0, [r6, r1]
	movs r2, #2
	ldrsh r1, [r6, r2]
	bl CheckEmptySlotExist
	cmp r0, #0
	bne _080068D8
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #3
	bgt _080068C6
	movs r2, #2
	ldrsh r1, [r6, r2]
	movs r3, #4
	ldrsb r3, [r6, r3]
	add r2, sp, #0x10
	str r2, [sp]
	str r2, [sp, #4]
	movs r2, #0x18
	str r2, [sp, #8]
	str r6, [sp, #0xc]
	movs r2, #1
	bl FUN_080177b4
_080068C6:
	ldr r0, _080068D4 @ =FUN_08006a80
	b _080068FC
	.align 2, 0
_080068CC: .4byte 0x0000FFFF
_080068D0: .4byte 0x030047A4
_080068D4: .4byte FUN_08006a80
_080068D8:
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #3
	bgt _080068FA
	movs r2, #2
	ldrsh r1, [r6, r2]
	movs r3, #4
	ldrsb r3, [r6, r3]
	add r2, sp, #0x10
	str r2, [sp]
	str r2, [sp, #4]
	movs r2, #0x18
	str r2, [sp, #8]
	str r6, [sp, #0xc]
	movs r2, #0
	bl FUN_080177b4
_080068FA:
	ldr r0, _08006918 @ =FUN_08006930
_080068FC:
	str r0, [r6, #0x44]
	movs r2, #0
	str r2, [r6, #0x18]
	ldr r0, [r6, #0x28]
	ldr r1, _0800691C @ =0x0300002C
	ldr r1, [r1]
	ldr r1, [r1, #0x1c]
	str r2, [sp]
	movs r2, #6
	movs r3, #0
	bl FUN_08236fac
	b _08006926
	.align 2, 0
_08006918: .4byte FUN_08006930
_0800691C: .4byte 0x0300002C
_08006920:
	ldr r0, [r6, #0x18]
	adds r0, #1
	str r0, [r6, #0x18]
_08006926:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08006930
FUN_08006930: @ 0x08006930
	push {r4, r5, r6, r7, lr}
	adds r7, r1, #0
	ldr r5, [r7, #0x20]
	ldr r4, [r7, #0x28]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08006964
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0800696C
_08006964:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0800696C:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08006990
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08006998
_08006990:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08006998:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080069D0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08006A08
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080069D4
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080069C8
	ldrb r0, [r4, #5]
_080069C8:
	subs r0, #1
	strh r0, [r4, #8]
	b _080069E4
	.align 2, 0
_080069D0: .4byte 0x0000FFFF
_080069D4:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080069E4
	strh r1, [r4, #8]
_080069E4:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08006A08
	movs r0, #1
	strb r0, [r4, #7]
_08006A08:
	ldrb r0, [r7, #7]
	cmp r0, #0
	beq _08006A18
	ldr r0, [r7, #0x20]
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	str r1, [r0]
_08006A18:
	ldr r1, [r7, #0x18]
	cmp r1, #8
	bne _08006A58
	ldr r0, _08006A54 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08006A34
	movs r0, #0x88
	lsls r0, r0, #1
	bl PlaySound_0824078c
_08006A34:
	ldrh r4, [r7, #0x34]
	movs r1, #0
	ldrsh r0, [r7, r1]
	movs r2, #2
	ldrsh r1, [r7, r2]
	bl CheckEmptySlotExist
	movs r2, #0
	cmp r0, #1
	bne _08006A4A
	movs r2, #1
_08006A4A:
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_08005d84
	b _08006A74
	.align 2, 0
_08006A54: .4byte 0x030047A4
_08006A58:
	cmp r1, #8
	bls _08006A74
	ldr r0, [r7, #0x20]
	movs r2, #0x1e
	movs r3, #0x5a
	bl FUN_082375c8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08006A74
	ldrb r1, [r7, #6]
	movs r0, #1
	orrs r0, r1
	strb r0, [r7, #6]
_08006A74:
	ldr r0, [r7, #0x18]
	adds r0, #1
	str r0, [r7, #0x18]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08006a80
FUN_08006a80: @ 0x08006A80
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r1, #0
	ldr r5, [r7, #0x20]
	ldr r4, [r7, #0x28]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08006AB6
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08006ABE
_08006AB6:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08006ABE:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08006AE2
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08006AEA
_08006AE2:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08006AEA:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08006B20 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08006B58
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08006B24
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08006B1A
	ldrb r0, [r4, #5]
_08006B1A:
	subs r0, #1
	strh r0, [r4, #8]
	b _08006B34
	.align 2, 0
_08006B20: .4byte 0x0000FFFF
_08006B24:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08006B34
	strh r1, [r4, #8]
_08006B34:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08006B58
	movs r0, #1
	strb r0, [r4, #7]
_08006B58:
	ldrb r0, [r7, #7]
	cmp r0, #0
	beq _08006B68
	ldr r0, [r7, #0x20]
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	str r1, [r0]
_08006B68:
	ldr r0, [r7, #0x18]
	cmp r0, #0x1f
	bls _08006B8A
	ldr r0, _08006B98 @ =FUN_08006ba0
	str r0, [r7, #0x44]
	movs r0, #0
	str r0, [r7, #0x18]
	ldr r0, [r7, #0x28]
	ldr r1, _08006B9C @ =0x0300002C
	ldr r1, [r1]
	ldr r1, [r1, #0x1c]
	movs r2, #4
	str r2, [sp]
	movs r2, #5
	movs r3, #0
	bl FUN_08236fac
_08006B8A:
	ldr r0, [r7, #0x18]
	adds r0, #1
	str r0, [r7, #0x18]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08006B98: .4byte FUN_08006ba0
_08006B9C: .4byte 0x0300002C

	thumb_func_start FUN_08006ba0
FUN_08006ba0: @ 0x08006BA0
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	mov ip, r0
	adds r7, r1, #0
	ldr r5, [r7, #0x20]
	ldr r4, [r7, #0x28]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08006BD8
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08006BE0
_08006BD8:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08006BE0:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08006C04
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08006C0C
_08006C04:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08006C0C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08006C44 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _08006C8A
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08006C4E
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08006C48
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r3, #1
	b _08006C64
	.align 2, 0
_08006C44: .4byte 0x0000FFFF
_08006C48:
	subs r0, #1
	strh r0, [r4, #8]
	b _08006C62
_08006C4E:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08006C62
	strh r1, [r4, #8]
	movs r3, #1
	b _08006C64
_08006C62:
	movs r3, #0
_08006C64:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08006C8C
	movs r0, #1
	strb r0, [r4, #7]
	b _08006C8C
_08006C8A:
	movs r3, #0
_08006C8C:
	ldrb r0, [r7, #7]
	cmp r0, #0
	beq _08006C9C
	ldr r0, [r7, #0x20]
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	str r1, [r0]
_08006C9C:
	cmp r3, #0
	beq _08006CC0
	ldr r0, _08006CBC @ =FUN_08006678
	str r0, [r7, #0x44]
	movs r2, #0
	str r2, [r7, #0x18]
	movs r0, #0xff
	strb r0, [r7, #4]
	ldr r0, [r7, #0x28]
	mov r3, ip
	ldr r1, [r3, #0x1c]
	str r2, [sp]
	movs r3, #0
	bl FUN_08236fac
	b _08006CC6
	.align 2, 0
_08006CBC: .4byte FUN_08006678
_08006CC0:
	ldr r0, [r7, #0x18]
	adds r0, #1
	str r0, [r7, #0x18]
_08006CC6:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08006cd0
FUN_08006cd0: @ 0x08006CD0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	movs r6, #0
	ldr r0, _08006D20 @ =0x03002BE0
	mov r8, r0
_08006CE2:
	lsls r1, r6, #2
	mov r2, r8
	adds r0, r1, r2
	ldr r2, [r0]
	mov r0, sl
	adds r0, #0x2c
	adds r0, r0, r1
	str r2, [r0]
	cmp r2, #0
	beq _08006D64
	lsls r0, r6, #3
	mov r7, sl
	adds r3, r0, r7
	adds r3, #0x3c
	adds r5, r2, #0
	adds r5, #0x2c
	ldrh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08006D24
	asrs r0, r0, #8
	b _08006D2A
	.align 2, 0
_08006D20: .4byte 0x03002BE0
_08006D24:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08006D2A:
	strh r0, [r3]
	adds r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08006D3C
	asrs r0, r0, #8
	b _08006D42
_08006D3C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08006D42:
	adds r2, r0, #0
	movs r0, #2
	ldrsh r1, [r5, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08006D56
	asrs r1, r0, #8
	b _08006D5C
_08006D56:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_08006D5C:
	subs r0, r2, r1
	strh r0, [r3, #2]
	adds r0, r2, r1
	strh r0, [r3, #4]
_08006D64:
	adds r6, #1
	cmp r6, #3
	ble _08006CE2
	mov r1, sl
	ldr r3, [r1, #0x28]
	movs r2, #0x24
	add r2, sl
	mov sb, r2
	cmp r3, #0
	bne _08006D7A
	b _08006F3C
_08006D7A:
	movs r5, #1
	movs r6, #2
	rsbs r6, r6, #0
_08006D80:
	adds r0, r3, #0
	adds r0, #0xb8
	ldr r0, [r0]
	mov r8, r0
	ldrb r1, [r3, #6]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _08006D9A
	adds r0, r3, #0
	bl FUN_08005e90
	b _08006F34
_08006D9A:
	ldrh r0, [r3, #0x16]
	cmp r0, #0
	beq _08006DC4
	ldr r0, _08006DB8 @ =0x030046A0
	ldr r0, [r0]
	movs r7, #0x92
	lsls r7, r7, #2
	adds r0, r0, r7
	ldr r0, [r0]
	ldrh r1, [r3, #0x16]
	cmp r0, r1
	bne _08006DBC
	movs r0, #1
	b _08006DBE
	.align 2, 0
_08006DB8: .4byte 0x030046A0
_08006DBC:
	movs r0, #0
_08006DBE:
	cmp r0, #0
	bne _08006DC4
	b _08006F12
_08006DC4:
	ldr r1, [r3, #0x1c]
	cmp r1, #0
	beq _08006DD0
	ldr r0, [r1]
	ands r0, r6
	str r0, [r1]
_08006DD0:
	ldr r1, [r3, #0x20]
	adds r4, r1, #0
	cmp r1, #0
	bne _08006DDA
	b _08006F2A
_08006DDA:
	ldrb r0, [r3, #9]
	cmp r0, #0
	bne _08006DE2
	b _08006F0C
_08006DE2:
	ldr r0, _08006DFC @ =0x03002B48
	ldr r0, [r0]
	cmp r0, #0
	ble _08006E00
	ldr r0, [r1]
	ands r0, r6
	str r0, [r1]
	movs r0, #0
	strb r0, [r3, #0xb]
_08006DF4:
	strb r0, [r3, #0xc]
_08006DF6:
	strb r5, [r3, #0xa]
	b _08006F2A
	.align 2, 0
_08006DFC: .4byte 0x03002B48
_08006E00:
	ldr r0, _08006E34 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08006E48
	ldr r0, _08006E38 @ =0x03002BE0
	ldr r1, [r0]
	cmp r1, #0
	beq _08006E44
	ldr r2, _08006E3C @ =0x00000446
	adds r0, r1, r2
	ldrh r0, [r0]
	movs r2, #0
	cmp r0, #0
	beq _08006E2E
	ldr r7, _08006E40 @ =0x00000442
	adds r0, r1, r7
	ldrh r0, [r0]
	cmp r0, #4
	bne _08006E2E
	movs r2, #1
_08006E2E:
	adds r0, r2, #0
	b _08006E70
	.align 2, 0
_08006E34: .4byte 0x030047A4
_08006E38: .4byte 0x03002BE0
_08006E3C: .4byte 0x00000446
_08006E40: .4byte 0x00000442
_08006E44:
	movs r0, #0
	b _08006E70
_08006E48:
	ldr r0, _08006E9C @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #2
	beq _08006E74
	ldr r0, _08006EA0 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _08006E6E
	ldr r0, _08006EA4 @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #4
	bne _08006E6E
	movs r1, #1
_08006E6E:
	adds r0, r1, #0
_08006E70:
	cmp r0, #0
	beq _08006ED8
_08006E74:
	ldrb r0, [r3, #0xa]
	cmp r0, #0
	beq _08006E7E
	movs r0, #0x1f
	strb r0, [r3, #0xb]
_08006E7E:
	ldrb r1, [r3, #0xb]
	adds r2, r1, #0
	cmp r2, #0
	beq _08006EB0
	subs r1, #1
	strb r1, [r3, #0xb]
	movs r0, #0xf
	ands r1, r0
	cmp r1, #7
	bls _08006EA8
	ldr r0, [r4]
	ands r0, r6
	str r0, [r4]
	b _08006ED2
	.align 2, 0
_08006E9C: .4byte 0x030046A0
_08006EA0: .4byte 0x03002B8C
_08006EA4: .4byte 0x03002B60
_08006EA8:
	ldr r0, [r4]
	orrs r0, r5
	str r0, [r4]
	b _08006ED2
_08006EB0:
	ldrb r0, [r3, #0xc]
	cmp r0, #0x2f
	bhi _08006EBE
	ldr r0, [r4]
	ands r0, r6
	str r0, [r4]
	b _08006ECC
_08006EBE:
	cmp r0, #0x47
	bhi _08006ECA
	ldr r0, [r4]
	orrs r0, r5
	str r0, [r4]
	b _08006ECC
_08006ECA:
	strb r2, [r3, #0xc]
_08006ECC:
	ldrb r0, [r3, #0xc]
	adds r0, #1
	strb r0, [r3, #0xc]
_08006ED2:
	movs r0, #0
	strb r0, [r3, #0xa]
	b _08006F2A
_08006ED8:
	ldrb r0, [r3, #0xa]
	cmp r0, #0
	bne _08006EE2
	movs r0, #0x2f
	strb r0, [r3, #0xb]
_08006EE2:
	ldrb r1, [r3, #0xb]
	cmp r1, #0
	beq _08006F04
	subs r1, #1
	strb r1, [r3, #0xb]
	movs r0, #0xf
	ands r1, r0
	cmp r1, #7
	bls _08006EFA
	ldr r0, [r4]
	orrs r0, r5
	b _08006EFE
_08006EFA:
	ldr r0, [r4]
	ands r0, r6
_08006EFE:
	str r0, [r4]
	movs r0, #0
	b _08006DF4
_08006F04:
	ldr r0, [r4]
	orrs r0, r5
	str r0, [r4]
	b _08006DF6
_08006F0C:
	ldr r0, [r1]
	ands r0, r6
	b _08006F28
_08006F12:
	ldr r1, [r3, #0x1c]
	cmp r1, #0
	beq _08006F1E
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
_08006F1E:
	ldr r1, [r3, #0x20]
	cmp r1, #0
	beq _08006F2A
	ldr r0, [r1]
	orrs r0, r5
_08006F28:
	str r0, [r1]
_08006F2A:
	ldr r2, [r3, #0x44]
	mov r0, sl
	adds r1, r3, #0
	bl _call_via_r2
_08006F34:
	mov r3, r8
	cmp r3, #0
	beq _08006F3C
	b _08006D80
_08006F3C:
	mov r7, sb
	ldrb r0, [r7]
	cmp r0, #0
	beq _08006F48
	subs r0, #1
	strb r0, [r7]
_08006F48:
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08006f58
FUN_08006f58: @ 0x08006F58
	push {r4, lr}
	ldr r1, [r0, #0x28]
	cmp r1, #0
	beq _08006F72
_08006F60:
	adds r0, r1, #0
	adds r0, #0xb8
	ldr r4, [r0]
	adds r0, r1, #0
	bl FUN_08005e90
	adds r1, r4, #0
	cmp r1, #0
	bne _08006F60
_08006F72:
	ldr r1, _08006F80 @ =0x0300002C
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08006F80: .4byte 0x0300002C

	thumb_func_start FUN_08006f84
FUN_08006f84: @ 0x08006F84
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _08006FE4 @ =0x0300002C
	str r5, [r0]
	ldr r0, _08006FE8 @ =0x00001C1A
	bl GetParticleGroup
	str r0, [r5, #0x18]
	movs r4, #0
	ldr r0, _08006FEC @ =0x00003876
	strh r0, [r5, #0x20]
	ldr r0, _08006FF0 @ =0x0000922E
	ldr r1, _08006FF4 @ =0x00009AF2
	bl GetFile
	str r0, [r5, #0x1c]
	str r4, [r5, #0x28]
	movs r7, #0
_08006FA8:
	ldr r0, _08006FF8 @ =0x03002BE0
	lsls r1, r7, #2
	adds r0, r1, r0
	ldr r2, [r0]
	adds r0, r5, #0
	adds r0, #0x2c
	adds r0, r0, r1
	str r2, [r0]
	cmp r2, #0
	beq _0800703C
	lsls r0, r7, #3
	adds r3, r0, r5
	adds r3, #0x3c
	adds r6, r2, #0
	adds r6, #0x2c
	ldrh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08006FFC
	asrs r0, r0, #8
	b _08007002
	.align 2, 0
_08006FE4: .4byte 0x0300002C
_08006FE8: .4byte 0x00001C1A
_08006FEC: .4byte 0x00003876
_08006FF0: .4byte 0x0000922E
_08006FF4: .4byte 0x00009AF2
_08006FF8: .4byte 0x03002BE0
_08006FFC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08007002:
	strh r0, [r3]
	adds r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08007014
	asrs r0, r0, #8
	b _0800701A
_08007014:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0800701A:
	adds r2, r0, #0
	movs r0, #2
	ldrsh r1, [r6, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0800702E
	asrs r1, r0, #8
	b _08007034
_0800702E:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_08007034:
	subs r0, r2, r1
	strh r0, [r3, #2]
	adds r0, r2, r1
	strh r0, [r3, #4]
_0800703C:
	adds r7, #1
	cmp r7, #3
	ble _08006FA8
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800704c
FUN_0800704c: @ 0x0800704C
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #9
	movs r1, #0x5c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08007084
	ldr r1, _0800707C @ =FUN_08006cd0
	ldr r2, _08007080 @ =FUN_08006f58
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08006f84
	cmp r0, #0
	bge _08007084
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08007086
	.align 2, 0
_0800707C: .4byte FUN_08006cd0
_08007080: .4byte FUN_08006f58
_08007084:
	adds r0, r4, #0
_08007086:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800708c
FUN_0800708c: @ 0x0800708C
	push {lr}
	ldr r0, _080070A4 @ =0x0300002C
	ldr r0, [r0]
	cmp r0, #0
	bne _0800709E
	movs r0, #0
	movs r1, #0
	bl FUN_0800704c
_0800709E:
	pop {r1}
	bx r1
	.align 2, 0
_080070A4: .4byte 0x0300002C

	thumb_func_start FUN_080070a8
FUN_080070a8: @ 0x080070A8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	mov sb, r0
	adds r6, r1, #0
	adds r7, r2, #0
	mov r8, r3
	bl FUN_0800708c
	adds r4, r0, #0
	cmp r4, #0
	beq _08007126
	movs r0, #0xbc
	bl Malloc
	adds r5, r0, #0
	cmp r5, #0
	beq _08007126
	adds r0, r5, #0
	movs r1, #0xbc
	bl ClearMemory
	movs r2, #0
	movs r1, #0
	strh r6, [r5]
	strh r7, [r5, #2]
	movs r0, #0xff
	strb r0, [r5, #4]
	strb r2, [r5, #5]
	strb r2, [r5, #6]
	strb r2, [r5, #7]
	str r1, [r5, #0x18]
	str r1, [r5, #0x1c]
	str r1, [r5, #0x20]
	str r1, [r5, #0x24]
	str r1, [r5, #0x28]
	ldr r0, _0800712C @ =FUN_080062d4
	str r0, [r5, #0x44]
	strb r2, [r5, #0xc]
	ldr r0, [sp, #0x44]
	strb r0, [r5, #0x14]
	mov r0, r8
	str r0, [r5, #0x34]
	ldr r3, [sp, #0x38]
	adds r2, r5, #0
	adds r2, #0x38
	movs r1, #2
_0800710A:
	ldm r3!, {r0}
	stm r2!, {r0}
	subs r1, #1
	cmp r1, #0
	bge _0800710A
	movs r0, #0x28
	bl Malloc
	str r0, [r5, #0x1c]
	cmp r0, #0
	bne _08007130
	adds r0, r5, #0
	bl Free
_08007126:
	movs r0, #1
	rsbs r0, r0, #0
	b _080071FC
	.align 2, 0
_0800712C: .4byte FUN_080062d4
_08007130:
	movs r1, #0x28
	bl ClearMemory
	ldr r0, [r5, #0x1c]
	ldr r1, [r4, #0x18]
	movs r2, #0
	bl FUN_0822d9f0
	ldr r0, [r5, #0x1c]
	movs r1, #8
	rsbs r1, r1, #0
	movs r2, #0xa
	rsbs r2, r2, #0
	bl FUN_0822dad4
	mov r0, sb
	movs r1, #0x80
	bl FUN_082342cc
	cmp r0, #0
	beq _0800717C
	ldr r2, [r5, #0x1c]
	ldr r3, [r4, #0x18]
	ldrb r1, [r2, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r2, #0xb]
	lsrs r0, r0, #3
	muls r1, r0, r1
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #8]
	ldr r1, [r5, #0x1c]
	movs r0, #1
	b _08007196
_0800717C:
	ldr r2, [r5, #0x1c]
	ldr r3, [r4, #0x18]
	ldrb r1, [r2, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r2, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	lsls r0, r0, #5
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #8]
	ldr r1, [r5, #0x1c]
	movs r0, #2
_08007196:
	strb r0, [r1, #0xf]
	ldr r2, [r5, #0x1c]
	mov r3, sb
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2, #0x18]
	str r1, [r2, #0x1c]
	ldr r1, [r5, #0x1c]
	movs r0, #0x10
	strb r0, [r1, #0x10]
	ldr r0, [r5, #0x1c]
	adds r0, #0x18
	str r0, [r5, #0x2c]
	ldr r1, [sp, #0x3c]
	cmp r1, #0
	beq _080071BE
	bl FUN_08241574
	strh r0, [r5, #0x16]
	b _080071C4
_080071BE:
	mov r3, sp
	ldrh r3, [r3, #0x3c]
	strh r3, [r5, #0x16]
_080071C4:
	movs r4, #0
	ldr r0, [sp, #0x40]
	strb r0, [r5, #8]
	adds r0, r5, #0
	adds r0, #0x48
	ldr r1, [r5, #0x1c]
	adds r1, #0x18
	movs r2, #0x28
	str r2, [sp]
	movs r2, #0x20
	str r2, [sp, #4]
	movs r2, #0x80
	lsls r2, r2, #2
	str r2, [sp, #8]
	movs r3, #1
	str r3, [sp, #0xc]
	movs r2, #5
	str r2, [sp, #0x10]
	str r3, [sp, #0x14]
	str r4, [sp, #0x18]
	movs r2, #0x40
	movs r3, #0x18
	bl FUN_08013ba8
	adds r0, r5, #0
	bl FUN_08005e30
	movs r0, #0
_080071FC:
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800720c
FUN_0800720c: @ 0x0800720C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _08007260
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08007258 @ =0xFFFF0000
	ldr r1, [sp, #0x1c]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0800725C @ =0x0000FFFF
	ldr r1, [sp, #0x1c]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r2, sp, #0x1c
	ldr r1, [r2, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r2, #4]
	b _0800726C
	.align 2, 0
_08007258: .4byte 0xFFFF0000
_0800725C: .4byte 0x0000FFFF
_08007260:
	ldr r2, _08007284 @ =0xFFFF0000
	str r0, [sp, #0x1c]
	add r1, sp, #0x1c
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
_0800726C:
	movs r0, #0x49
	bl prepare_08231510
	cmp r0, #0
	beq _08007288
	bl Script_GetValue
	mov sb, r0
	bl Script_GetValue
	b _0800728C
	.align 2, 0
_08007284: .4byte 0xFFFF0000
_08007288:
	movs r0, #0
	mov sb, r0
_0800728C:
	mov r8, r0
	movs r0, #0x70
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [sp, #0x24]
	movs r0, #0x4d
	movs r1, #0
	bl Script_GetKeywordValue
	mov sl, r0
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x4f
	movs r1, #0
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r1, #0
	add r0, sp, #0x18
_080072BA:
	str r1, [r0]
	subs r0, #4
	add r2, sp, #0x10
	cmp r0, r2
	bge _080072BA
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	beq _080072E8
	movs r4, #0
	add r5, sp, #0x10
	b _080072DC
_080072D4:
	bl Script_GetValue
	stm r5!, {r0}
	adds r4, #1
_080072DC:
	bl VM_GetPC
	cmp r0, #0
	beq _080072E8
	cmp r4, #2
	ble _080072D4
_080072E8:
	add r0, sp, #0x10
	str r0, [sp]
	mov r2, sl
	str r2, [sp, #4]
	str r7, [sp, #8]
	str r6, [sp, #0xc]
	add r0, sp, #0x1c
	mov r1, sb
	mov r2, r8
	ldr r3, [sp, #0x24]
	bl FUN_080070a8
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08007310
FUN_08007310: @ 0x08007310
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	mov sb, r0
	adds r4, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	bl FUN_0800708c
	mov r8, r0
	cmp r0, #0
	bne _0800732E
	b _08007428
_0800732E:
	movs r0, #0xbc
	bl Malloc
	adds r5, r0, #0
	cmp r5, #0
	beq _08007428
	adds r0, r5, #0
	movs r1, #0xbc
	bl ClearMemory
	movs r2, #0
	movs r1, #0
	strh r4, [r5]
	strh r6, [r5, #2]
	movs r0, #0xff
	strb r0, [r5, #4]
	movs r0, #1
	strb r0, [r5, #5]
	strb r2, [r5, #6]
	strb r7, [r5, #7]
	str r1, [r5, #0x18]
	str r1, [r5, #0x1c]
	str r1, [r5, #0x20]
	str r1, [r5, #0x24]
	str r1, [r5, #0x28]
	ldr r0, [sp, #0x38]
	cmp r0, #0
	beq _0800738C
	ldr r0, _08007380 @ =FUN_08006488
	str r0, [r5, #0x44]
	ldr r0, _08007384 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08007390
	ldr r0, _08007388 @ =0x0000026F
	bl PlaySound_082406e0
	b _08007390
	.align 2, 0
_08007380: .4byte FUN_08006488
_08007384: .4byte 0x030047A4
_08007388: .4byte 0x0000026F
_0800738C:
	ldr r0, _080073CC @ =FUN_08006678
	str r0, [r5, #0x44]
_08007390:
	ldr r0, [sp, #0x3c]
	str r0, [r5, #0x30]
	ldr r0, [sp, #0x40]
	str r0, [r5, #0x34]
	ldr r3, [sp, #0x44]
	adds r2, r5, #0
	adds r2, #0x38
	movs r1, #2
_080073A0:
	ldm r3!, {r0}
	stm r2!, {r0}
	subs r1, #1
	cmp r1, #0
	bge _080073A0
	movs r0, #0x2c
	bl Malloc
	str r0, [r5, #0x20]
	cmp r0, #0
	beq _08007422
	movs r1, #0x2c
	bl ClearMemory
	movs r0, #0x1c
	bl Malloc
	str r0, [r5, #0x24]
	cmp r0, #0
	bne _080073D0
	ldr r0, [r5, #0x20]
	b _0800741A
	.align 2, 0
_080073CC: .4byte FUN_08006678
_080073D0:
	movs r1, #0x1c
	bl ClearMemory
	movs r0, #0x10
	bl Malloc
	str r0, [r5, #0x28]
	cmp r0, #0
	bne _080073F0
	ldr r0, [r5, #0x20]
	cmp r0, #0
	beq _080073EC
	bl Free
_080073EC:
	ldr r0, [r5, #0x24]
	b _0800741A
_080073F0:
	movs r1, #0x10
	bl ClearMemory
	ldr r0, [r5, #0x24]
	mov r2, r8
	ldrh r1, [r2, #0x20]
	bl Video_GetActorSprite
	cmp r0, #0
	bne _0800742E
	ldr r0, [r5, #0x20]
	cmp r0, #0
	beq _0800740E
	bl Free
_0800740E:
	ldr r0, [r5, #0x24]
	cmp r0, #0
	beq _08007418
	bl Free
_08007418:
	ldr r0, [r5, #0x28]
_0800741A:
	cmp r0, #0
	beq _08007422
	bl Free
_08007422:
	adds r0, r5, #0
	bl Free
_08007428:
	movs r0, #1
	rsbs r0, r0, #0
	b _08007630
_0800742E:
	ldr r0, [r5, #0x20]
	ldr r1, [r5, #0x24]
	movs r2, #0
	bl FUN_0822a470
	ldr r2, [r5, #0x20]
	mov r3, sb
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldr r0, [r5, #0x20]
	adds r6, r0, #0
	adds r6, #0x1c
	ldrh r0, [r0, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0800746E
	cmp r1, #0
	blt _0800746E
	ldr r0, _08007474 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800746E
	ldr r0, _08007478 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0800747C
_0800746E:
	movs r4, #0
	b _0800748A
	.align 2, 0
_08007474: .4byte 0x030046A8
_08007478: .4byte 0x030046AC
_0800747C:
	ldr r0, _0800749C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0800748A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080074A0
	adds r0, #4
	b _080074AC
	.align 2, 0
_0800749C: .4byte 0x030046A4
_080074A0:
	ldr r0, _080074C0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080074AC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080074C4
	cmp r2, #2
	beq _080074C8
	b _080074CC
	.align 2, 0
_080074C0: .4byte 0x030046A4
_080074C4:
	ldrb r0, [r6, #4]
	b _080074CA
_080074C8:
	ldrb r0, [r6]
_080074CA:
	subs r1, r1, r0
_080074CC:
	ldr r0, [r5, #0x20]
	strh r1, [r0, #0x1e]
	ldrb r0, [r5, #7]
	cmp r0, #0
	beq _080074E0
	ldr r0, [r5, #0x20]
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	str r1, [r0]
_080074E0:
	ldr r0, [r5, #0x20]
	adds r0, #0x1c
	str r0, [r5, #0x2c]
	ldr r0, [sp, #0x4c]
	strb r0, [r5, #9]
	add r0, sp, #0x50
	ldrb r0, [r0]
	strb r0, [r5, #0x15]
	ldr r1, [sp, #0x50]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _08007508
	ldr r0, [r5, #0x24]
	ldr r1, _08007504 @ =0x0000028A
	bl FUN_0822b20c
	b _08007524
	.align 2, 0
_08007504: .4byte 0x0000028A
_08007508:
	cmp r0, #1
	bne _0800751C
	ldr r0, [r5, #0x24]
	ldr r1, _08007518 @ =0x0000028D
	bl FUN_0822b20c
	b _08007524
	.align 2, 0
_08007518: .4byte 0x0000028D
_0800751C:
	ldr r0, [r5, #0x24]
	ldr r1, _08007568 @ =0x0000028E
	bl FUN_0822b20c
_08007524:
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _080075CA
	ldr r2, [r5, #0x20]
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r0, _0800756C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08007580
	ldr r0, _08007570 @ =0x03002BE0
	ldr r1, [r0]
	cmp r1, #0
	beq _0800757C
	ldr r2, _08007574 @ =0x00000446
	adds r0, r1, r2
	ldrh r0, [r0]
	movs r2, #0
	cmp r0, #0
	beq _08007562
	ldr r3, _08007578 @ =0x00000442
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #4
	bne _08007562
	movs r2, #1
_08007562:
	adds r0, r2, #0
	b _080075B0
	.align 2, 0
_08007568: .4byte 0x0000028E
_0800756C: .4byte 0x030047A4
_08007570: .4byte 0x03002BE0
_08007574: .4byte 0x00000446
_08007578: .4byte 0x00000442
_0800757C:
	movs r0, #0
	b _080075B0
_08007580:
	ldr r0, _080075B8 @ =0x03002B48
	ldr r0, [r0]
	cmp r0, #0
	bgt _080075B4
	ldr r0, _080075BC @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #2
	beq _080075B4
	ldr r0, _080075C0 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080075AE
	ldr r0, _080075C4 @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #4
	bne _080075AE
	movs r1, #1
_080075AE:
	adds r0, r1, #0
_080075B0:
	cmp r0, #0
	beq _080075C8
_080075B4:
	movs r0, #0
	b _080075CA
	.align 2, 0
_080075B8: .4byte 0x03002B48
_080075BC: .4byte 0x030046A0
_080075C0: .4byte 0x03002B8C
_080075C4: .4byte 0x03002B60
_080075C8:
	movs r0, #1
_080075CA:
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x28]
	mov r3, r8
	ldr r1, [r3, #0x1c]
	movs r2, #0
	str r2, [sp]
	movs r3, #0
	bl FUN_08236fac
	ldr r0, [sp, #0x48]
	cmp r0, #0
	beq _080075EE
	ldr r0, [r5, #0x20]
	adds r0, #0x1c
	bl FUN_08241574
	strh r0, [r5, #0x16]
	b _080075F4
_080075EE:
	add r1, sp, #0x48
	ldrh r1, [r1]
	strh r1, [r5, #0x16]
_080075F4:
	adds r4, r5, #0
	adds r4, #0x48
	ldr r1, [r5, #0x20]
	adds r1, #0x1c
	movs r0, #0x28
	str r0, [sp]
	movs r0, #0x20
	str r0, [sp, #4]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #8]
	movs r2, #1
	str r2, [sp, #0xc]
	movs r0, #5
	str r0, [sp, #0x10]
	str r2, [sp, #0x14]
	movs r0, #0
	str r0, [sp, #0x18]
	adds r0, r4, #0
	movs r2, #0x40
	movs r3, #0x18
	bl FUN_08013ba8
	adds r0, r4, #0
	bl FUN_080139a0
	adds r0, r5, #0
	bl FUN_08005e30
	movs r0, #0
_08007630:
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08007640
FUN_08007640: @ 0x08007640
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _08007694
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0800768C @ =0xFFFF0000
	ldr r1, [sp, #0x28]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x28]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08007690 @ =0x0000FFFF
	ldr r1, [sp, #0x28]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x28]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r2, sp, #0x28
	ldr r1, [r2, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r2, #4]
	b _080076A0
	.align 2, 0
_0800768C: .4byte 0xFFFF0000
_08007690: .4byte 0x0000FFFF
_08007694:
	ldr r2, _080076B8 @ =0xFFFF0000
	str r0, [sp, #0x28]
	add r1, sp, #0x28
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
_080076A0:
	movs r0, #0x49
	bl prepare_08231510
	cmp r0, #0
	beq _080076BC
	bl Script_GetValue
	str r0, [sp, #0x34]
	bl Script_GetValue
	b _080076C0
	.align 2, 0
_080076B8: .4byte 0xFFFF0000
_080076BC:
	movs r0, #0
	str r0, [sp, #0x34]
_080076C0:
	mov sl, r0
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [sp, #0x30]
	movs r0, #0x67
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [sp, #0x38]
	movs r0, #0x70
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [sp, #0x3c]
	movs r0, #0x6d
	movs r1, #0
	bl Script_GetKeywordValue
	mov r8, r0
	movs r0, #0x4d
	movs r1, #0
	bl Script_GetKeywordValue
	mov sb, r0
	movs r0, #0x53
	movs r1, #0
	bl Script_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x63
	movs r1, #0
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r1, #0
	add r0, sp, #0x24
_0800770C:
	str r1, [r0]
	subs r0, #4
	add r2, sp, #0x1c
	cmp r0, r2
	bge _0800770C
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	beq _0800773A
	movs r4, #0
	add r5, sp, #0x1c
	b _0800772E
_08007726:
	bl Script_GetValue
	stm r5!, {r0}
	adds r4, #1
_0800772E:
	bl VM_GetPC
	cmp r0, #0
	beq _0800773A
	cmp r4, #2
	ble _08007726
_0800773A:
	mov r0, r8
	str r0, [sp]
	ldr r2, [sp, #0x38]
	str r2, [sp, #4]
	ldr r0, [sp, #0x3c]
	str r0, [sp, #8]
	add r2, sp, #0x1c
	str r2, [sp, #0xc]
	mov r0, sb
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	add r0, sp, #0x28
	ldr r1, [sp, #0x34]
	mov r2, sl
	ldr r3, [sp, #0x30]
	bl FUN_08007310
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08007770
FUN_08007770: @ 0x08007770
	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_0800708c
	adds r1, r0, #0
	cmp r1, #0
	bne _08007784
	movs r0, #1
	rsbs r0, r0, #0
	b _080077A2
_08007784:
	ldr r2, [r1, #0x28]
	cmp r2, #0
	beq _080077A2
_0800778A:
	adds r1, r2, #0
	adds r1, #0xb8
	ldr r4, [r1]
	ldrb r1, [r2, #5]
	cmp r1, r5
	bne _0800779C
	adds r0, r2, #0
	bl FUN_08005e90
_0800779C:
	adds r2, r4, #0
	cmp r2, #0
	bne _0800778A
_080077A2:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080077a8
FUN_080077a8: @ 0x080077A8
	push {lr}
	movs r0, #0x74
	movs r1, #0
	bl Script_GetKeywordValue
	bl FUN_08007770
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080077bc
FUN_080077bc: @ 0x080077BC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	bl FUN_0800708c
	adds r1, r0, #0
	cmp r1, #0
	bne _080077D4
	movs r0, #1
	rsbs r0, r0, #0
	b _08007816
_080077D4:
	ldr r2, [r1, #0x28]
	cmp r2, #0
	beq _08007816
	ldr r1, _0800781C @ =FUN_08006640
	mov ip, r1
_080077DE:
	adds r1, r2, #0
	adds r1, #0xb8
	ldr r4, [r1]
	ldrb r1, [r2, #5]
	cmp r1, #0
	bne _08007810
	ldrb r1, [r2, #0x14]
	cmp r1, #0
	beq _08007810
	movs r3, #0
	ldrsh r1, [r2, r3]
	cmp r1, r6
	bne _08007810
	movs r3, #2
	ldrsh r1, [r2, r3]
	cmp r1, r5
	bne _08007810
	ldr r1, [r2, #0x44]
	cmp r1, ip
	beq _08007810
	ldr r3, [r2, #0x2c]
	ldr r1, [r7]
	ldr r2, [r7, #4]
	str r1, [r3]
	str r2, [r3, #4]
_08007810:
	adds r2, r4, #0
	cmp r2, #0
	bne _080077DE
_08007816:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800781C: .4byte FUN_08006640

	thumb_func_start FUN_08007820
FUN_08007820: @ 0x08007820
	push {r4, r5, r6, lr}
	sub sp, #8
	movs r0, #0x6b
	movs r1, #0
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08007874
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08007888 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0800788C @ =0x0000FFFF
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
_08007874:
	mov r0, sp
	adds r1, r6, #0
	adds r2, r5, #0
	bl FUN_080077bc
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08007888: .4byte 0xFFFF0000
_0800788C: .4byte 0x0000FFFF

	thumb_func_start FUN_08007890
FUN_08007890: @ 0x08007890
	str r1, [r0, #0x1c]
	movs r1, #0
	str r1, [r0, #0x18]
	movs r1, #1
	strb r1, [r0, #3]
	bx lr

	thumb_func_start FUN_0800789c
FUN_0800789c: @ 0x0800789C
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #3]
	cmp r0, #0
	bne _080078AA
	movs r0, #0
	b _080078B0
_080078AA:
	movs r0, #0
	strb r0, [r1, #3]
	movs r0, #1
_080078B0:
	pop {r1}
	bx r1

	thumb_func_start FUN_080078b4
FUN_080078b4: @ 0x080078B4
	push {r4, r5, r6, lr}
	sub sp, #0x24
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	bl FUN_08236524
	ldrh r0, [r5, #4]
	ldrh r1, [r4, #0x3e]
	subs r0, r0, r1
	strh r0, [r5, #4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _080078E0
	movs r0, #0
	strh r0, [r5, #4]
	ldr r0, _080078DC @ =0x0000014F
	bl PlaySound_082406e0
	b _080078E8
	.align 2, 0
_080078DC: .4byte 0x0000014F
_080078E0:
	movs r0, #0xa7
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080078E8:
	movs r0, #4
	strb r0, [r5, #9]
	adds r0, r5, #0
	adds r0, #0x20
	movs r1, #0x99
	lsls r1, r1, #1
	bl FUN_0822b20c
	ldr r0, [r5, #0x10]
	ldr r1, [r5, #0x14]
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	add r0, sp, #0x1c
	ldrh r0, [r0]
	subs r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _08007958 @ =0xFFFF0000
	ldr r2, [sp, #0x1c]
	ands r2, r3
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0x80
	lsls r1, r1, #0x10
	ldr r0, _0800795C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r0, sp, #0x1c
	ldrh r0, [r0, #4]
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x20]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x20]
	adds r0, r6, #0
	adds r0, #0x42
	ldrb r0, [r0]
	adds r3, r0, #0
	adds r3, #0x80
	ldr r2, _08007960 @ =0x085B0A08
	adds r0, #0xc0
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	cmp r0, #0
	blt _08007964
	asrs r2, r0, #0xc
	b _0800796A
	.align 2, 0
_08007958: .4byte 0xFFFF0000
_0800795C: .4byte 0x0000FFFF
_08007960: .4byte 0x085B0A08
_08007964:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0800796A:
	add r0, sp, #0x1c
	ldrh r1, [r0]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08007998 @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x1c]
	ldr r1, _0800799C @ =0x085B0A08
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	cmp r0, #0
	blt _080079A0
	asrs r2, r0, #0xc
	b _080079A6
	.align 2, 0
_08007998: .4byte 0xFFFF0000
_0800799C: .4byte 0x085B0A08
_080079A0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080079A6:
	add r0, sp, #0x1c
	ldrh r1, [r0, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080079EC @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x20]
	movs r0, #0xa4
	str r0, [sp]
	movs r0, #0x10
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	movs r0, #3
	str r0, [sp, #0x10]
	movs r0, #0x1e
	str r0, [sp, #0x14]
	movs r0, #0xf
	str r0, [sp, #0x18]
	movs r0, #4
	movs r1, #3
	add r2, sp, #0x1c
	bl FUN_080149dc
	movs r0, #0xa
	strb r0, [r5, #0xb]
	add sp, #0x24
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080079EC: .4byte 0xFFFF0000

	thumb_func_start FUN_080079f0
FUN_080079f0: @ 0x080079F0
	push {r4, r5, lr}
	adds r4, r1, #0
	adds r5, r4, #0
	adds r5, #0x20
	ldr r1, _08007A20 @ =0x0000F680
	adds r0, r5, #0
	bl Video_GetActorSprite
	cmp r0, #0
	beq _08007A28
	adds r0, r4, #0
	adds r0, #0x3c
	adds r1, r5, #0
	movs r2, #1
	bl FUN_0822a470
	ldr r1, _08007A24 @ =FUN_08007a34
	adds r0, r4, #0
	bl FUN_08007890
	movs r0, #0
	strb r0, [r4, #2]
	b _08007A2C
	.align 2, 0
_08007A20: .4byte 0x0000F680
_08007A24: .4byte FUN_08007a34
_08007A28:
	movs r0, #1
	rsbs r0, r0, #0
_08007A2C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08007a34
FUN_08007a34: @ 0x08007A34
	push {lr}
	adds r0, r1, #0
	bl FUN_0800789c
	pop {r0}
	bx r0

	thumb_func_start FUN_08007a40
FUN_08007a40: @ 0x08007A40
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	mov sb, r1
	mov r0, sb
	bl FUN_0800789c
	mov r1, sb
	movs r2, #4
	ldrsh r0, [r1, r2]
	cmp r0, #0
	ble _08007A60
	b _08007B88
_08007A60:
	ldrh r0, [r1, #0xc]
	cmp r0, #0
	beq _08007A84
	ldrh r0, [r1]
	str r0, [sp, #0x20]
	ldr r1, _08007B7C @ =0xFFFF0000
	ldr r0, [sp, #0x24]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #0x24]
	add r1, sp, #0x24
	add r0, sp, #0x20
	str r0, [r1, #4]
	mov r2, sb
	ldrh r0, [r2, #0xc]
	bl Script_ExecById
_08007A84:
	mov r0, sb
	ldrb r1, [r0, #0xa]
	adds r0, #0x3c
	strh r1, [r0, #0x10]
	mov r2, sb
	adds r2, #0x6e
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08007B80 @ =FUN_08007a34
	mov r0, sb
	bl FUN_08007890
	mov r0, sb
	adds r0, #0x20
	movs r1, #6
	bl FUN_0822b20c
	mov r2, sb
	ldr r0, [r2, #0x10]
	ldr r1, [r2, #0x14]
	str r0, [sp, #0x2c]
	str r1, [sp, #0x30]
	add r5, sp, #0x2c
	ldrh r0, [r5]
	subs r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _08007B7C @ =0xFFFF0000
	ldr r1, [sp, #0x2c]
	ands r1, r3
	orrs r1, r0
	lsrs r2, r1, #0x10
	lsls r2, r2, #0x10
	ldr r0, _08007B84 @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x2c]
	ldrh r0, [r5, #4]
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r5, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [r5, #4]
	movs r0, #0x80
	lsls r0, r0, #6
	mov sl, r0
	movs r1, #0
	str r1, [sp]
	movs r6, #0x80
	lsls r6, r6, #1
	str r6, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r7, #3
	str r7, [sp, #0xc]
	movs r2, #0xc
	mov sb, r2
	str r2, [sp, #0x10]
	movs r0, #6
	str r0, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #4
	movs r1, #1
	mov r2, sl
	movs r3, #0x40
	bl FUN_08015ce0
	movs r1, #0
	str r1, [sp]
	str r6, [sp, #4]
	movs r4, #4
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r2, #0xa
	mov r8, r2
	str r2, [sp, #0x10]
	str r4, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #6
	movs r1, #1
	mov r2, sl
	movs r3, #0x40
	bl FUN_08015ce0
	str r6, [sp]
	movs r0, #0x10
	str r0, [sp, #4]
	str r4, [sp, #8]
	mov r0, sb
	str r0, [sp, #0xc]
	str r7, [sp, #0x10]
	movs r0, #0x1e
	str r0, [sp, #0x14]
	movs r0, #0xf
	str r0, [sp, #0x18]
	movs r0, #4
	movs r1, #3
	adds r2, r5, #0
	movs r3, #0
	bl FUN_080149dc
	movs r0, #0x14
	str r0, [sp]
	str r4, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	movs r2, #6
	str r2, [sp, #0xc]
	movs r1, #0
	str r1, [sp, #0x10]
	str r6, [sp, #0x14]
	str r0, [sp, #0x18]
	str r4, [sp, #0x1c]
	movs r0, #4
	movs r1, #6
	adds r2, r5, #0
	movs r3, #0
	bl FUN_08014da0
	b _08007C1E
	.align 2, 0
_08007B7C: .4byte 0xFFFF0000
_08007B80: .4byte FUN_08007a34
_08007B84: .4byte 0x0000FFFF
_08007B88:
	mov r2, sb
	ldrb r0, [r2, #9]
	cmp r0, #0
	beq _08007BA4
	subs r0, #1
	strb r0, [r2, #9]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08007BA4
	mov r0, sb
	adds r0, #0x20
	movs r1, #6
	bl FUN_0822b20c
_08007BA4:
	mov r1, sb
	ldrb r0, [r1, #0xb]
	cmp r0, #0
	beq _08007C1E
	subs r0, #1
	strb r0, [r1, #0xb]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08007BC8
	mov r2, sb
	adds r2, #0x6e
	ldrh r1, [r2]
	ldr r0, _08007BC4 @ =0x0000FFFB
	ands r0, r1
	b _08007BD2
	.align 2, 0
_08007BC4: .4byte 0x0000FFFB
_08007BC8:
	mov r2, sb
	adds r2, #0x6e
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
_08007BD2:
	strh r0, [r2]
	mov r2, sb
	ldr r0, [r2, #0x10]
	ldr r1, [r2, #0x14]
	str r0, [r2, #0x58]
	str r1, [r2, #0x5c]
	ldr r0, _08007C30 @ =0x0203B400
	mov r8, r0
	ldr r4, _08007C34 @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r6, _08007C38 @ =0x000003FF
	ands r1, r6
	str r1, [r4]
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	mov r3, sb
	adds r3, #0x58
	ldrh r0, [r3]
	subs r0, #8
	movs r5, #0xf
	ands r2, r5
	adds r0, r0, r2
	strh r0, [r3]
	adds r1, #1
	ands r1, r6
	str r1, [r4]
	lsls r1, r1, #1
	add r1, r8
	ldrh r1, [r1]
	mov r2, sb
	adds r2, #0x5c
	ldrh r0, [r2]
	subs r0, #8
	ands r1, r5
	adds r0, r0, r1
	strh r0, [r2]
_08007C1E:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08007C30: .4byte 0x0203B400
_08007C34: .4byte 0x030046B8
_08007C38: .4byte 0x000003FF

	thumb_func_start FUN_08007c3c
FUN_08007c3c: @ 0x08007C3C
	push {r4, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	adds r0, #0x68
	bl FUN_08236424
	adds r4, #0x3c
	adds r0, r4, #0
	bl FUN_0822a4e0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityED07_Update
EntityED07_Update: @ 0x08007C58
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, [r6, #0x1c]
	cmp r1, #0
	beq _08007C86
	adds r4, r1, #0
	movs r5, #0
	b _08007C80
_08007C68:
	ldrb r0, [r4, #2]
	cmp r0, #0
	beq _08007C7C
	ldr r2, [r4, #0x1c]
	cmp r2, #0
	beq _08007C7C
	adds r0, r6, #0
	adds r1, r4, #0
	bl _call_via_r2
_08007C7C:
	adds r5, #1
	adds r4, #0xb8
_08007C80:
	ldr r0, [r6, #0x18]
	cmp r5, r0
	blt _08007C68
_08007C86:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityED07_Destroy
EntityED07_Destroy: @ 0x08007C90
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x1c]
	cmp r1, #0
	beq _08007CBC
	adds r5, r1, #0
	movs r6, #0
	b _08007CAC
_08007CA0:
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08007c3c
	adds r6, #1
	adds r5, #0xb8
_08007CAC:
	ldr r0, [r4, #0x18]
	cmp r6, r0
	blt _08007CA0
	ldr r0, [r4, #0x1c]
	bl Free
	movs r0, #0
	str r0, [r4, #0x1c]
_08007CBC:
	ldr r1, _08007CC8 @ =0x03000030
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08007CC8: .4byte 0x03000030

	thumb_func_start EntityED07_Init
EntityED07_Init: @ 0x08007CCC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _08007CF8 @ =0x03000030
	str r5, [r0]
	movs r0, #0x6e
	movs r1, #4
	bl Script_GetKeywordValue
	str r0, [r5, #0x18]
	movs r1, #0xb8
	adds r4, r0, #0
	muls r4, r1, r4
	adds r0, r4, #0
	bl Malloc
	str r0, [r5, #0x1c]
	cmp r0, #0
	bne _08007CFC
	movs r0, #1
	rsbs r0, r0, #0
	bl exit
	.align 2, 0
_08007CF8: .4byte 0x03000030
_08007CFC:
	adds r1, r4, #0
	bl ClearMemory
	ldr r4, [r5, #0x1c]
	movs r6, #0
	b _08007D14
_08007D08:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080079f0
	adds r6, #1
	adds r4, #0xb8
_08007D14:
	ldr r0, [r5, #0x18]
	cmp r6, r0
	blt _08007D08
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityED07_Create
EntityED07_Create: @ 0x08007D24
	push {r4, lr}
	ldr r0, _08007D58 @ =0x03000030
	ldr r0, [r0]
	cmp r0, #0
	bne _08007D66
	movs r0, #8
	movs r1, #0x20
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08007D64
	ldr r1, _08007D5C @ =EntityED07_Update
	ldr r2, _08007D60 @ =EntityED07_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityED07_Init
	cmp r0, #0
	bge _08007D64
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08007D66
	.align 2, 0
_08007D58: .4byte 0x03000030
_08007D5C: .4byte EntityED07_Update
_08007D60: .4byte EntityED07_Destroy
_08007D64:
	adds r0, r4, #0
_08007D66:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08007d6c
FUN_08007d6c: @ 0x08007D6C
	push {lr}
	ldr r1, [r0, #0x1c]
	movs r2, #0
	ldr r0, [r0, #0x18]
	cmp r2, r0
	bge _08007D8C
	adds r3, r0, #0
_08007D7A:
	ldrb r0, [r1, #2]
	cmp r0, #0
	bne _08007D84
	adds r0, r1, #0
	b _08007D8E
_08007D84:
	adds r2, #1
	adds r1, #0xb8
	cmp r2, r3
	blt _08007D7A
_08007D8C:
	movs r0, #0
_08007D8E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08007d94
FUN_08007d94: @ 0x08007D94
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	ldr r0, _08007E3C @ =0x03000030
	ldr r0, [r0]
	cmp r0, #0
	beq _08007E36
	bl FUN_08007d6c
	adds r6, r0, #0
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	movs r1, #0
	mov sb, r1
	movs r4, #0
	strh r0, [r6]
	mov r0, sb
	strb r0, [r6, #9]
	movs r0, #0x6c
	movs r1, #0xa
	bl Script_GetKeywordValue
	strh r0, [r6, #4]
	strh r4, [r6, #6]
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08007DE8
	bl Script_GetValue
	strh r0, [r6, #0x10]
	bl Script_GetValue
	strh r0, [r6, #0x12]
	bl Script_GetValue
	strh r0, [r6, #0x14]
_08007DE8:
	ldr r1, _08007E40 @ =0x0000F680
	movs r0, #0x74
	bl Script_GetKeywordValue
	adds r4, r0, #0
	movs r0, #0x50
	movs r1, #0
	bl Script_GetKeywordValue
	mov r8, r0
	movs r0, #0x6b
	movs r1, #0
	bl Script_GetKeywordValue
	strb r0, [r6, #8]
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r6, #0xc]
	adds r5, r6, #0
	adds r5, #0x3c
	ldr r0, [r6, #0x3c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x3c]
	ldr r0, [r6, #0x10]
	ldr r1, [r6, #0x14]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	adds r7, r6, #0
	adds r7, #0x20
	adds r0, r7, #0
	adds r1, r4, #0
	bl Video_GetActorSprite
	cmp r0, #0
	bne _08007E44
_08007E36:
	movs r0, #1
	rsbs r0, r0, #0
	b _08007EDA
	.align 2, 0
_08007E3C: .4byte 0x03000030
_08007E40: .4byte 0x0000F680
_08007E44:
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_0822a4fc
	mov r1, r8
	strh r1, [r5, #0x10]
	movs r0, #2
	strb r0, [r5, #7]
	ldr r1, _08007EE8 @ =FUN_08007a40
	adds r0, r6, #0
	bl FUN_08007890
	mov r0, r8
	adds r0, #1
	strb r0, [r6, #0xa]
	mov r0, sb
	strb r0, [r6, #9]
	adds r5, r6, #0
	adds r5, #0x68
	ldr r2, _08007EEC @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r4, #0x80
	orrs r0, r4
	ldr r3, _08007EF0 @ =0x0000FFFF
	ands r0, r3
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r4
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	ldr r1, _08007EF4 @ =0x0000FF80
	orrs r0, r1
	ands r0, r3
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r4
	str r0, [r3, #4]
	ldrh r1, [r6]
	ldr r2, _08007EF8 @ =0x00004001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r1, _08007EFC @ =FUN_080078b4
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_0823651c
	adds r1, r6, #0
	adds r1, #0x10
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	bl FUN_08236400
	movs r1, #1
	strb r1, [r6, #2]
_08007EDA:
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08007EE8: .4byte FUN_08007a40
_08007EEC: .4byte 0xFFFF0000
_08007EF0: .4byte 0x0000FFFF
_08007EF4: .4byte 0x0000FF80
_08007EF8: .4byte 0x00004001
_08007EFC: .4byte FUN_080078b4

	thumb_func_start FUN_08007f00
FUN_08007f00: @ 0x08007F00
	push {lr}
	ldr r1, [r0, #0x1c]
	movs r2, #0
	ldr r0, [r0, #0x18]
	cmp r2, r0
	bhs _08007F20
	adds r3, r0, #0
_08007F0E:
	ldrb r0, [r1]
	cmp r0, #0
	bne _08007F18
	adds r0, r1, #0
	b _08007F22
_08007F18:
	adds r2, #1
	adds r1, #0xe8
	cmp r2, r3
	blo _08007F0E
_08007F20:
	movs r0, #0
_08007F22:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08007f28
FUN_08007f28: @ 0x08007F28
	movs r2, #0
	strb r1, [r0, #2]
	str r2, [r0, #0xc]
	movs r1, #1
	strb r1, [r0, #4]
	bx lr

	thumb_func_start FUN_08007f34
FUN_08007f34: @ 0x08007F34
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #4]
	cmp r0, #0
	bne _08007F42
	movs r0, #0
	b _08007F48
_08007F42:
	movs r0, #0
	strb r0, [r1, #4]
	movs r0, #1
_08007F48:
	pop {r1}
	bx r1

	thumb_func_start FUN_08007f4c
FUN_08007f4c: @ 0x08007F4C
	push {lr}
	adds r3, r2, #0
	ldrb r1, [r2, #2]
	cmp r1, #1
	bne _08007F6A
	movs r1, #4
	ldr r0, [r0, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _08007F80
	adds r0, r2, #0
	movs r1, #3
	bl FUN_08007f28
	b _08007F80
_08007F6A:
	cmp r1, #2
	bne _08007F80
	movs r1, #8
	ldr r0, [r0, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _08007F80
	adds r0, r3, #0
	movs r1, #4
	bl FUN_08007f28
_08007F80:
	pop {r0}
	bx r0

	thumb_func_start FUN_08007f84
FUN_08007f84: @ 0x08007F84
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x2c
	adds r4, r0, #0
	adds r7, r1, #0
	movs r0, #0xe4
	adds r0, r0, r7
	mov sb, r0
	adds r4, #0x20
	str r4, [r0]
	add r5, sp, #0x14
	movs r0, #0
	mov r8, r0
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _0800804C @ =0x05000002
	bl CpuSet
	adds r6, r7, #0
	adds r6, #0x34
	movs r0, #2
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	movs r3, #1
	bl FUN_0822f4d8
	mov r0, sb
	ldr r1, [r0]
	mov r0, r8
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	adds r5, r7, #0
	adds r5, #0x94
	ldr r2, _08008050 @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	movs r3, #0x80
	orrs r0, r3
	ldr r1, _08008054 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r4, sp, #0x1c
	ldr r0, [r4, #4]
	ands r0, r2
	orrs r0, r3
	str r0, [r4, #4]
	str r1, [sp, #0x24]
	add r3, sp, #0x24
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	ldrh r1, [r7, #0x10]
	ldr r2, _08008058 @ =0x00004001
	mov r0, r8
	str r0, [sp]
	str r4, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r1, _0800805C @ =FUN_08007f4c
	adds r0, r5, #0
	adds r2, r7, #0
	bl FUN_0823651c
	adds r1, r7, #0
	adds r1, #0x54
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	bl FUN_08236400
	movs r0, #0
	add sp, #0x2c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800804C: .4byte 0x05000002
_08008050: .4byte 0xFFFF0000
_08008054: .4byte 0x0000FFFF
_08008058: .4byte 0x00004001
_0800805C: .4byte FUN_08007f4c

	thumb_func_start FUN_08008060
FUN_08008060: @ 0x08008060
	push {lr}
	sub sp, #0x14
	adds r2, r0, #0
	ldrh r0, [r2, #0x12]
	cmp r0, #0
	beq _0800809E
	ldrh r0, [r2, #0x10]
	str r0, [sp]
	ldrb r0, [r2, #2]
	cmp r0, #3
	bne _0800807A
	movs r0, #1
	b _08008080
_0800807A:
	cmp r0, #4
	bne _08008082
	movs r0, #0
_08008080:
	str r0, [sp, #4]
_08008082:
	ldr r0, [r2, #0x1c]
	str r0, [sp, #8]
	ldr r1, _080080A4 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r1
	movs r1, #3
	orrs r0, r1
	str r0, [sp, #0xc]
	add r1, sp, #0xc
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r2, #0x12]
	bl Script_ExecById
_0800809E:
	add sp, #0x14
	pop {r0}
	bx r0
	.align 2, 0
_080080A4: .4byte 0xFFFF0000

	thumb_func_start FUN_080080a8
FUN_080080a8: @ 0x080080A8
	bx lr
	.align 2, 0

	thumb_func_start FUN_080080ac
FUN_080080ac: @ 0x080080AC
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r1, #0
	adds r0, r5, #0
	bl FUN_08007f34
	cmp r0, #0
	beq _080080EE
	adds r4, r5, #0
	adds r4, #0x34
	adds r0, r5, #0
	adds r0, #0xe4
	ldr r1, [r0]
	ldr r2, _080080F8 @ =0x085AA670
	ldr r0, [r5, #0x18]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r1, _080080FC @ =0x085AA678
	ldr r0, [r5, #0x18]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	adds r0, r4, #0
	bl Sprite_SetPlttID
_080080EE:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080080F8: .4byte 0x085AA670
_080080FC: .4byte 0x085AA678

	thumb_func_start FUN_08008100
FUN_08008100: @ 0x08008100
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r1, #0
	adds r0, r5, #0
	bl FUN_08007f34
	cmp r0, #0
	beq _08008142
	adds r4, r5, #0
	adds r4, #0x34
	adds r0, r5, #0
	adds r0, #0xe4
	ldr r1, [r0]
	ldr r2, _08008164 @ =0x085AA670
	ldr r0, [r5, #0x18]
	lsls r0, r0, #2
	adds r2, #2
	adds r0, r0, r2
	ldrh r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r1, _08008168 @ =0x085AA678
	ldr r0, [r5, #0x18]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl Sprite_SetPlttID
_08008142:
	movs r1, #8
	ldrsh r0, [r5, r1]
	cmp r0, #0
	blt _0800815A
	adds r1, r0, #0
	ldr r0, [r5, #0xc]
	cmp r0, r1
	blt _0800815A
	adds r0, r5, #0
	movs r1, #4
	bl FUN_08007f28
_0800815A:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08008164: .4byte 0x085AA670
_08008168: .4byte 0x085AA678

	thumb_func_start FUN_0800816c
FUN_0800816c: @ 0x0800816C
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r1, #0
	adds r0, r5, #0
	bl FUN_08007f34
	cmp r0, #0
	beq _080081BE
	adds r4, r5, #0
	adds r4, #0x34
	adds r0, r5, #0
	adds r0, #0xe4
	ldr r1, [r0]
	ldr r2, _080081D4 @ =0x085AA670
	ldr r0, [r5, #0x18]
	lsls r0, r0, #2
	adds r2, #2
	adds r0, r0, r2
	ldrh r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r1, _080081D8 @ =0x085AA678
	ldr r0, [r5, #0x18]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl Sprite_SetPlttID
	movs r0, #0xa
	strb r0, [r5, #5]
	ldr r0, _080081DC @ =0x0000014B
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_08008060
_080081BE:
	ldr r0, [r5, #0xc]
	cmp r0, #0xa
	ble _080081CC
	adds r0, r5, #0
	movs r1, #2
	bl FUN_08007f28
_080081CC:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080081D4: .4byte 0x085AA670
_080081D8: .4byte 0x085AA678
_080081DC: .4byte 0x0000014B

	thumb_func_start FUN_080081e0
FUN_080081e0: @ 0x080081E0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r7, r1, #0
	adds r0, r7, #0
	bl FUN_08007f34
	cmp r0, #0
	bne _080081FA
	b _080082FE
_080081FA:
	adds r5, r7, #0
	adds r5, #0x34
	adds r0, r7, #0
	adds r0, #0xe4
	ldr r1, [r0]
	ldr r2, _0800831C @ =0x085AA670
	ldr r0, [r7, #0x18]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r2, [r0]
	movs r4, #0
	str r4, [sp]
	adds r0, r5, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r1, _08008320 @ =0x085AA678
	ldr r0, [r7, #0x18]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	adds r0, r5, #0
	bl Sprite_SetPlttID
	movs r0, #0xa
	strb r0, [r7, #5]
	adds r0, r7, #0
	bl FUN_08008060
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	adds r6, r7, #0
	adds r6, #0x54
	ldr r2, _08008324 @ =0xFFFF0000
	movs r0, #0x56
	adds r0, r0, r7
	mov sl, r0
	movs r3, #0xc8
	lsls r3, r3, #1
	adds r1, r3, #0
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldrh r0, [r6]
	orrs r0, r1
	str r0, [sp, #0x1c]
	movs r1, #0x58
	adds r1, r1, r7
	mov sb, r1
	ldrh r1, [r1]
	add r5, sp, #0x1c
	ldr r0, [sp, #0x20]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x20]
	str r4, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r3, #4
	str r3, [sp, #0x10]
	movs r0, #2
	mov r8, r0
	str r0, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #1
	movs r1, #2
	ldr r2, _08008328 @ =0x00002001
	movs r3, #0x40
	bl FUN_08015ce0
	ldrh r0, [r6]
	subs r0, #0x40
	add r1, sp, #0x1c
	strh r0, [r1]
	mov r1, sl
	ldrh r0, [r1]
	adds r0, #0xc0
	strh r0, [r5, #2]
	mov r3, sb
	ldrh r0, [r3]
	adds r0, #0x40
	strh r0, [r5, #4]
	str r4, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #4
	str r0, [sp, #0x10]
	mov r1, r8
	str r1, [sp, #0x14]
	add r3, sp, #0x1c
	str r3, [sp, #0x18]
	movs r0, #1
	movs r1, #2
	ldr r2, _08008328 @ =0x00002001
	movs r3, #0x40
	bl FUN_08015ce0
	ldrh r0, [r6]
	adds r0, #0x40
	add r1, sp, #0x1c
	strh r0, [r1]
	mov r1, sl
	ldrh r0, [r1]
	adds r0, #0xc0
	strh r0, [r5, #2]
	mov r3, sb
	ldrh r0, [r3]
	subs r0, #0x40
	strh r0, [r5, #4]
	str r4, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #4
	str r0, [sp, #0x10]
	mov r1, r8
	str r1, [sp, #0x14]
	add r3, sp, #0x1c
	str r3, [sp, #0x18]
	movs r0, #1
	movs r1, #2
	ldr r2, _08008328 @ =0x00002001
	movs r3, #0x40
	bl FUN_08015ce0
_080082FE:
	ldr r0, [r7, #0xc]
	cmp r0, #0xa
	ble _0800830C
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08007f28
_0800830C:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800831C: .4byte 0x085AA670
_08008320: .4byte 0x085AA678
_08008324: .4byte 0xFFFF0000
_08008328: .4byte 0x00002001

	thumb_func_start FUN_0800832c
FUN_0800832c: @ 0x0800832C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x28
	ldrh r0, [r4, #0xa]
	cmp r0, #0
	beq _08008342
	subs r0, #1
	strh r0, [r4, #0xa]
	b _08008388
_08008342:
	adds r6, r4, #0
	adds r6, #0x54
	add r7, sp, #0x10
	ldrh r0, [r4, #0x26]
	str r0, [sp]
	str r0, [sp, #4]
	ldrh r0, [r4, #0x24]
	str r0, [sp, #8]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r7, #0
	add r3, sp, #0xc
	bl FUN_08234e78
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08008374
	adds r0, r5, #0
	bl FUN_08234e3c
	ldr r0, [r5, #8]
	ldrh r1, [r0, #4]
	ldr r0, _08008390 @ =0x00000FFF
	ands r0, r1
	strh r0, [r4, #0xa]
_08008374:
	ldrh r0, [r7]
	ldrh r1, [r6]
	adds r0, r0, r1
	strh r0, [r6]
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r0, [r7, #4]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
_08008388:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08008390: .4byte 0x00000FFF

	thumb_func_start FUN_08008394
FUN_08008394: @ 0x08008394
	push {lr}
	adds r2, r0, #0
	ldr r3, [r2, #0x20]
	cmp r3, #0
	beq _080083B8
	ldrh r1, [r3]
	adds r0, #0x54
	strh r1, [r0]
	ldrh r0, [r2, #6]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	adds r1, r2, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r3, #4]
	adds r0, r2, #0
	adds r0, #0x58
	strh r1, [r0]
_080083B8:
	pop {r0}
	bx r0

	thumb_func_start Entity2D2B_Update
Entity2D2B_Update: @ 0x080083BC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r4, [r7, #0x1c]
	movs r1, #0
	mov r8, r1
	ldr r1, [r7, #0x18]
	cmp r8, r1
	bhs _080084AC
	adds r6, r4, #0
	adds r6, #0x94
_080083D4:
	ldrb r1, [r4]
	adds r5, r4, #0
	adds r5, #0x9a
	cmp r1, #0
	beq _0800849E
	ldr r2, [r4, #0x14]
	cmp r2, #0
	blt _08008414
	ldr r1, _080083F8 @ =0x030046A0
	ldr r1, [r1]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r1, r1, r3
	ldr r1, [r1]
	cmp r1, r2
	bne _080083FC
	movs r1, #1
	b _080083FE
	.align 2, 0
_080083F8: .4byte 0x030046A0
_080083FC:
	movs r1, #0
_080083FE:
	cmp r1, #0
	bne _08008414
	ldr r1, [r4, #0x3c]
	movs r2, #1
	orrs r1, r2
	str r1, [r4, #0x3c]
	ldrh r2, [r6, #6]
	movs r1, #4
	orrs r1, r2
	strh r1, [r6, #6]
	b _0800849E
_08008414:
	ldr r0, [r4, #0x3c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x3c]
	ldrh r0, [r6, #6]
	ldr r2, _08008448 @ =0x0000FFFB
	adds r1, r2, #0
	ands r0, r1
	strh r0, [r6, #6]
	ldr r1, _0800844C @ =0x085AA67C
	ldrb r0, [r4, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	bl _call_via_r2
	ldrb r0, [r4, #1]
	cmp r0, #1
	bne _08008450
	adds r0, r4, #0
	bl FUN_0800832c
	b _0800845A
	.align 2, 0
_08008448: .4byte 0x0000FFFB
_0800844C: .4byte 0x085AA67C
_08008450:
	cmp r0, #2
	bne _0800845A
	adds r0, r4, #0
	bl FUN_08008394
_0800845A:
	adds r0, r4, #0
	adds r0, #0x34
	ldr r1, [r6, #0x50]
	bl FUN_082372cc
	adds r1, r4, #0
	adds r1, #0x54
	adds r0, r6, #0
	movs r2, #0
	bl FUN_082364c4
	ldrb r1, [r4, #5]
	cmp r1, #0
	beq _08008498
	subs r1, #1
	strb r1, [r4, #5]
	lsls r1, r1, #0x18
	cmp r1, #0
	bne _08008490
	ldrh r1, [r5]
	ldr r3, _0800848C @ =0x0000FFFB
	adds r2, r3, #0
	ands r1, r2
	b _08008496
	.align 2, 0
_0800848C: .4byte 0x0000FFFB
_08008490:
	ldrh r2, [r5]
	movs r1, #4
	orrs r1, r2
_08008496:
	strh r1, [r5]
_08008498:
	ldr r1, [r4, #0xc]
	adds r1, #1
	str r1, [r4, #0xc]
_0800849E:
	movs r1, #1
	add r8, r1
	adds r6, #0xe8
	adds r4, #0xe8
	ldr r1, [r7, #0x18]
	cmp r8, r1
	blo _080083D4
_080084AC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity2D2B_Destroy
Entity2D2B_Destroy: @ 0x080084B8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r4, [r6, #0x1c]
	movs r5, #0
	b _080084DC
_080084C2:
	ldrb r1, [r4]
	cmp r1, #0
	beq _080084D8
	adds r0, r4, #0
	adds r0, #0x94
	bl FUN_08236424
	adds r0, r4, #0
	adds r0, #0x34
	bl FUN_0822f1c0
_080084D8:
	adds r5, #1
	adds r4, #0xe8
_080084DC:
	ldr r1, [r6, #0x18]
	cmp r5, r1
	blo _080084C2
	ldr r1, [r6, #0x1c]
	cmp r1, #0
	beq _080084F2
	adds r0, r1, #0
	bl Free
	movs r1, #0
	str r1, [r6, #0x1c]
_080084F2:
	ldr r2, _08008500 @ =0x03000034
	movs r1, #0
	str r1, [r2]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08008500: .4byte 0x03000034

	thumb_func_start Entity2D2B_Init
Entity2D2B_Init: @ 0x08008504
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	ldr r0, _08008538 @ =0x03000034
	str r6, [r0]
	movs r5, #0
	movs r0, #0x20
	adds r0, r0, r6
	mov r8, r0
	mov sb, r6
_0800851C:
	ldr r0, _0800853C @ =0x085AA66C
	lsls r1, r5, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	ldr r0, _08008540 @ =0x0000CB05
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _08008544
	movs r0, #1
	rsbs r0, r0, #0
	b _080085A2
	.align 2, 0
_08008538: .4byte 0x03000034
_0800853C: .4byte 0x085AA66C
_08008540: .4byte 0x0000CB05
_08008544:
	mov r1, sb
	adds r1, #0x20
	adds r0, r2, #0
	ldm r0!, {r3, r4, r7}
	stm r1!, {r3, r4, r7}
	ldm r0!, {r3, r4, r7}
	stm r1!, {r3, r4, r7}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	mov r0, r8
	adds r1, r2, #0
	bl OpenSpriteSetFile
	movs r7, #0x20
	add r8, r7
	movs r0, #0x20
	add sb, r0
	adds r5, #1
	cmp r5, #1
	ble _0800851C
	movs r0, #0x6e
	movs r1, #8
	bl Script_GetKeywordValue
	str r0, [r6, #0x18]
	movs r1, #0xe8
	adds r4, r0, #0
	muls r4, r1, r4
	adds r0, r4, #0
	bl Malloc
	str r0, [r6, #0x1c]
	adds r1, r4, #0
	bl ClearMemory
	ldr r4, [r6, #0x1c]
	movs r5, #0
	b _0800859C
_08008590:
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_08007f84
	adds r5, #1
	adds r4, #0xe8
_0800859C:
	ldr r1, [r6, #0x18]
	cmp r5, r1
	blo _08008590
_080085A2:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity2D2B_Create
Entity2D2B_Create: @ 0x080085B0
	push {r4, lr}
	ldr r0, _080085E4 @ =0x03000034
	ldr r0, [r0]
	cmp r0, #0
	bne _080085F2
	movs r0, #0xa
	movs r1, #0x60
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080085F0
	ldr r1, _080085E8 @ =Entity2D2B_Update
	ldr r2, _080085EC @ =Entity2D2B_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity2D2B_Init
	cmp r0, #0
	bge _080085F0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080085F2
	.align 2, 0
_080085E4: .4byte 0x03000034
_080085E8: .4byte Entity2D2B_Update
_080085EC: .4byte Entity2D2B_Destroy
_080085F0:
	adds r0, r4, #0
_080085F2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080085f8
FUN_080085f8: @ 0x080085F8
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	ldr r0, _080086C8 @ =0x03000034
	ldr r7, [r0]
	cmp r7, #0
	beq _080086C2
	adds r0, r7, #0
	bl FUN_08007f00
	adds r6, r0, #0
	cmp r6, #0
	beq _080086C2
	movs r0, #0
	strb r0, [r6, #1]
	movs r4, #0
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _0800866A
	bl Script_GetValue
	adds r5, r0, #0
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	adds r3, r0, #0
	adds r0, r6, #0
	adds r0, #0x28
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08234de8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080086C2
	movs r0, #1
	strb r0, [r6, #1]
	ldr r0, [r6, #0x30]
	ldrh r1, [r0, #4]
	ldr r0, _080086CC @ =0x00000FFF
	ands r0, r1
	strh r0, [r6, #0xa]
	bl Script_GetValue
	strh r0, [r6, #0x24]
	bl Script_GetValue
	strh r0, [r6, #0x26]
	ldr r1, [r6, #0x30]
	add r0, sp, #4
	movs r2, #0
	bl FUN_08234f80
	movs r4, #1
_0800866A:
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _0800869C
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	strh r0, [r6, #6]
	adds r0, r4, #0
	bl FUN_081d553c
	adds r1, r0, #0
	str r1, [r6, #0x20]
	cmp r1, #0
	beq _080086C2
	movs r0, #2
	strb r0, [r6, #1]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r4, #1
_0800869C:
	movs r0, #0x50
	bl prepare_08231510
	cmp r0, #0
	beq _080086BE
	bl Script_GetValue
	add r1, sp, #4
	strh r0, [r1]
	bl Script_GetValue
	add r4, sp, #4
	strh r0, [r4, #2]
	bl Script_GetValue
	strh r0, [r4, #4]
	movs r4, #1
_080086BE:
	cmp r4, #0
	bne _080086D0
_080086C2:
	movs r0, #1
	rsbs r0, r0, #0
	b _08008860
	.align 2, 0
_080086C8: .4byte 0x03000034
_080086CC: .4byte 0x00000FFF
_080086D0:
	movs r0, #0x6d
	movs r1, #1
	bl Script_GetKeywordValue
	adds r1, r0, #0
	adds r0, r6, #0
	bl FUN_08007f28
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	strb r0, [r6, #3]
	movs r0, #0x64
	movs r1, #0x78
	bl Script_GetKeywordValue
	strh r0, [r6, #8]
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r6, #0x10]
	movs r0, #0x44
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [r6, #0x18]
	adds r4, r6, #0
	adds r4, #0xe4
	lsls r0, r0, #5
	adds r0, #0x20
	adds r0, r7, r0
	str r0, [r4]
	movs r0, #0x70
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r6, #0x12]
	movs r0, #0x61
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [r6, #0x1c]
	ldrb r0, [r6, #1]
	adds r7, r4, #0
	cmp r0, #2
	beq _080087B8
	add r5, sp, #4
	adds r0, r5, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08008758
	cmp r1, #0
	blt _08008758
	ldr r0, _0800875C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08008758
	ldr r0, _08008760 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08008764
_08008758:
	movs r4, #0
	b _08008772
	.align 2, 0
_0800875C: .4byte 0x030046A8
_08008760: .4byte 0x030046AC
_08008764:
	ldr r0, _08008784 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08008772:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08008788
	adds r0, #4
	b _08008794
	.align 2, 0
_08008784: .4byte 0x030046A4
_08008788:
	ldr r0, _080087A8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08008794:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080087AC
	cmp r2, #2
	beq _080087B0
	b _080087B4
	.align 2, 0
_080087A8: .4byte 0x030046A4
_080087AC:
	ldrb r0, [r5, #4]
	b _080087B2
_080087B0:
	ldrb r0, [r5]
_080087B2:
	subs r1, r1, r0
_080087B4:
	add r0, sp, #4
	strh r1, [r0, #2]
_080087B8:
	movs r0, #0x4d
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _080087CC
	add r0, sp, #4
	bl FUN_08241574
	b _080087D0
_080087CC:
	movs r0, #1
	rsbs r0, r0, #0
_080087D0:
	str r0, [r6, #0x14]
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	str r0, [r6, #0x54]
	str r1, [r6, #0x58]
	ldr r0, [r6, #0x3c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x3c]
	ldrb r0, [r6, #2]
	cmp r0, #1
	bne _08008824
	adds r4, r6, #0
	adds r4, #0x34
	ldr r1, [r7]
	ldr r2, _0800881C @ =0x085AA670
	ldr r0, [r6, #0x18]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r1, _08008820 @ =0x085AA678
	ldr r0, [r6, #0x18]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	adds r0, r4, #0
	bl Sprite_SetPlttID
	b _08008852
	.align 2, 0
_0800881C: .4byte 0x085AA670
_08008820: .4byte 0x085AA678
_08008824:
	adds r4, r6, #0
	adds r4, #0x34
	ldr r1, [r7]
	ldr r2, _08008868 @ =0x085AA670
	ldr r0, [r6, #0x18]
	lsls r0, r0, #2
	adds r2, #2
	adds r0, r0, r2
	ldrh r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r1, _0800886C @ =0x085AA678
	ldr r0, [r6, #0x18]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl Sprite_SetPlttID
_08008852:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0822a3f0
	movs r0, #1
	strb r0, [r6]
	movs r0, #0
_08008860:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08008868: .4byte 0x085AA670
_0800886C: .4byte 0x085AA678

	thumb_func_start FUN_08008870
FUN_08008870: @ 0x08008870
	push {r4, r5, lr}
	ldr r0, _08008898 @ =0x03000034
	ldr r4, [r0]
	cmp r4, #0
	beq _080088B4
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0x64
	bl Script_GetKeywordValue
	adds r3, r0, #0
	ldr r1, [r4, #0x1c]
	movs r2, #0
	b _080088AE
	.align 2, 0
_08008898: .4byte 0x03000034
_0800889C:
	ldrb r0, [r1]
	cmp r0, #1
	bne _080088AA
	ldrh r0, [r1, #0x10]
	cmp r0, r5
	bne _080088AA
	strh r3, [r1, #8]
_080088AA:
	adds r2, #1
	adds r1, #0xe8
_080088AE:
	ldr r0, [r4, #0x18]
	cmp r2, r0
	blo _0800889C
_080088B4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080088bc
FUN_080088bc: @ 0x080088BC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _080088F0 @ =0x03000034
	ldr r7, [r0]
	cmp r7, #0
	beq _08008912
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	mov r8, r0
	movs r4, #1
	rsbs r4, r4, #0
	movs r0, #0x6d
	adds r1, r4, #0
	bl Script_GetKeywordValue
	adds r6, r0, #0
	cmp r6, r4
	beq _08008912
	cmp r6, #4
	bgt _08008912
	ldr r4, [r7, #0x1c]
	movs r5, #0
	b _0800890C
	.align 2, 0
_080088F0: .4byte 0x03000034
_080088F4:
	ldrb r0, [r4]
	cmp r0, #1
	bne _08008908
	ldrh r0, [r4, #0x10]
	cmp r0, r8
	bne _08008908
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_08007f28
_08008908:
	adds r5, #1
	adds r4, #0xe8
_0800890C:
	ldr r0, [r7, #0x18]
	cmp r5, r0
	blo _080088F4
_08008912:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0800891c
FUN_0800891c: @ 0x0800891C
	movs r2, #0
	strb r1, [r0, #1]
	str r2, [r0, #4]
	movs r1, #1
	strb r1, [r0, #2]
	bx lr

	thumb_func_start FUN_08008928
FUN_08008928: @ 0x08008928
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #2]
	cmp r0, #0
	bne _08008936
	movs r0, #0
	b _0800893C
_08008936:
	movs r0, #0
	strb r0, [r1, #2]
	movs r0, #1
_0800893C:
	pop {r1}
	bx r1

	thumb_func_start FUN_08008940
FUN_08008940: @ 0x08008940
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r6, r2, #0
	ldr r0, _08008980 @ =0x03000038
	ldr r5, [r0]
	cmp r5, #0
	beq _080089B0
	ldrb r4, [r6, #1]
	cmp r4, #0
	bne _08008984
	movs r1, #4
	ldr r0, [r3, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080089B0
	adds r0, r6, #0
	movs r1, #1
	bl FUN_0800891c
	movs r1, #1
	adds r0, r1, #0
	ldrb r2, [r6]
	lsls r0, r2
	ldrh r2, [r5, #0x34]
	orrs r0, r2
	strh r0, [r5, #0x34]
	ldrb r6, [r6]
	lsls r1, r6
	ldrh r0, [r5, #0x38]
	orrs r1, r0
	strh r1, [r5, #0x38]
	b _080089B0
	.align 2, 0
_08008980: .4byte 0x03000038
_08008984:
	cmp r4, #1
	bne _080089B0
	movs r1, #8
	ldr r0, [r3, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080089B0
	adds r0, r6, #0
	movs r1, #0
	bl FUN_0800891c
	adds r0, r4, #0
	ldrb r1, [r6]
	lsls r0, r1
	ldrh r1, [r5, #0x36]
	orrs r0, r1
	strh r0, [r5, #0x36]
	ldrb r6, [r6]
	lsls r4, r6
	ldrh r0, [r5, #0x38]
	orrs r4, r0
	strh r4, [r5, #0x38]
_080089B0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080089b8
FUN_080089b8: @ 0x080089B8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x20
	mov sb, r0
	mov r8, r1
	adds r7, r2, #0
	movs r4, #0
	strb r7, [r1]
	mov r0, r8
	movs r1, #0
	bl FUN_0800891c
	mov r0, r8
	strb r4, [r0, #3]
	mov r5, r8
	adds r5, #0x58
	mov r6, sb
	adds r6, #0x4c
	movs r0, #2
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r0, sb
	adds r0, #0x44
	str r0, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0
	movs r3, #0x11
	bl FUN_0822f3fc
	adds r2, r7, #2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r4, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r3, #1
	bl FUN_082370cc
	subs r5, #0x50
	subs r0, r7, #1
	cmp r0, #1
	bhi _08008A3C
	ldr r2, _08008A34 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x18
	orrs r0, r1
	ldr r1, _08008A38 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r1, #0x60
	b _08008A58
	.align 2, 0
_08008A34: .4byte 0xFFFF0000
_08008A38: .4byte 0x0000FFFF
_08008A3C:
	ldr r2, _08008AD4 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x60
	orrs r0, r1
	ldr r1, _08008AD8 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r1, #0x18
_08008A58:
	orrs r0, r1
	str r0, [sp, #0x14]
	ldr r0, _08008ADC @ =0x085AA690
	lsls r2, r7, #1
	adds r0, r2, r0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	subs r0, #0x10
	lsls r0, r0, #0x10
	ldr r4, _08008AD4 @ =0xFFFF0000
	lsrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r0, _08008AE0 @ =0x085AA698
	adds r2, r2, r0
	ldrh r1, [r2]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x11
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r3, sp, #0x18
	ldr r0, [r3, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r3, #4]
	ldr r2, _08008AE4 @ =0x00004001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0x10
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r1, _08008AE8 @ =FUN_08008940
	adds r0, r5, #0
	mov r2, r8
	bl FUN_0823651c
	mov r1, sb
	adds r1, #0x3c
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	bl FUN_08236400
	movs r0, #0
	add sp, #0x20
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08008AD4: .4byte 0xFFFF0000
_08008AD8: .4byte 0x0000FFFF
_08008ADC: .4byte 0x085AA690
_08008AE0: .4byte 0x085AA698
_08008AE4: .4byte 0x00004001
_08008AE8: .4byte FUN_08008940

	thumb_func_start FUN_08008aec
FUN_08008aec: @ 0x08008AEC
	push {r4, lr}
	sub sp, #0x28
	adds r3, r0, #0
	adds r4, r1, #0
	ldrh r0, [r3, #0x1a]
	cmp r0, #0
	beq _08008B5C
	str r2, [sp]
	cmp r4, #1
	bne _08008B12
	str r4, [sp, #4]
	ldrh r1, [r3, #0x1c]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0xf
	beq _08008B28
	movs r0, #0
	str r0, [sp, #8]
	b _08008B2A
_08008B12:
	cmp r4, #0
	bne _08008B2A
	str r4, [sp, #4]
	ldrh r1, [r3, #0x1c]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _08008B28
	movs r0, #1
	str r0, [sp, #8]
	b _08008B2A
_08008B28:
	str r4, [sp, #8]
_08008B2A:
	ldrh r0, [r3, #0x38]
	asrs r0, r2
	movs r1, #1
	ands r0, r1
	str r0, [sp, #0xc]
	ldr r0, [r3, #0x24]
	str r0, [sp, #0x10]
	ldr r0, [r3, #0x28]
	str r0, [sp, #0x14]
	ldr r0, [r3, #0x2c]
	str r0, [sp, #0x18]
	ldr r0, [r3, #0x30]
	str r0, [sp, #0x1c]
	ldr r1, _08008B64 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x20]
	add r1, sp, #0x20
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r3, #0x1a]
	bl Script_ExecById
_08008B5C:
	add sp, #0x28
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08008B64: .4byte 0xFFFF0000

	thumb_func_start FUN_08008b68
FUN_08008b68: @ 0x08008B68
	push {r4, r5, r6, lr}
	sub sp, #0x24
	adds r6, r0, #0
	adds r5, r1, #0
	adds r0, r5, #0
	bl FUN_08008928
	cmp r0, #0
	beq _08008BF0
	ldr r0, [r5, #0x60]
	movs r1, #1
	orrs r0, r1
	str r0, [r5, #0x60]
	ldrb r0, [r5]
	lsls r1, r0
	ldrh r0, [r6, #0x1c]
	bics r0, r1
	movs r3, #0
	strh r0, [r6, #0x1c]
	ldr r1, _08008BF8 @ =0x085AA690
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r1, [r6, #0x3c]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldr r4, _08008BFC @ =0xFFFF0000
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r2, #0
	ldrh r2, [r6, #0x3e]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp, #0x1c]
	adds r2, r6, #0
	adds r2, #0x40
	ldr r1, _08008C00 @ =0x085AA698
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r2, [r2]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x20]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x20]
	ldr r2, _08008C04 @ =0x00002001
	str r3, [sp]
	str r3, [sp, #4]
	str r3, [sp, #8]
	str r3, [sp, #0xc]
	movs r0, #4
	str r0, [sp, #0x10]
	movs r0, #2
	str r0, [sp, #0x14]
	add r0, sp, #0x1c
	str r0, [sp, #0x18]
	movs r0, #1
	movs r1, #2
	movs r3, #0x40
	bl FUN_08015ce0
_08008BF0:
	add sp, #0x24
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08008BF8: .4byte 0x085AA690
_08008BFC: .4byte 0xFFFF0000
_08008C00: .4byte 0x085AA698
_08008C04: .4byte 0x00002001

	thumb_func_start FUN_08008c08
FUN_08008c08: @ 0x08008C08
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r0, r4, #0
	bl FUN_08008928
	cmp r0, #0
	beq _08008C2E
	ldr r0, [r4, #0x60]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x60]
	movs r0, #1
	ldrb r1, [r4]
	lsls r0, r1
	ldrh r1, [r5, #0x1c]
	orrs r0, r1
	strh r0, [r5, #0x1c]
_08008C2E:
	ldr r0, [r5, #0x44]
	ldr r1, [r5, #0x48]
	str r0, [r4, #0x78]
	str r1, [r4, #0x7c]
	adds r0, r4, #0
	adds r0, #0x58
	adds r1, r5, #0
	adds r1, #0x4c
	bl FUN_082372cc
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start Entity5DA5_Update
Entity5DA5_Update: @ 0x08008C48
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _08008C94 @ =0x030047A4
	ldr r1, _08008C98 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	beq _08008C6E
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0
	movs r2, #1
	bl FUN_08009064
_08008C6E:
	adds r5, r6, #0
	adds r5, #0x44
	adds r2, r6, #0
	adds r2, #0x3c
	ldrh r0, [r6, #0x3c]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r7, r2, #0
	cmp r0, #0
	blt _08008C9C
	asrs r0, r0, #8
	b _08008CA2
	.align 2, 0
_08008C94: .4byte 0x030047A4
_08008C98: .4byte 0x030047A0
_08008C9C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08008CA2:
	strh r0, [r5]
	adds r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08008CB4
	asrs r0, r0, #8
	b _08008CBA
_08008CB4:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08008CBA:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08008CCE
	asrs r0, r0, #8
	b _08008CD4
_08008CCE:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08008CD4:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _08008D30 @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	adds r4, r6, #0
	adds r4, #0xcc
	movs r5, #3
_08008CF8:
	ldr r1, _08008D34 @ =0x085AA6A0
	ldrb r0, [r4, #1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	bl _call_via_r2
	adds r0, r4, #0
	adds r0, #8
	adds r1, r7, #0
	movs r2, #0
	bl FUN_082364c4
	ldrb r1, [r4, #3]
	cmp r1, #0
	beq _08008D44
	subs r1, #1
	strb r1, [r4, #3]
	lsls r1, r1, #0x18
	cmp r1, #0
	bne _08008D3C
	ldrh r1, [r4, #0xe]
	ldr r3, _08008D38 @ =0x0000FFFB
	adds r2, r3, #0
	ands r1, r2
	b _08008D42
	.align 2, 0
_08008D30: .4byte 0x030047C8
_08008D34: .4byte 0x085AA6A0
_08008D38: .4byte 0x0000FFFB
_08008D3C:
	ldrh r2, [r4, #0xe]
	movs r1, #4
	orrs r1, r2
_08008D42:
	strh r1, [r4, #0xe]
_08008D44:
	ldr r1, [r4, #4]
	adds r1, #1
	str r1, [r4, #4]
	subs r5, #1
	adds r4, #0xb8
	cmp r5, #0
	bge _08008CF8
	movs r5, #4
	ldrh r2, [r6, #0x1c]
	movs r1, #0xf
	ands r1, r2
	cmp r1, #0xf
	bne _08008DC4
	ldr r0, [r6, #0x74]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x74]
	adds r0, r6, #0
	adds r0, #0x6c
	adds r1, r6, #0
	adds r1, #0x4c
	bl FUN_082372cc
	adds r3, r6, #0
	adds r3, #0x8c
	ldr r1, [r6, #0x44]
	ldr r2, [r6, #0x48]
	str r1, [r3]
	str r2, [r3, #4]
	adds r1, r6, #0
	adds r1, #0x89
	ldrb r1, [r1]
	ands r5, r1
	cmp r5, #0
	beq _08008DD6
	movs r0, #0x10
	str r0, [sp]
	ldr r2, _08008DBC @ =0x085AA6A8
	adds r0, r6, #0
	adds r0, #0x80
	ldrh r1, [r0]
	movs r0, #3
	ands r0, r1
	adds r0, r0, r2
	ldrb r0, [r0]
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #2
	movs r2, #2
	mov r3, sp
	bl FUN_08000fac
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r3, _08008DC0 @ =0x03003E78
	ldrh r2, [r3]
	orrs r1, r2
	strh r1, [r3]
	b _08008DD6
	.align 2, 0
_08008DBC: .4byte 0x085AA6A8
_08008DC0: .4byte 0x03003E78
_08008DC4:
	ldr r3, _08008E34 @ =0x03003E78
	ldr r1, _08008E38 @ =0xFFFFFDFF
	ldrh r2, [r3]
	ands r1, r2
	strh r1, [r3]
	ldr r1, [r6, #0x74]
	movs r2, #1
	orrs r1, r2
	str r1, [r6, #0x74]
_08008DD6:
	ldrh r1, [r6, #0x34]
	cmp r1, #0
	beq _08008E00
	ldr r0, _08008E3C @ =0x0000014B
	bl PlaySound_082406e0
	movs r5, #0
_08008DE4:
	ldrh r1, [r6, #0x34]
	asrs r1, r5
	movs r2, #1
	ands r1, r2
	cmp r1, #0
	beq _08008DFA
	adds r0, r6, #0
	movs r1, #1
	adds r2, r5, #0
	bl FUN_08008aec
_08008DFA:
	adds r5, #1
	cmp r5, #3
	ble _08008DE4
_08008E00:
	ldrh r1, [r6, #0x36]
	cmp r1, #0
	beq _08008E24
	movs r5, #0
_08008E08:
	ldrh r1, [r6, #0x36]
	asrs r1, r5
	movs r2, #1
	ands r1, r2
	cmp r1, #0
	beq _08008E1E
	adds r0, r6, #0
	movs r1, #0
	adds r2, r5, #0
	bl FUN_08008aec
_08008E1E:
	adds r5, #1
	cmp r5, #3
	ble _08008E08
_08008E24:
	movs r1, #0
	strh r1, [r6, #0x34]
	strh r1, [r6, #0x36]
	strh r1, [r6, #0x38]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08008E34: .4byte 0x03003E78
_08008E38: .4byte 0xFFFFFDFF
_08008E3C: .4byte 0x0000014B

	thumb_func_start Entity5DA5_Destroy
Entity5DA5_Destroy: @ 0x08008E40
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x6c
	bl FUN_0822f1c0
	adds r4, #0xcc
	movs r5, #3
_08008E4E:
	adds r0, r4, #0
	adds r0, #8
	bl FUN_08236424
	adds r0, r4, #0
	adds r0, #0x58
	bl FUN_0822f1c0
	subs r5, #1
	adds r4, #0xb8
	cmp r5, #0
	bge _08008E4E
	ldr r2, _08008E74 @ =0x03000038
	movs r1, #0
	str r1, [r2]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08008E74: .4byte 0x03000038

	thumb_func_start Entity5DA5_Init
Entity5DA5_Init: @ 0x08008E78
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	mov r8, r1
	ldr r0, _08008EA0 @ =0x03000038
	str r7, [r0]
	ldr r0, _08008EA4 @ =0x0000CB05
	ldr r1, _08008EA8 @ =0x0000F099
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _08008EAC
	movs r0, #1
	rsbs r0, r0, #0
	b _08009000
	.align 2, 0
_08008EA0: .4byte 0x03000038
_08008EA4: .4byte 0x0000CB05
_08008EA8: .4byte 0x0000F099
_08008EAC:
	adds r1, r7, #0
	adds r1, #0x4c
	adds r0, r2, #0
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r6, r7, #0
	adds r6, #0x4c
	adds r0, r6, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	movs r4, #0
	movs r5, #0
	mov r0, r8
	strh r0, [r7, #0x18]
	movs r0, #0x70
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r7, #0x1a]
	strh r5, [r7, #0x1c]
	strb r4, [r7, #0x1e]
	strb r4, [r7, #0x1f]
	str r5, [r7, #0x20]
	movs r0, #0x61
	bl prepare_08231510
	str r6, [sp, #0x10]
	subs r6, #0xc
	movs r1, #0x44
	adds r1, r1, r7
	mov sb, r1
	movs r3, #0x3c
	adds r3, r3, r7
	mov r8, r3
	movs r4, #0x6c
	adds r4, r4, r7
	mov sl, r4
	adds r5, r7, #0
	adds r5, #0xcc
	str r5, [sp, #0x14]
	cmp r0, #0
	beq _08008F24
	subs r5, #0xa8
	movs r4, #3
_08008F0E:
	bl VM_GetPC
	cmp r0, #0
	beq _08008F1C
	bl Script_GetValue
	str r0, [r5]
_08008F1C:
	adds r5, #4
	subs r4, #1
	cmp r4, #0
	bge _08008F0E
_08008F24:
	movs r0, #0x50
	bl prepare_08231510
	cmp r0, #0
	beq _08008F40
	bl Script_GetValue
	strh r0, [r7, #0x3c]
	bl Script_GetValue
	strh r0, [r7, #0x3e]
	bl Script_GetValue
	b _08008F44
_08008F40:
	strh r0, [r7, #0x3c]
	strh r0, [r7, #0x3e]
_08008F44:
	strh r0, [r6]
	mov r6, sb
	mov r5, r8
	ldrh r0, [r7, #0x3c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08008F66
	asrs r0, r0, #8
	b _08008F6C
_08008F66:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08008F6C:
	strh r0, [r6]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08008F7E
	asrs r0, r0, #8
	b _08008F84
_08008F7E:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08008F84:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r5, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08008F98
	asrs r0, r0, #8
	b _08008F9E
_08008F98:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08008F9E:
	subs r2, r4, r0
	movs r5, #0
	strh r2, [r6, #2]
	adds r4, r4, r0
	strh r4, [r6, #4]
	ldr r3, _08009010 @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	movs r0, #2
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	mov r0, sl
	ldr r1, [sp, #0x10]
	movs r2, #0
	movs r3, #0x11
	bl FUN_0822f3fc
	str r5, [sp]
	mov r0, sl
	ldr r1, [sp, #0x10]
	movs r2, #6
	movs r3, #1
	bl FUN_082370cc
	ldr r5, [sp, #0x14]
	movs r4, #0
_08008FEE:
	adds r0, r7, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080089b8
	adds r4, #1
	adds r5, #0xb8
	cmp r4, #3
	ble _08008FEE
_08009000:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08009010: .4byte 0x030047C8

	thumb_func_start Entity5DA5_Create
Entity5DA5_Create: @ 0x08009014
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08009050 @ =0x03000038
	ldr r0, [r0]
	cmp r0, #0
	bne _0800905E
	movs r1, #0xeb
	lsls r1, r1, #2
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0800905C
	ldr r1, _08009054 @ =Entity5DA5_Update
	ldr r2, _08009058 @ =Entity5DA5_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity5DA5_Init
	cmp r0, #0
	bge _0800905C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0800905E
	.align 2, 0
_08009050: .4byte 0x03000038
_08009054: .4byte Entity5DA5_Update
_08009058: .4byte Entity5DA5_Destroy
_0800905C:
	adds r0, r4, #0
_0800905E:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08009064
FUN_08009064: @ 0x08009064
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	ldr r1, _08009080 @ =0x03000038
	ldr r4, [r1]
	cmp r4, #0
	bne _08009084
	movs r0, #1
	rsbs r0, r0, #0
	b _08009116
	.align 2, 0
_08009080: .4byte 0x03000038
_08009084:
	cmp r6, #0
	bge _080090D6
	adds r5, r4, #0
	adds r5, #0xcc
	movs r6, #0
	movs r3, #1
_08009090:
	ldrb r1, [r5, #1]
	cmp r1, r7
	beq _080090CC
	adds r0, r5, #0
	adds r1, r7, #0
	str r3, [sp]
	bl FUN_0800891c
	ldr r3, [sp]
	cmp r7, #0
	bne _080090B2
	adds r1, r3, #0
	lsls r1, r6
	ldrh r2, [r4, #0x36]
	orrs r1, r2
	strh r1, [r4, #0x36]
	b _080090BC
_080090B2:
	adds r1, r3, #0
	lsls r1, r6
	ldrh r2, [r4, #0x34]
	orrs r1, r2
	strh r1, [r4, #0x34]
_080090BC:
	mov r1, r8
	cmp r1, #0
	beq _080090CC
	adds r1, r3, #0
	lsls r1, r6
	ldrh r2, [r4, #0x38]
	orrs r1, r2
	strh r1, [r4, #0x38]
_080090CC:
	adds r6, #1
	adds r5, #0xb8
	cmp r6, #3
	ble _08009090
	b _08009116
_080090D6:
	movs r1, #0xb8
	muls r1, r6, r1
	adds r1, #0xcc
	adds r5, r4, r1
	ldrb r1, [r5, #1]
	cmp r1, r7
	beq _08009116
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_0800891c
	cmp r7, #0
	bne _080090FC
	movs r1, #1
	lsls r1, r6
	ldrh r2, [r4, #0x36]
	orrs r1, r2
	strh r1, [r4, #0x36]
	b _08009106
_080090FC:
	movs r1, #1
	lsls r1, r6
	ldrh r2, [r4, #0x34]
	orrs r1, r2
	strh r1, [r4, #0x34]
_08009106:
	mov r1, r8
	cmp r1, #0
	beq _08009116
	movs r1, #1
	lsls r1, r6
	ldrh r2, [r4, #0x38]
	orrs r1, r2
	strh r1, [r4, #0x38]
_08009116:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08009124
FUN_08009124: @ 0x08009124
	push {r4, r5, lr}
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0x69
	bl Script_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0x6d
	movs r1, #0
	bl Script_GetKeywordValue
	adds r4, r0, #0
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08009064
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08009154
FUN_08009154: @ 0x08009154
	push {lr}
	ldr r0, _08009164 @ =0x03000038
	ldr r0, [r0]
	cmp r0, #0
	bne _08009168
	movs r0, #1
	rsbs r0, r0, #0
	b _08009188
	.align 2, 0
_08009164: .4byte 0x03000038
_08009168:
	movs r3, #0
	adds r1, r0, #0
	adds r1, #0xcc
	movs r2, #3
_08009170:
	ldrb r0, [r1, #1]
	cmp r0, #1
	bne _08009178
	adds r3, #1
_08009178:
	subs r2, #1
	adds r1, #0xb8
	cmp r2, #0
	bge _08009170
	movs r0, #0
	cmp r3, #4
	bne _08009188
	movs r0, #1
_08009188:
	pop {r1}
	bx r1

	thumb_func_start FUN_0800918c
FUN_0800918c: @ 0x0800918C
	push {lr}
	ldr r0, _0800919C @ =0x03000038
	ldr r0, [r0]
	cmp r0, #0
	bne _080091A0
	movs r0, #1
	rsbs r0, r0, #0
	b _080091C0
	.align 2, 0
_0800919C: .4byte 0x03000038
_080091A0:
	movs r3, #0
	adds r1, r0, #0
	adds r1, #0xcc
	movs r2, #3
_080091A8:
	ldrb r0, [r1, #1]
	cmp r0, #1
	bne _080091B0
	adds r3, #1
_080091B0:
	subs r2, #1
	adds r1, #0xb8
	cmp r2, #0
	bge _080091A8
	movs r0, #0
	cmp r3, #0
	bne _080091C0
	movs r0, #1
_080091C0:
	pop {r1}
	bx r1

