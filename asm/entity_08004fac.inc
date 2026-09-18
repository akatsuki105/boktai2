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
	bl Video_GetAuxSprite
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
	bl Video_SetAuxSpritePltt
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
	bl VM_GetKeywordValue
	str r0, [sp, #0x20]
	movs r0, #0x74
	movs r1, #0
	bl VM_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	mov sb, r0
	movs r0, #0x4d
	bl VM_SeekToKeyword
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
	bl VM_SeekToKeyword
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
	bl VM_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x69
	movs r1, #0
	bl VM_GetKeywordValue
	mov r8, r0
	movs r0, #0x6c
	movs r1, #0x80
	bl VM_GetKeywordValue
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
	bl VM_GetKeywordValue
	adds r5, r0, #0
_08004B6A:
	movs r4, #0x99
	lsls r4, r4, #1
	movs r0, #0x62
	movs r1, #0
	bl VM_GetKeywordValue
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
	bl VM_GetKeywordValue
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
	bl VM_GetKeywordValue
	adds r4, r0, #0
	movs r0, #0x53
	movs r1, #1
	bl VM_GetKeywordValue
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
	bl Video_SetAuxSpritePltt
	b _08004C68
_08004C14:
	movs r0, #3
	strh r0, [r5, #0x1a]
	adds r0, r5, #0
	adds r0, #0x70
	movs r1, #3
	bl Video_SetAuxSpritePltt
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
	bl Video_SetAuxSpritePltt
	adds r1, r7, #0
	adds r1, #0x30
	b _08004C56
_08004C44:
	movs r0, #5
	strh r0, [r5, #0x1a]
	adds r0, r5, #0
	adds r0, #0x70
	movs r1, #5
	bl Video_SetAuxSpritePltt
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
	bl VM_GetKeywordValue
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
	bl VM_GetKeywordValue
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
	bl VM_GetKeywordValue
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
	bl VM_GetKeywordValue
	mov r8, r0
	movs r0, #0x74
	adds r1, r4, #0
	bl VM_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x66
	adds r1, r4, #0
	bl VM_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x65
	adds r1, r4, #0
	bl VM_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0x70
	bl VM_SeekToKeyword
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
	bl VM_GetKeywordValue
	mov r8, r0
	movs r0, #0x74
	movs r1, #0
	bl VM_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0x70
	bl VM_SeekToKeyword
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
