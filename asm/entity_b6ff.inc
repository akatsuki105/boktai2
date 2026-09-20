	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080ac5b4
FUN_080ac5b4: @ 0x080AC5B4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080AC5F0 @ =0x0000A854
	bl FUN_08230e70
	cmp r0, #0
	beq _080AC5E8
	movs r5, #1
	adds r1, r0, #0
	adds r1, #0x18
	movs r3, #0
	movs r2, #3
_080AC5CC:
	ldrh r0, [r1, #0x36]
	cmp r0, #0
	beq _080AC5E0
	ldrh r0, [r1, #0x34]
	cmp r0, r4
	bne _080AC5E0
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
	strh r3, [r1, #0x36]
_080AC5E0:
	adds r1, #0x40
	subs r2, #1
	cmp r2, #0
	bge _080AC5CC
_080AC5E8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AC5F0: .4byte 0x0000A854

	thumb_func_start FUN_080ac5f4
FUN_080ac5f4: @ 0x080AC5F4
	push {lr}
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080AC608
	bl Script_GetValue
	bl FUN_080ac5b4
_080AC608:
	pop {r0}
	bx r0

	thumb_func_start FUN_080ac60c
FUN_080ac60c: @ 0x080AC60C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	mov r8, r3
	ldr r0, _080AC634 @ =0x0000A854
	bl FUN_08230e70
	adds r4, r0, #0
	cmp r4, #0
	bne _080AC62C
	bl Entity080ac574_Create
	adds r4, r0, #0
_080AC62C:
	movs r2, #0
	adds r1, r4, #0
	adds r1, #0x4e
	b _080AC640
	.align 2, 0
_080AC634: .4byte 0x0000A854
_080AC638:
	adds r1, #0x40
	adds r2, #1
	cmp r2, #3
	bgt _080AC68E
_080AC640:
	ldrh r0, [r1]
	cmp r0, #0
	bne _080AC638
	cmp r2, #3
	bgt _080AC68E
	lsls r0, r2, #6
	adds r1, r4, r0
	mov ip, r1
	adds r1, #0x4c
	strh r5, [r1]
	adds r3, r4, #0
	adds r3, #0x40
	adds r3, r3, r0
	ldr r1, [r6]
	ldr r2, [r6, #4]
	str r1, [r3]
	str r2, [r3, #4]
	mov r1, ip
	adds r1, #0x54
	strh r7, [r1]
	adds r1, #2
	mov r2, r8
	strh r2, [r1]
	mov r2, ip
	adds r2, #0x4e
	movs r1, #1
	strh r1, [r2]
	adds r2, r4, #0
	adds r2, #0x18
	adds r2, r2, r0
	ldr r1, [r2]
	movs r3, #2
	rsbs r3, r3, #0
	ands r1, r3
	str r1, [r2]
	adds r0, #0x18
	adds r0, r4, r0
	bl FUN_080ac3d4
_080AC68E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080ac698
FUN_080ac698: @ 0x080AC698
	push {r4, r5, lr}
	sub sp, #8
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080AC6AE
	bl Script_GetValue
	adds r5, r0, #0
	b _080AC6B0
_080AC6AE:
	movs r5, #0
_080AC6B0:
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080AC6F8
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080AC6F0 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080AC6F4 @ =0x0000FFFF
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
	b _080AC702
	.align 2, 0
_080AC6F0: .4byte 0xFFFF0000
_080AC6F4: .4byte 0x0000FFFF
_080AC6F8:
	ldr r1, _080AC71C @ =0xFFFF0000
	str r0, [sp]
	ldr r0, [sp, #4]
	ands r0, r1
	str r0, [sp, #4]
_080AC702:
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080AC720
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	adds r3, r0, #0
	b _080AC724
	.align 2, 0
_080AC71C: .4byte 0xFFFF0000
_080AC720:
	movs r4, #0x10
	movs r3, #0
_080AC724:
	adds r0, r5, #0
	mov r1, sp
	adds r2, r4, #0
	bl FUN_080ac60c
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ac738
FUN_080ac738: @ 0x080AC738
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r0, #0x48
	ldrh r0, [r0]
	ldrh r1, [r3, #0x1c]
	adds r0, r0, r1
	strh r0, [r3, #0x1c]
	adds r0, r3, #0
	adds r0, #0x4a
	ldrh r0, [r0]
	ldrh r1, [r3, #0x1e]
	adds r0, r0, r1
	strh r0, [r3, #0x1e]
	adds r0, r3, #0
	adds r0, #0x4c
	ldrh r0, [r0]
	ldrh r1, [r3, #0x20]
	adds r0, r0, r1
	strh r0, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x54
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x12
	movs r1, #3
	ands r0, r1
	strh r0, [r3, #0x10]
	adds r1, r3, #0
	adds r1, #0x56
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080AC864
	ldr r2, _080AC7B0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080AC7B4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080AC7B8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #0x1f
	ands r0, r1
	adds r4, r0, #0
	subs r4, #0xf
	adds r6, r2, #0
	cmp r4, #0
	ble _080AC7BC
	ldr r0, [r3]
	movs r1, #4
	orrs r0, r1
	b _080AC7C4
	.align 2, 0
_080AC7B0: .4byte 0x030046B8
_080AC7B4: .4byte 0x000003FF
_080AC7B8: .4byte 0x0203B400
_080AC7BC:
	ldr r0, [r3]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080AC7C4:
	str r0, [r3]
	adds r0, r3, #0
	adds r0, #0x58
	ldrh r0, [r0]
	adds r4, r4, r0
	ldr r0, [r6]
	adds r0, #1
	ldr r1, _080AC80C @ =0x000003FF
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r1, _080AC810 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r2, r3, #0
	adds r2, #0x5a
	asrs r0, r0, #3
	movs r1, #3
	ands r0, r1
	ldrh r2, [r2]
	adds r0, r0, r2
	subs r5, r0, #1
	ldr r2, _080AC814 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _080AC818
	asrs r1, r0, #0xc
	b _080AC81E
	.align 2, 0
_080AC80C: .4byte 0x000003FF
_080AC810: .4byte 0x0203B400
_080AC814: .4byte 0x085B0A08
_080AC818:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080AC81E:
	adds r0, r3, #0
	adds r0, #0x48
	strh r1, [r0]
	movs r0, #0xff
	ands r4, r0
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _080AC83A
	asrs r2, r0, #0xc
	b _080AC840
_080AC83A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080AC840:
	adds r0, r3, #0
	adds r0, #0x4c
	strh r2, [r0]
	ldr r0, [r6]
	adds r0, #1
	ldr r1, _080AC86C @ =0x000003FF
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r1, _080AC870 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0xf
	adds r1, r3, #0
	adds r1, #0x56
	strh r0, [r1]
_080AC864:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AC86C: .4byte 0x000003FF
_080AC870: .4byte 0x0203B400

	thumb_func_start FUN_080ac874
FUN_080ac874: @ 0x080AC874
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov ip, r0
	ldr r0, [r1]
	ldr r1, [r1, #4]
	mov r3, ip
	str r0, [r3, #0x1c]
	str r1, [r3, #0x20]
	ldr r6, _080AC918 @ =0x0203B400
	ldr r5, _080AC91C @ =0x030046B8
	mov r8, r5
	ldr r1, [r5]
	adds r1, #1
	ldr r4, _080AC920 @ =0x000003FF
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ldrh r3, [r3, #0x1c]
	subs r3, #0xff
	asrs r0, r0, #3
	ldr r7, _080AC924 @ =0x000001FF
	adds r5, r7, #0
	ands r0, r5
	adds r3, r3, r0
	mov r0, ip
	strh r3, [r0, #0x1c]
	adds r1, #1
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	mov r7, ip
	ldrh r3, [r7, #0x20]
	subs r3, #0xff
	asrs r0, r0, #3
	ands r0, r5
	adds r3, r3, r0
	strh r3, [r7, #0x20]
	mov r3, ip
	adds r3, #0x58
	strh r2, [r3]
	adds r1, #1
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r2, [r0]
	movs r0, #0x1f
	ands r2, r0
	ldrh r3, [r3]
	adds r2, r2, r3
	adds r5, r2, #0
	subs r5, #0xf
	adds r1, #1
	ands r1, r4
	mov r0, r8
	str r1, [r0]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	mov r3, ip
	adds r3, #0x5a
	movs r1, #3
	ands r0, r1
	ldrh r3, [r3]
	adds r0, r0, r3
	subs r4, r0, #1
	ldr r1, _080AC928 @ =0x085B0A08
	adds r2, #0x31
	movs r0, #0xff
	ands r2, r0
	lsls r2, r2, #1
	adds r2, r2, r1
	movs r3, #0
	ldrsh r0, [r2, r3]
	muls r0, r4, r0
	mov r2, r8
	cmp r0, #0
	blt _080AC92C
	asrs r3, r0, #0xc
	b _080AC932
	.align 2, 0
_080AC918: .4byte 0x0203B400
_080AC91C: .4byte 0x030046B8
_080AC920: .4byte 0x000003FF
_080AC924: .4byte 0x000001FF
_080AC928: .4byte 0x085B0A08
_080AC92C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080AC932:
	mov r0, ip
	adds r0, #0x48
	strh r3, [r0]
	movs r0, #0xff
	ands r5, r0
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r4, r0
	cmp r0, #0
	blt _080AC94E
	asrs r1, r0, #0xc
	b _080AC954
_080AC94E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080AC954:
	mov r0, ip
	adds r0, #0x4c
	strh r1, [r0]
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080AC998 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r7, _080AC99C @ =0x0203B400
	adds r0, r0, r7
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0xf
	mov r1, ip
	adds r1, #0x56
	strh r0, [r1]
	mov r1, ip
	ldr r0, [r1]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	mov r3, ip
	str r0, [r3]
	mov r1, ip
	adds r1, #0x50
	movs r0, #1
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AC998: .4byte 0x000003FF
_080AC99C: .4byte 0x0203B400

	thumb_func_start EntityB6FF_Update
EntityB6FF_Update: @ 0x080AC9A0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	movs r6, #0
_080AC9AE:
	movs r0, #0x5c
	adds r1, r6, #0
	muls r1, r0, r1
	adds r0, r7, r1
	adds r0, #0x90
	ldrb r0, [r0]
	cmp r0, #0
	beq _080AC9C8
	adds r0, r1, #0
	adds r0, #0x40
	adds r0, r7, r0
	bl FUN_080ac738
_080AC9C8:
	adds r6, #1
	cmp r6, #0x17
	ble _080AC9AE
	movs r0, #0
	mov sb, r0
	ldr r1, _080ACA3C @ =0x0000FFFF
	mov r8, r1
	adds r5, r7, #0
	adds r5, #0x24
	adds r3, r7, #0
	adds r3, #0x1c
	movs r6, #2
_080AC9E0:
	ldrh r0, [r5, #2]
	adds r0, #1
	strh r0, [r5, #2]
	mov r1, r8
	ands r0, r1
	cmp r0, #0x1f
	bls _080ACA20
	movs r0, #0x8e
	lsls r0, r0, #4
	adds r4, r7, r0
	ldrh r1, [r4]
	movs r0, #0x5c
	muls r0, r1, r0
	adds r0, #0x40
	adds r0, r7, r0
	ldrh r2, [r5]
	adds r1, r3, #0
	str r3, [sp]
	bl FUN_080ac874
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	mov r1, r8
	ands r0, r1
	ldr r3, [sp]
	cmp r0, #0x17
	bls _080ACA1C
	mov r0, sb
	strh r0, [r4]
_080ACA1C:
	mov r1, sb
	strh r1, [r5, #2]
_080ACA20:
	adds r5, #0xc
	adds r3, #0xc
	subs r6, #1
	cmp r6, #0
	bge _080AC9E0
	movs r0, #0
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080ACA3C: .4byte 0x0000FFFF

	thumb_func_start EntityB6FF_Destroy
EntityB6FF_Destroy: @ 0x080ACA40
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x40
	movs r5, #0x17
_080ACA48:
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r4, #0x5c
	subs r5, #1
	cmp r5, #0
	bge _080ACA48
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080aca60
FUN_080aca60: @ 0x080ACA60
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	movs r6, #0
	mov r8, r6
	ldr r7, _080ACAD4 @ =0x030046B8
_080ACA70:
	movs r0, #0x5c
	adds r4, r6, #0
	muls r4, r0, r4
	adds r4, #0x40
	add r4, sb
	adds r5, r4, #0
	adds r5, #0x2c
	adds r0, r5, #0
	ldr r1, _080ACAD8 @ =0x0000CC88
	bl Video_GetAuxSprite
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	mov r0, r8
	strh r0, [r4, #0x10]
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080ACADC @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _080ACAE0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #3
	ands r0, r1
	adds r0, #5
	adds r1, r4, #0
	adds r1, #0x5a
	strh r0, [r1]
	adds r4, #0x50
	mov r0, r8
	strb r0, [r4]
	adds r6, #1
	cmp r6, #0x17
	ble _080ACA70
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ACAD4: .4byte 0x030046B8
_080ACAD8: .4byte 0x0000CC88
_080ACADC: .4byte 0x000003FF
_080ACAE0: .4byte 0x0203B400

	thumb_func_start EntityB6FF_Init
EntityB6FF_Init: @ 0x080ACAE4
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r0, #0x63
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080ACB14
	adds r4, r7, #0
	adds r4, #0x1c
	movs r5, #2
_080ACAF8:
	bl Script_GetValue
	strh r0, [r4]
	bl Script_GetValue
	strh r0, [r4, #2]
	bl Script_GetValue
	strh r0, [r4, #4]
	adds r4, #0xc
	subs r5, #1
	cmp r5, #0
	bge _080ACAF8
	b _080ACB2A
_080ACB14:
	movs r1, #0
	adds r0, r7, #0
	adds r0, #0x1c
	movs r5, #2
_080ACB1C:
	strh r1, [r0]
	strh r1, [r0, #2]
	strh r1, [r0, #4]
	adds r0, #0xc
	subs r5, #1
	cmp r5, #0
	bge _080ACB1C
_080ACB2A:
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080ACB70
	ldr r6, _080ACB64 @ =0x030046B8
	adds r4, r7, #0
	adds r4, #0x24
	movs r5, #2
_080ACB3C:
	bl Script_GetValue
	strh r0, [r4]
	ldr r0, [r6]
	adds r0, #1
	ldr r1, _080ACB68 @ =0x000003FF
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r1, _080ACB6C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	strh r0, [r4, #2]
	adds r4, #0xc
	subs r5, #1
	cmp r5, #0
	bge _080ACB3C
	b _080ACBA0
	.align 2, 0
_080ACB64: .4byte 0x030046B8
_080ACB68: .4byte 0x000003FF
_080ACB6C: .4byte 0x0203B400
_080ACB70:
	movs r0, #0x20
	mov ip, r0
	ldr r6, _080ACBC0 @ =0x0203B400
	ldr r2, _080ACBC4 @ =0x030046B8
	adds r1, r7, #0
	adds r1, #0x24
	ldr r4, _080ACBC8 @ =0x000003FF
	movs r3, #0x1f
	movs r5, #2
_080ACB82:
	mov r0, ip
	strh r0, [r1]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r4
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r3
	strh r0, [r1, #2]
	adds r1, #0xc
	subs r5, #1
	cmp r5, #0
	bge _080ACB82
_080ACBA0:
	movs r5, #2
_080ACBA2:
	subs r5, #1
	cmp r5, #0
	bge _080ACBA2
	adds r0, r7, #0
	bl FUN_080aca60
	ldr r0, _080ACBCC @ =0x00003969
	adds r1, r7, #0
	movs r2, #0
	bl FUN_08230e30
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080ACBC0: .4byte 0x0203B400
_080ACBC4: .4byte 0x030046B8
_080ACBC8: .4byte 0x000003FF
_080ACBCC: .4byte 0x00003969

	thumb_func_start EntityB6FF_Create
EntityB6FF_Create: @ 0x080ACBD0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _080ACC00 @ =0x000008E4
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080ACC0C
	strh r5, [r4, #0x18]
	ldr r1, _080ACC04 @ =EntityB6FF_Update
	ldr r2, _080ACC08 @ =EntityB6FF_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityB6FF_Init
	cmp r0, #0
	bge _080ACC0C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080ACC0E
	.align 2, 0
_080ACC00: .4byte 0x000008E4
_080ACC04: .4byte EntityB6FF_Update
_080ACC08: .4byte EntityB6FF_Destroy
_080ACC0C:
	adds r0, r4, #0
_080ACC0E:
	pop {r4, r5}
	pop {r1}
	bx r1
