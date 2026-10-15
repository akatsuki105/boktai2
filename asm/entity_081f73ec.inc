	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081f5458
FUN_081f5458: @ 0x081F5458
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sb, r0
	str r1, [sp, #4]
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	movs r0, #0
	mov sl, r0
	movs r1, #0
	str r1, [sp, #0x10]
	mov r5, sb
	mov r6, sb
	adds r6, #0xe8
	movs r2, #0x2c
	add r2, sb
	mov r8, r2
	mov r7, sb
_081F5482:
	mov r0, r8
	ldr r1, [sp, #4]
	bl Video_GetAuxSprite
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0
	bl AuxSprite_Add
	mov r0, r8
	movs r1, #0xd1
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	mov r4, sp
	ldrb r4, [r4, #0xc]
	strb r4, [r6, #0x14]
	ldr r0, [sp, #8]
	lsls r1, r0, #0x10
	ldr r0, _081F54CC @ =0x0000922E
	lsrs r1, r1, #0x10
	bl GetFile
	adds r1, r0, #0
	str r1, [r6, #0x10]
	mov r2, sl
	cmp r2, #5
	bne _081F54D0
	movs r4, #0
	str r4, [sp]
	adds r0, r6, #0
	movs r2, #7
	movs r3, #0
	bl AuxAnim_SetAnim
	b _081F54E6
	.align 2, 0
_081F54CC: .4byte 0x0000922E
_081F54D0:
	movs r3, #2
	mov r0, sl
	cmp r0, #0
	bgt _081F54DA
	movs r3, #1
_081F54DA:
	movs r2, #0
	str r2, [sp]
	adds r0, r6, #0
	movs r2, #6
	bl AuxAnim_SetAnim
_081F54E6:
	adds r1, r7, #0
	adds r1, #0xe8
	adds r3, r1, #0
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r3, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r4]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r2, r0
	beq _081F5518
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081F5520
_081F5518:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F5520:
	str r0, [r5]
	ldrb r0, [r3, #4]
	movs r1, #2
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	movs r2, #2
	ands r0, r2
	cmp r1, r0
	beq _081F5544
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081F554C
_081F5544:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F554C:
	str r0, [r5]
	ldrh r0, [r3, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0xe]
	ldr r4, _081F5584 @ =0x0000FFFF
	adds r2, r4, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r4, [r3, #7]
	cmp r0, r4
	blo _081F55BC
	strh r1, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F5588
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _081F557C
	ldrb r0, [r3, #5]
_081F557C:
	subs r0, #1
	strh r0, [r3, #8]
	b _081F5598
	.align 2, 0
_081F5584: .4byte 0x0000FFFF
_081F5588:
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _081F5598
	strh r1, [r3, #8]
_081F5598:
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r3, #6]
	ldrb r1, [r3, #6]
	ldrh r0, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r3, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081F55BC
	movs r4, #1
	strb r4, [r3, #7]
_081F55BC:
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	movs r2, #2
	strb r2, [r6, #0x15]
	mov r4, sb
	str r4, [r6, #0x38]
	mov r0, sp
	ldrb r0, [r0, #0x10]
	strb r0, [r6, #0x1e]
	movs r1, #0
	strh r1, [r6, #0x1a]
	ldr r2, [sp, #0x10]
	adds r2, #0x18
	str r2, [sp, #0x10]
	movs r4, #0x92
	lsls r4, r4, #1
	adds r5, r5, r4
	adds r6, r6, r4
	add r8, r4
	adds r7, r7, r4
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #5
	bgt _081F55F4
	b _081F5482
_081F55F4:
	movs r1, #0xdb
	lsls r1, r1, #3
	add r1, sb
	movs r0, #5
	strb r0, [r1]
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081f5610
FUN_081f5610: @ 0x081F5610
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	mov sl, r0
	ldr r1, [sp, #8]
	adds r1, #0xfd
	mov sb, r1
	ldr r2, [sp, #8]
	mov r8, r2
	adds r7, r2, #0
	adds r6, r2, #0
	adds r6, #0x1c
_081F5632:
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081F5656
	cmp r1, #0
	blt _081F5656
	ldr r0, _081F565C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081F5656
	ldr r0, _081F5660 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081F5664
_081F5656:
	movs r4, #0
	b _081F5672
	.align 2, 0
_081F565C: .4byte 0x030046A8
_081F5660: .4byte 0x030046AC
_081F5664:
	ldr r0, _081F5684 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081F5672:
	adds r5, r6, #0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081F5688
	adds r0, #4
	b _081F5694
	.align 2, 0
_081F5684: .4byte 0x030046A4
_081F5688:
	ldr r0, _081F56A8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081F5694:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r3, r0, #8
	cmp r2, #1
	beq _081F56AC
	cmp r2, #2
	beq _081F56B0
	b _081F56B4
	.align 2, 0
_081F56A8: .4byte 0x030046A4
_081F56AC:
	ldrb r0, [r5, #4]
	b _081F56B2
_081F56B0:
	ldrb r0, [r5]
_081F56B2:
	subs r3, r3, r0
_081F56B4:
	movs r1, #2
	ldrsh r0, [r6, r1]
	cmp r0, r3
	bge _081F5704
	mov r2, r8
	ldr r1, [r2]
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	bne _081F56F8
	orrs r1, r2
	mov r0, r8
	str r1, [r0]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [sp]
	str r1, [sp, #4]
	subs r1, r3, #1
	lsls r1, r1, #0x10
	ldr r2, _081F5700 @ =0x0000FFFF
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	mov r0, sp
	movs r1, #1
	bl FUN_081f624c
	mov r2, sb
	ldrb r1, [r2]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2]
_081F56F8:
	movs r0, #1
	rsbs r0, r0, #0
	add sl, r0
	b _081F5742
	.align 2, 0
_081F5700: .4byte 0x0000FFFF
_081F5704:
	adds r4, r7, #0
	adds r4, #0xfd
	ldrb r1, [r4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081F573E
	ldr r1, [r7]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081F573E
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r7]
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	strh r3, [r0, #2]
	movs r1, #1
	bl FUN_081f624c
	ldrb r1, [r4]
	movs r0, #0xfd
	ands r0, r1
	strb r0, [r4]
_081F573E:
	movs r1, #1
	add sl, r1
_081F5742:
	movs r2, #0x92
	lsls r2, r2, #1
	add sb, r2
	add r8, r2
	adds r7, r7, r2
	adds r6, r6, r2
	ldr r1, [sp, #8]
	ldr r2, _081F5764 @ =0x000005B4
	adds r0, r1, r2
	cmp r8, r0
	bgt _081F575A
	b _081F5632
_081F575A:
	mov r0, sl
	cmp r0, #5
	ble _081F5768
	movs r0, #1
	b _081F5778
	.align 2, 0
_081F5764: .4byte 0x000005B4
_081F5768:
	movs r0, #6
	rsbs r0, r0, #0
	cmp sl, r0
	ble _081F5774
	movs r0, #0
	b _081F5778
_081F5774:
	movs r0, #1
	rsbs r0, r0, #0
_081F5778:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081f5788
FUN_081f5788: @ 0x081F5788
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #5
_081F578E:
	adds r0, r4, #0
	bl AuxSprite_Remove
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r4, r0
	subs r5, #1
	cmp r5, #0
	bge _081F578E
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081f57a8
FUN_081f57a8: @ 0x081F57A8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x98
	movs r5, #5
_081F57B0:
	adds r0, r4, #0
	bl Hitbox_Unregister
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r4, r0
	subs r5, #1
	cmp r5, #0
	bge _081F57B0
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081f57c8
FUN_081f57c8: @ 0x081F57C8
	lsls r3, r1, #3
	adds r3, r3, r1
	lsls r3, r3, #3
	adds r3, r3, r1
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r1, [r2]
	ldr r2, [r2, #4]
	str r1, [r0, #0x1c]
	str r2, [r0, #0x20]
	bx lr
	.align 2, 0

	thumb_func_start FUN_081f57e0
FUN_081f57e0: @ 0x081F57E0
	lsls r3, r2, #3
	adds r3, r3, r2
	lsls r3, r3, #3
	adds r3, r3, r2
	lsls r3, r3, #2
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r0, r0, r2
	adds r0, r0, r3
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [r0]
	str r2, [r0, #4]
	bx lr

	thumb_func_start FUN_081f57fc
FUN_081f57fc: @ 0x081F57FC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x48
	str r0, [sp, #0x2c]
	adds r4, r3, #0
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	movs r0, #0x80
	lsls r0, r0, #3
	subs r1, r4, #1
	ldr r2, [sp, #0x68]
	subs r1, r2, r1
	bl Div
	str r0, [sp, #0x30]
	movs r0, #0
	mov sl, r4
	ldr r3, [sp, #0x68]
	cmp sl, r3
	blt _081F5838
	b _081F5994
_081F5838:
	mov r4, sp
	adds r4, #4
	str r4, [sp, #0x34]
	add r7, sp, #0xc
	mov sb, r7
	mov r1, sp
	adds r1, #0x14
	str r1, [sp, #0x38]
	add r2, sp, #0x1c
	mov r8, r2
	mov r3, sp
	adds r3, #0x24
	str r3, [sp, #0x40]
_081F5852:
	adds r4, r0, #1
	ldr r7, [sp, #0x30]
	adds r5, r7, #0
	muls r5, r4, r5
	ldr r1, [sp, #0x38]
	ldrh r0, [r1]
	mov r2, sb
	ldrh r1, [r2]
	subs r0, r0, r1
	mov r3, r8
	strh r0, [r3]
	ldr r7, [sp, #0x38]
	ldrh r0, [r7, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r7, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	add r1, sp, #0x24
	ldr r2, _081F5898 @ =0x05000002
	bl CpuSet
	adds r0, r5, #0
	muls r0, r5, r0
	str r4, [sp, #0x3c]
	cmp r0, #0
	blt _081F589C
	asrs r0, r0, #0xa
	b _081F58A2
	.align 2, 0
_081F5898: .4byte 0x05000002
_081F589C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r0, r0, #0
_081F58A2:
	adds r3, r0, #0
	adds r0, r3, #0
	muls r0, r5, r0
	cmp r0, #0
	blt _081F58B0
	asrs r1, r0, #0xa
	b _081F58B6
_081F58B0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081F58B6:
	lsls r2, r1, #1
	lsls r0, r3, #1
	adds r6, r0, r3
	subs r0, r1, r0
	adds r0, r0, r5
	movs r4, #0
	adds r5, r0, #0
	muls r5, r4, r5
	subs r1, r1, r3
	mov ip, r1
	subs r0, r2, r6
	adds r0, #1
	ldr r7, [sp, #0x40]
	movs r3, #0
	ldrsh r1, [r7, r3]
	muls r0, r1, r0
	adds r7, r4, #0
	adds r4, r0, #0
	muls r4, r7, r4
	subs r1, r6, r2
	mov r3, r8
	movs r7, #0
	ldrsh r0, [r3, r7]
	muls r0, r1, r0
	adds r0, r4, r0
	adds r0, r0, r5
	add r0, ip
	cmp r0, #0
	blt _081F58F4
	asrs r1, r0, #0xa
	b _081F58FA
_081F58F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081F58FA:
	mov r3, sb
	ldrh r0, [r3]
	adds r0, r0, r1
	ldr r4, [sp, #0x34]
	strh r0, [r4]
	subs r3, r2, r6
	adds r1, r3, #1
	ldr r7, [sp, #0x40]
	movs r4, #2
	ldrsh r0, [r7, r4]
	muls r0, r1, r0
	movs r7, #0
	adds r4, r0, #0
	muls r4, r7, r4
	rsbs r2, r2, #0
	adds r0, r2, r6
	str r0, [sp, #0x44]
	mov r1, r8
	movs r7, #2
	ldrsh r0, [r1, r7]
	ldr r1, [sp, #0x44]
	muls r0, r1, r0
	adds r0, r4, r0
	adds r0, r0, r5
	add r0, ip
	cmp r0, #0
	blt _081F5934
	asrs r1, r0, #0xa
	b _081F593A
_081F5934:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081F593A:
	mov r4, sb
	ldrh r0, [r4, #2]
	adds r0, r0, r1
	ldr r7, [sp, #0x34]
	strh r0, [r7, #2]
	adds r1, r3, #1
	ldr r3, [sp, #0x40]
	movs r4, #4
	ldrsh r0, [r3, r4]
	muls r0, r1, r0
	movs r7, #0
	adds r4, r0, #0
	muls r4, r7, r4
	adds r1, r2, r6
	mov r2, r8
	movs r3, #4
	ldrsh r0, [r2, r3]
	muls r0, r1, r0
	adds r0, r4, r0
	adds r0, r0, r5
	add r0, ip
	cmp r0, #0
	blt _081F596C
	asrs r1, r0, #0xa
	b _081F5972
_081F596C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081F5972:
	mov r4, sb
	ldrh r0, [r4, #4]
	adds r0, r0, r1
	ldr r7, [sp, #0x34]
	strh r0, [r7, #4]
	ldr r0, [sp, #0x2c]
	mov r1, sl
	ldr r2, [sp, #0x34]
	bl FUN_081f57c8
	ldr r0, [sp, #0x3c]
	movs r1, #1
	add sl, r1
	ldr r2, [sp, #0x68]
	cmp sl, r2
	bge _081F5994
	b _081F5852
_081F5994:
	add sp, #0x48
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081f59a4
FUN_081f59a4: @ 0x081F59A4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	adds r3, r0, #0
	adds r7, r1, #0
	mov sb, r2
	movs r0, #0xdb
	lsls r0, r0, #3
	adds r2, r3, r0
	ldrb r1, [r2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r3, r0
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldrb r0, [r2]
	cmp r0, #0
	bne _081F5A64
	mov r5, sp
	add r1, sp, #8
	mov r8, r1
	adds r4, r3, #0
	movs r6, #5
_081F59E0:
	add r0, sp, #8
	ldrh r0, [r0]
	ldrh r1, [r4, #0x1c]
	subs r0, r0, r1
	strh r0, [r5]
	mov r3, r8
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #0x1e]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #0x20]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r0, #0
	ldrsh r2, [r5, r0]
	adds r1, r2, #0
	muls r1, r2, r1
	movs r3, #2
	ldrsh r0, [r5, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r3, #4
	ldrsh r0, [r5, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	cmp r1, sb
	ble _081F5A4E
	adds r0, r2, #0
	adds r1, r7, #0
	bl Div
	ldrh r1, [r4, #0x1c]
	adds r1, r1, r0
	strh r1, [r4, #0x1c]
	movs r1, #2
	ldrsh r0, [r5, r1]
	adds r1, r7, #0
	bl Div
	ldrh r1, [r4, #0x1e]
	adds r1, r1, r0
	strh r1, [r4, #0x1e]
	movs r3, #4
	ldrsh r0, [r5, r3]
	adds r1, r7, #0
	bl Div
	ldrh r1, [r4, #0x20]
	adds r1, r1, r0
	strh r1, [r4, #0x20]
_081F5A4E:
	ldr r0, [r4, #0x1c]
	ldr r1, [r4, #0x20]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r4, r0
	subs r6, #1
	cmp r6, #0
	bge _081F59E0
	b _081F5AFA
_081F5A64:
	ldrb r6, [r2]
	cmp r6, #0
	blt _081F5AFA
	add r5, sp, #0x10
	add r1, sp, #8
	mov r8, r1
	lsls r0, r6, #3
	adds r0, r0, r6
	lsls r0, r0, #3
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r4, r0, r3
_081F5A7C:
	mov r3, r8
	ldrh r0, [r3]
	ldrh r1, [r4, #0x1c]
	subs r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #0x1e]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #0x20]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r0, #0
	ldrsh r2, [r5, r0]
	adds r1, r2, #0
	muls r1, r2, r1
	movs r3, #2
	ldrsh r0, [r5, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r3, #4
	ldrsh r0, [r5, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	cmp r1, sb
	ble _081F5AE8
	adds r0, r2, #0
	adds r1, r7, #0
	bl Div
	ldrh r1, [r4, #0x1c]
	adds r1, r1, r0
	strh r1, [r4, #0x1c]
	movs r1, #2
	ldrsh r0, [r5, r1]
	adds r1, r7, #0
	bl Div
	ldrh r1, [r4, #0x1e]
	adds r1, r1, r0
	strh r1, [r4, #0x1e]
	movs r3, #4
	ldrsh r0, [r5, r3]
	adds r1, r7, #0
	bl Div
	ldrh r1, [r4, #0x20]
	adds r1, r1, r0
	strh r1, [r4, #0x20]
_081F5AE8:
	ldr r0, [r4, #0x1c]
	ldr r1, [r4, #0x20]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r0, _081F5B08 @ =0xFFFFFEDC
	adds r4, r4, r0
	subs r6, #1
	cmp r6, #0
	bge _081F5A7C
_081F5AFA:
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F5B08: .4byte 0xFFFFFEDC

	thumb_func_start FUN_081f5b0c
FUN_081f5b0c: @ 0x081F5B0C
	push {r4, r5, lr}
	ldr r2, [r1, #4]
	ldr r1, [r1]
	movs r4, #0x88
	lsls r4, r4, #1
	adds r3, r0, r4
	movs r5, #0x92
	lsls r5, r5, #1
	movs r4, #5
_081F5B1E:
	str r1, [r0, #0x1c]
	str r2, [r0, #0x20]
	str r1, [r3]
	str r2, [r3, #4]
	adds r3, r3, r5
	adds r0, r0, r5
	subs r4, #1
	cmp r4, #0
	bge _081F5B1E
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081f5b38
FUN_081f5b38: @ 0x081F5B38
	push {r4, r5, r6, r7, lr}
	movs r2, #0xdb
	lsls r2, r2, #3
	adds r1, r0, r2
	ldrb r2, [r1]
	lsls r1, r2, #3
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r0, r1
	ldr r2, [r1, #0x1c]
	ldr r3, [r1, #0x20]
	movs r1, #0x88
	lsls r1, r1, #1
	adds r5, r0, r1
	adds r4, r0, #0
	movs r7, #0x92
	lsls r7, r7, #1
	movs r6, #5
_081F5B60:
	ldr r0, [r4, #0x1c]
	ldr r1, [r4, #0x20]
	str r2, [r5]
	str r3, [r5, #4]
	adds r3, r1, #0
	adds r2, r0, #0
	adds r5, r5, r7
	adds r4, r4, r7
	subs r6, #1
	cmp r6, #0
	bge _081F5B60
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081f5b7c
FUN_081f5b7c: @ 0x081F5B7C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	movs r0, #0
	mov sl, r0
	mov sb, r0
	mov r5, r8
	mov r7, r8
	adds r7, #0x1c
_081F5B94:
	ldrh r0, [r7]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081F5BB8
	cmp r1, #0
	blt _081F5BB8
	ldr r0, _081F5BBC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081F5BB8
	ldr r0, _081F5BC0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081F5BC4
_081F5BB8:
	movs r4, #0
	b _081F5BD2
	.align 2, 0
_081F5BBC: .4byte 0x030046A8
_081F5BC0: .4byte 0x030046AC
_081F5BC4:
	ldr r0, _081F5BE4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081F5BD2:
	adds r6, r7, #0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081F5BE8
	adds r0, #4
	b _081F5BF4
	.align 2, 0
_081F5BE4: .4byte 0x030046A4
_081F5BE8:
	ldr r0, _081F5C08 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081F5BF4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081F5C0C
	cmp r2, #2
	beq _081F5C10
	b _081F5C14
	.align 2, 0
_081F5C08: .4byte 0x030046A4
_081F5C0C:
	ldrb r0, [r6, #4]
	b _081F5C12
_081F5C10:
	ldrb r0, [r6]
_081F5C12:
	subs r1, r1, r0
_081F5C14:
	movs r2, #2
	ldrsh r0, [r7, r2]
	cmp r0, r1
	beq _081F5C7C
	cmp r0, r1
	bge _081F5C6E
	subs r0, r1, r0
	cmp r0, #0
	bge _081F5C28
	rsbs r0, r0, #0
_081F5C28:
	cmp r0, #0xff
	ble _081F5C46
	movs r0, #0xdb
	lsls r0, r0, #3
	add r0, r8
	ldrb r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	add r0, r8
	ldrh r0, [r0, #0x1e]
	strh r0, [r5, #0x1e]
	b _081F5C7C
_081F5C46:
	strh r1, [r5, #0x1e]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _081F5C62
	adds r0, r5, #0
	adds r0, #0x1c
	movs r1, #1
	bl FUN_081f624c
	movs r0, #0x1e
	strh r0, [r4]
_081F5C62:
	mov r2, sb
	cmp r2, #5
	bne _081F5C7C
	movs r0, #1
	mov sl, r0
	b _081F5C7C
_081F5C6E:
	subs r0, r1, r0
	movs r1, #0x1e
	bl Div
	ldrh r1, [r5, #0x1e]
	adds r1, r1, r0
	strh r1, [r5, #0x1e]
_081F5C7C:
	movs r2, #0x92
	lsls r2, r2, #1
	adds r5, r5, r2
	adds r7, r7, r2
	movs r0, #1
	add sb, r0
	mov r2, sb
	cmp r2, #5
	bgt _081F5C90
	b _081F5B94
_081F5C90:
	ldr r4, _081F5CB8 @ =0x000006DB
	add r4, r8
	ldrb r0, [r4]
	cmp r0, #0
	bne _081F5CAA
	mov r0, sl
	cmp r0, #0
	beq _081F5CAA
	ldr r0, _081F5CBC @ =0x000003D9
	bl PlaySound_082406e0
	movs r0, #0x14
	strb r0, [r4]
_081F5CAA:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F5CB8: .4byte 0x000006DB
_081F5CBC: .4byte 0x000003D9

	thumb_func_start FUN_081f5cc0
FUN_081f5cc0: @ 0x081F5CC0
	push {r4, r5, lr}
	adds r2, r0, #0
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r3, #0x92
	lsls r3, r3, #1
	ldr r5, _081F5CF8 @ =0x000005B4
	adds r4, r2, r5
_081F5CD2:
	ldrh r0, [r1]
	ldrh r5, [r2, #0x1c]
	adds r0, r0, r5
	strh r0, [r2, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r5, [r2, #0x1e]
	adds r0, r0, r5
	strh r0, [r2, #0x1e]
	ldrh r0, [r1, #4]
	ldrh r5, [r2, #0x20]
	adds r0, r0, r5
	strh r0, [r2, #0x20]
	movs r5, #0
	ldrsh r0, [r1, r5]
	cmp r0, #0
	blt _081F5CFC
	asrs r0, r0, #1
	b _081F5D02
	.align 2, 0
_081F5CF8: .4byte 0x000005B4
_081F5CFC:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_081F5D02:
	strh r0, [r1]
	movs r5, #2
	ldrsh r0, [r1, r5]
	cmp r0, #0
	blt _081F5D10
	asrs r0, r0, #1
	b _081F5D16
_081F5D10:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_081F5D16:
	strh r0, [r1, #2]
	movs r5, #4
	ldrsh r0, [r1, r5]
	cmp r0, #0
	blt _081F5D24
	asrs r0, r0, #1
	b _081F5D2A
_081F5D24:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_081F5D2A:
	strh r0, [r1, #4]
	adds r2, r2, r3
	adds r1, r1, r3
	cmp r2, r4
	ble _081F5CD2
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081f5d3c
FUN_081f5d3c: @ 0x081F5D3C
	push {r4, lr}
	adds r4, r0, #0
	adds r2, r4, #0
	adds r2, #0xfd
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x2c
	movs r1, #0x99
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	ldr r0, _081F5D68 @ =0x00000107
	adds r1, r4, r0
	movs r0, #6
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081F5D68: .4byte 0x00000107

	thumb_func_start FUN_081f5d6c
FUN_081f5d6c: @ 0x081F5D6C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r2, r0, #0
	movs r0, #1
	mov sb, r0
	adds r7, r2, #0
	adds r7, #0xdc
	adds r6, r2, #0
	adds r6, #0xfd
	adds r5, r2, #0
	adds r3, r2, #0
	adds r3, #0x2c
	ldr r1, _081F5DA8 @ =0x00000107
	adds r1, r1, r2
	mov r8, r1
_081F5D90:
	ldrb r1, [r6]
	mov r0, sb
	ands r0, r1
	cmp r0, #0
	beq _081F5DCA
	ldrb r0, [r6, #0xa]
	adds r4, r0, #0
	cmp r4, #0
	beq _081F5DAC
	subs r0, #1
	strb r0, [r6, #0xa]
	b _081F5DCA
	.align 2, 0
_081F5DA8: .4byte 0x00000107
_081F5DAC:
	adds r0, r3, #0
	movs r1, #0xd1
	lsls r1, r1, #1
	str r2, [sp]
	str r3, [sp, #4]
	bl Video_SetAuxSpritePltt
	mov r0, r8
	strb r4, [r0]
	ldrb r1, [r6]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r6]
	ldr r3, [sp, #4]
	ldr r2, [sp]
_081F5DCA:
	ldrb r1, [r6]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081F5DE6
	ldrh r0, [r7]
	cmp r0, #0
	beq _081F5DDE
	subs r0, #1
	strh r0, [r7]
_081F5DDE:
	ldr r0, [r5]
	mov r1, sb
	orrs r0, r1
	b _081F5E22
_081F5DE6:
	adds r0, r5, #0
	adds r0, #0xdc
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _081F5E24
	lsrs r0, r0, #0x12
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	beq _081F5E06
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _081F5E0C
_081F5E06:
	ldr r0, [r5]
	mov r1, sb
	orrs r0, r1
_081F5E0C:
	str r0, [r5]
	ldrh r0, [r7]
	subs r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _081F5E24
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
_081F5E22:
	str r0, [r5]
_081F5E24:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r7, r7, r0
	adds r6, r6, r0
	adds r5, r5, r0
	adds r3, r3, r0
	add r8, r0
	ldr r1, _081F5E48 @ =0x000005B4
	adds r0, r2, r1
	cmp r5, r0
	ble _081F5D90
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F5E48: .4byte 0x000005B4

	thumb_func_start FUN_081f5e4c
FUN_081f5e4c: @ 0x081F5E4C
	bx lr
	.align 2, 0

	thumb_func_start FUN_081f5e50
FUN_081f5e50: @ 0x081F5E50
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	adds r7, r0, #0
	adds r6, r1, #0
	mov r8, r2
	movs r0, #0x90
	lsls r0, r0, #1
	add r0, r8
	ldr r0, [r0]
	mov sb, r0
	adds r4, r6, #0
	adds r4, #0x44
	ldrh r5, [r4]
	cmp r5, #0
	beq _081F5E78
	b _081F6006
_081F5E78:
	adds r0, r7, #0
	bl Hitbox_ApplyDamage
	adds r0, r7, #0
	adds r0, #0x44
	ldrh r0, [r0]
	strh r0, [r4]
	mov r0, r8
	bl FUN_081f5d3c
	add r0, sp, #0x14
	add r4, sp, #0x18
	str r5, [sp, #0x14]
	adds r1, r4, #0
	ldr r2, _081F5EF8 @ =0x05000002
	bl CpuSet
	ldrh r1, [r6, #0x3e]
	mov r3, r8
	adds r3, #0x1c
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	adds r0, r6, #0
	movs r2, #0
	bl FUN_0805fe7c
	add r1, sp, #0x10
	movs r0, #6
	strh r0, [r1]
	ldrh r0, [r6, #0x3e]
	strh r0, [r1, #2]
	movs r0, #0x19
	bl FUN_080ec79c
	ldr r2, _081F5EFC @ =0x000006E4
	add r2, sb
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r6, #0
	adds r0, #0x43
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _081F5EE2
	b _081F6006
_081F5EE2:
	ldrh r1, [r7, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081F5F00
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r3, [r0]
	b _081F5F62
	.align 2, 0
_081F5EF8: .4byte 0x05000002
_081F5EFC: .4byte 0x000006E4
_081F5F00:
	add r3, sp, #0x20
	adds r5, r6, #0
	adds r5, #0xc
	adds r4, r7, #0
	adds r4, #0xc
	ldrh r2, [r7, #0xc]
	ldrh r0, [r6, #0xc]
	subs r2, r2, r0
	strh r2, [r3]
	ldrh r0, [r4, #2]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4, #4]
	ldrh r0, [r5, #4]
	subs r0, r1, r0
	strh r0, [r3, #4]
	lsls r2, r2, #0x10
	cmp r2, #0
	bne _081F5F50
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _081F5F50
	ldr r0, _081F5F44 @ =0x030046B8
	ldr r1, [r0]
	adds r1, #1
	ldr r2, _081F5F48 @ =0x000003FF
	ands r1, r2
	str r1, [r0]
	lsls r1, r1, #1
	ldr r0, _081F5F4C @ =0x0203B400
	adds r1, r1, r0
	ldrb r3, [r1]
	b _081F5F62
	.align 2, 0
_081F5F44: .4byte 0x030046B8
_081F5F48: .4byte 0x000003FF
_081F5F4C: .4byte 0x0203B400
_081F5F50:
	movs r1, #0
	ldrsh r0, [r3, r1]
	add r1, sp, #0x20
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
_081F5F62:
	mov r2, r8
	ldr r0, [r2, #0x1c]
	ldr r1, [r2, #0x20]
	str r0, [sp, #0x30]
	str r1, [sp, #0x34]
	ldr r0, _081F6018 @ =0x0203B400
	mov r8, r0
	ldr r1, _081F601C @ =0x030046B8
	mov sl, r1
	ldr r4, [r1]
	adds r4, #1
	ldr r6, _081F6020 @ =0x000003FF
	ands r4, r6
	lsls r0, r4, #1
	add r0, r8
	ldr r2, [sp, #0x30]
	asrs r1, r2, #0x10
	ldrb r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _081F6024 @ =0x0000FFFF
	mov sb, r0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x30]
	adds r4, #1
	ands r4, r6
	lsls r0, r4, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	subs r0, #0x10
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	adds r3, r3, r0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r5, _081F6028 @ =0xFFFF0000
	ldr r0, [sp, #0x28]
	ands r0, r5
	movs r1, #0x3c
	orrs r0, r1
	mov r1, sb
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x28]
	add r2, sp, #0x28
	ldr r0, [r2, #4]
	ands r0, r5
	movs r1, #0x28
	orrs r0, r1
	str r0, [r2, #4]
	adds r4, #1
	ands r4, r6
	lsls r0, r4, #1
	add r0, r8
	ldrh r5, [r0]
	movs r0, #7
	ands r5, r0
	adds r5, #4
	adds r4, #1
	ands r4, r6
	mov r1, sl
	str r4, [r1]
	lsls r4, r4, #1
	add r4, r8
	ldrh r1, [r4]
	ands r1, r0
	adds r1, #8
	add r0, sp, #0x30
	str r5, [sp]
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	movs r1, #1
	str r1, [sp, #0xc]
	movs r1, #2
	bl FUN_080ddcc8
_081F6006:
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F6018: .4byte 0x0203B400
_081F601C: .4byte 0x030046B8
_081F6020: .4byte 0x000003FF
_081F6024: .4byte 0x0000FFFF
_081F6028: .4byte 0xFFFF0000

	thumb_func_start FUN_081f602c
FUN_081f602c: @ 0x081F602C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r6, r0, #0
	str r1, [sp, #0x1c]
	str r2, [sp, #0x20]
	mov sb, r3
	ldr r0, [sp, #0x50]
	mov sl, r0
	ldr r2, _081F6100 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x20
	orrs r0, r3
	ldr r1, _081F6104 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	mov r8, r1
	adds r5, r6, #0
	adds r5, #0x1c
	adds r4, r6, #0
	adds r4, #0x48
	movs r7, #5
_081F6078:
	movs r0, #0x10
	str r0, [sp]
	add r1, sp, #0xc
	str r1, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	ldr r2, _081F6108 @ =0x00002401
	movs r3, #0
	bl Hitbox_Init
	mov r0, sb
	str r0, [sp]
	ldr r1, [sp, #0x44]
	str r1, [sp, #4]
	adds r0, r4, #0
	ldr r1, [sp, #0x1c]
	ldr r2, [sp, #0x20]
	movs r3, #0
	bl Hitbox_SetAttack
	adds r0, r4, #0
	ldr r1, _081F610C @ =FUN_081f5e4c
	adds r2, r6, #0
	bl Hitbox_SetHandler
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	movs r2, #0x92
	lsls r2, r2, #1
	adds r5, r5, r2
	adds r4, r4, r2
	subs r7, #1
	cmp r7, #0
	bge _081F6078
	adds r7, r6, #0
	adds r7, #0x1c
	adds r4, r6, #0
	adds r4, #0x98
	adds r5, r6, #0
_081F60D0:
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	ldr r2, _081F6110 @ =0x00005005
	movs r3, #0
	bl Hitbox_Init
	ldr r2, _081F6114 @ =0x000005B4
	adds r0, r6, r2
	cmp r5, r0
	bne _081F611C
	ldr r1, _081F6118 @ =0x0000064C
	adds r0, r6, r1
	ldr r1, [sp, #0x48]
	ldr r2, [sp, #0x4c]
	mov r3, sl
	bl Hitbox_SetPowerAndAttributes
	b _081F612A
	.align 2, 0
_081F6100: .4byte 0xFFFF0000
_081F6104: .4byte 0x0000FFFF
_081F6108: .4byte 0x00002401
_081F610C: .4byte FUN_081f5e4c
_081F6110: .4byte 0x00005005
_081F6114: .4byte 0x000005B4
_081F6118: .4byte 0x0000064C
_081F611C:
	adds r0, r4, #0
	ldr r2, [sp, #0x48]
	lsls r1, r2, #1
	ldr r2, [sp, #0x4c]
	mov r3, sl
	bl Hitbox_SetPowerAndAttributes
_081F612A:
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	ldr r1, _081F6168 @ =FUN_081f5e50
	adds r2, r5, #0
	bl Hitbox_SetHandler
	adds r0, r4, #0
	bl Hitbox_Register
	movs r0, #0x92
	lsls r0, r0, #1
	adds r7, r7, r0
	adds r4, r4, r0
	adds r5, r5, r0
	ldr r1, _081F616C @ =0x000005B4
	adds r0, r6, r1
	cmp r5, r0
	ble _081F60D0
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F6168: .4byte FUN_081f5e50
_081F616C: .4byte 0x000005B4

	thumb_func_start FUN_081f6170
FUN_081f6170: @ 0x081F6170
	push {r4, r5, r6, lr}
	movs r5, #0
	adds r2, r0, #0
	adds r2, #0xfd
	adds r3, r0, #0
	movs r6, #0x92
	lsls r6, r6, #1
	movs r4, #5
_081F6180:
	movs r0, #0x81
	lsls r0, r0, #1
	adds r1, r3, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081F6192
	subs r0, #1
	strh r0, [r1]
	b _081F61A4
_081F6192:
	cmp r5, #1
	bgt _081F61A4
	movs r0, #3
	strh r0, [r1]
	ldrb r1, [r2]
	movs r0, #4
	orrs r0, r1
	strb r0, [r2]
	adds r5, #1
_081F61A4:
	adds r2, r2, r6
	adds r3, r3, r6
	subs r4, #1
	cmp r4, #0
	bge _081F6180
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081f61b4
FUN_081f61b4: @ 0x081F61B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r1, #4
	mov sb, r1
	subs r1, #9
	mov sl, r1
	adds r6, r0, #0
	adds r6, #0x48
	adds r5, r0, #0
	adds r5, #0x98
	adds r4, r0, #0
	adds r4, #0x1c
	adds r7, r0, #0
	adds r7, #0xfd
	movs r0, #5
	mov r8, r0
_081F61DA:
	ldrb r1, [r7]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _081F6216
	mov r0, sb
	ands r0, r1
	cmp r0, #0
	beq _081F6216
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r6, #0
	bl Hitbox_Register
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldrh r1, [r4, #0x32]
	mov r0, sl
	ands r0, r1
	strh r0, [r4, #0x32]
	ldrh r1, [r5, #6]
	mov r0, sl
	ands r0, r1
	b _081F6224
_081F6216:
	ldrh r1, [r4, #0x32]
	mov r0, sb
	orrs r0, r1
	strh r0, [r4, #0x32]
	ldrh r1, [r5, #6]
	mov r0, sb
	orrs r0, r1
_081F6224:
	strh r0, [r5, #6]
	movs r1, #0x92
	lsls r1, r1, #1
	adds r6, r6, r1
	adds r5, r5, r1
	adds r4, r4, r1
	adds r7, r7, r1
	movs r0, #1
	rsbs r0, r0, #0
	add r8, r0
	mov r1, r8
	cmp r1, #0
	bge _081F61DA
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081f624c
FUN_081f624c: @ 0x081F624C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x38
	adds r5, r0, #0
	adds r6, r1, #0
	movs r4, #0
	cmp r4, r6
	bge _081F62FE
	movs r0, #1
	mov r8, r0
	movs r7, #0
_081F6264:
	adds r1, r4, #0
	mov r0, r8
	ands r1, r0
	cmp r1, #0
	beq _081F62B8
	movs r0, #0xc
	str r0, [sp]
	movs r0, #0x12
	str r0, [sp, #4]
	lsls r0, r4, #6
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	movs r0, #0x30
	str r0, [sp, #0x10]
	mov r0, r8
	str r0, [sp, #0x14]
	movs r0, #2
	str r0, [sp, #0x18]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x1c]
	str r7, [sp, #0x20]
	ldr r0, _081F62B0 @ =0x0000F422
	str r0, [sp, #0x24]
	ldr r0, _081F62B4 @ =0x0000121B
	str r0, [sp, #0x28]
	str r7, [sp, #0x2c]
	str r7, [sp, #0x30]
	movs r0, #0xd8
	str r0, [sp, #0x34]
	adds r0, r5, #0
	movs r1, #8
	movs r2, #0x10
	movs r3, #4
	bl FUN_081ee53c
	b _081F62F8
	.align 2, 0
_081F62B0: .4byte 0x0000F422
_081F62B4: .4byte 0x0000121B
_081F62B8:
	movs r0, #0xc
	str r0, [sp]
	movs r0, #0x12
	str r0, [sp, #4]
	lsls r0, r4, #6
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	movs r0, #0x30
	str r0, [sp, #0x10]
	mov r0, r8
	str r0, [sp, #0x14]
	movs r0, #2
	str r0, [sp, #0x18]
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	ldr r0, _081F630C @ =0x0000F422
	str r0, [sp, #0x24]
	ldr r0, _081F6310 @ =0x0000121B
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r1, [sp, #0x30]
	movs r0, #0xd8
	str r0, [sp, #0x34]
	adds r0, r5, #0
	movs r1, #8
	movs r2, #0x10
	movs r3, #4
	bl FUN_081ee53c
_081F62F8:
	adds r4, #1
	cmp r4, r6
	blt _081F6264
_081F62FE:
	add sp, #0x38
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F630C: .4byte 0x0000F422
_081F6310: .4byte 0x0000121B

	thumb_func_start FUN_081f6314
FUN_081f6314: @ 0x081F6314
	bx lr
	.align 2, 0

	thumb_func_start FUN_081f6318
FUN_081f6318: @ 0x081F6318
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _081F635C @ =0x000006EA
	adds r6, r4, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081F6354
	adds r0, r4, #0
	bl FUN_081f5788
	adds r0, r4, #0
	bl FUN_081f57a8
	ldr r0, _081F6360 @ =0x000006E7
	adds r2, r4, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	movs r1, #1
	lsls r1, r0
	ldr r0, [r5, #0x38]
	bics r0, r1
	str r0, [r5, #0x38]
	movs r0, #0xff
	strb r0, [r2]
	ldr r0, _081F6364 @ =0x000006E6
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	strb r0, [r6]
_081F6354:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081F635C: .4byte 0x000006EA
_081F6360: .4byte 0x000006E7
_081F6364: .4byte 0x000006E6

	thumb_func_start FUN_081f6368
FUN_081f6368: @ 0x081F6368
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r1, #0
	ldr r0, _081F63A8 @ =0x000006EA
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081F63C4
	ldr r2, _081F63AC @ =0x000006DC
	adds r1, r5, r2
	movs r4, #0
	str r4, [sp]
	mov r0, sp
	ldr r2, _081F63B0 @ =0x05000002
	bl CpuSet
	movs r1, #0xdb
	lsls r1, r1, #3
	adds r0, r5, r1
	strb r4, [r0]
	strb r4, [r6]
	movs r1, #1
	ldr r2, _081F63B4 @ =0x000006E4
	adds r0, r5, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	ands r0, r1
	cmp r0, #0
	beq _081F63B8
	movs r0, #1
	b _081F63BA
	.align 2, 0
_081F63A8: .4byte 0x000006EA
_081F63AC: .4byte 0x000006DC
_081F63B0: .4byte 0x05000002
_081F63B4: .4byte 0x000006E4
_081F63B8:
	movs r0, #0
_081F63BA:
	cmp r0, #0
	beq _081F63C4
	ldr r0, _081F6440 @ =0x000001A5
	bl PlaySound_082406e0
_081F63C4:
	movs r1, #0xdb
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrb r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r5, r0
	adds r3, r0, #0
	adds r3, #0x1c
	ldr r4, _081F6444 @ =0x000006DC
	adds r2, r5, r4
	ldrh r1, [r2]
	ldrh r4, [r0, #0x1c]
	adds r1, r1, r4
	strh r1, [r0, #0x1c]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r3, #4]
	adds r0, r0, r2
	strh r0, [r3, #4]
	ldr r4, _081F6448 @ =0x000006DE
	adds r1, r5, r4
	ldrh r0, [r1]
	subs r0, #0xc
	strh r0, [r1]
	ldr r2, _081F644C @ =0x000061A8
	adds r0, r5, #0
	movs r1, #4
	bl FUN_081f59a4
	adds r0, r5, #0
	bl FUN_081f5610
	adds r0, r5, #0
	bl FUN_081f61b4
	adds r0, r5, #0
	bl FUN_081f5d6c
	adds r0, r5, #0
	bl FUN_081f5610
	cmp r0, #0
	bge _081F6438
	ldr r0, _081F6450 @ =0x000006E6
	adds r1, r5, r0
	movs r0, #6
	strb r0, [r1]
	ldr r2, _081F6454 @ =0x000006EA
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
_081F6438:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081F6440: .4byte 0x000001A5
_081F6444: .4byte 0x000006DC
_081F6448: .4byte 0x000006DE
_081F644C: .4byte 0x000061A8
_081F6450: .4byte 0x000006E6
_081F6454: .4byte 0x000006EA

	thumb_func_start FUN_081f6458
FUN_081f6458: @ 0x081F6458
	push {lr}
	movs r2, #1
	movs r3, #0x88
	lsls r3, r3, #2
	adds r1, r0, r3
	subs r3, #0xfc
_081F6464:
	lsls r0, r2, #5
	strb r0, [r1]
	adds r1, r1, r3
	adds r2, #1
	cmp r2, #5
	ble _081F6464
	pop {r0}
	bx r0

	thumb_func_start FUN_081f6474
FUN_081f6474: @ 0x081F6474
	push {lr}
	movs r2, #5
	movs r1, #0xd6
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #0
	ldr r3, _081F6494 @ =0xFFFFFEDC
_081F6482:
	strb r1, [r0]
	adds r1, #8
	adds r0, r0, r3
	subs r2, #1
	cmp r2, #0
	bgt _081F6482
	pop {r0}
	bx r0
	.align 2, 0
_081F6494: .4byte 0xFFFFFEDC

	thumb_func_start FUN_081f6498
FUN_081f6498: @ 0x081F6498
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	movs r6, #1
	mov r5, sp
	movs r0, #2
	mov sl, r0
	ldr r1, _081F64DC @ =0x085B0A08
	mov r8, r1
	movs r0, #0x88
	lsls r0, r0, #2
	adds r4, r7, r0
	mov sb, r8
_081F64BA:
	ldrb r0, [r4]
	adds r0, #2
	strb r0, [r4]
	ldrb r2, [r4]
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #1
	cmp r0, #0
	blt _081F64E0
	asrs r1, r0, #0xc
	b _081F64E6
	.align 2, 0
_081F64DC: .4byte 0x085B0A08
_081F64E0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F64E6:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	lsls r0, r2, #1
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _081F6502
	asrs r0, r0, #0xc
	b _081F6508
_081F6502:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F6508:
	strh r0, [r5, #4]
	adds r0, r7, #0
	mov r1, sp
	adds r2, r6, #0
	bl FUN_081f57e0
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r4, r0
	adds r6, #1
	cmp r6, #5
	ble _081F64BA
	movs r1, #0xdd
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0x1e
	bl Mod
	cmp r0, #0
	bne _081F65DE
	movs r1, #0xdb
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrb r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r7, r0
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r1, sp, #8
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	adds r6, r1, #0
	cmp r3, #0
	blt _081F6578
	cmp r2, #0
	blt _081F6578
	ldr r0, _081F657C @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _081F6578
	ldr r0, _081F6580 @ =0x030046AC
	ldr r0, [r0]
	cmp r2, r0
	blo _081F6584
_081F6578:
	movs r4, #0
	b _081F6592
	.align 2, 0
_081F657C: .4byte 0x030046A8
_081F6580: .4byte 0x030046AC
_081F6584:
	ldr r0, _081F65A4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r2, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_081F6592:
	adds r5, r6, #0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081F65A8
	adds r0, #4
	b _081F65B4
	.align 2, 0
_081F65A4: .4byte 0x030046A4
_081F65A8:
	ldr r0, _081F65C8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081F65B4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081F65CC
	cmp r2, #2
	beq _081F65D0
	b _081F65D4
	.align 2, 0
_081F65C8: .4byte 0x030046A4
_081F65CC:
	ldrb r0, [r5, #4]
	b _081F65D2
_081F65D0:
	ldrb r0, [r5]
_081F65D2:
	subs r1, r1, r0
_081F65D4:
	strh r1, [r6, #2]
	adds r0, r6, #0
	movs r1, #2
	bl FUN_081f624c
_081F65DE:
	adds r0, r7, #0
	bl FUN_081f5cc0
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081f65f4
FUN_081f65f4: @ 0x081F65F4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	add r4, sp, #4
	movs r5, #0
	str r5, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _081F6650 @ =0x05000002
	bl CpuSet
	movs r1, #0xdd
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r8, r4
	cmp r0, #5
	bgt _081F668C
	subs r1, #0xe
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r3, r0, #0
	adds r3, #0x80
	movs r1, #0xff
	mov r5, r8
	ands r3, r1
	ldr r2, _081F6654 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #6
	mov sl, r2
	cmp r0, #0
	blt _081F6658
	asrs r1, r0, #0xc
	b _081F665E
	.align 2, 0
_081F6650: .4byte 0x05000002
_081F6654: .4byte 0x085B0A08
_081F6658:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F665E:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	lsls r0, r3, #1
	add r0, sl
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x40
	muls r0, r1, r0
	cmp r0, #0
	blt _081F6678
	asrs r0, r0, #0xc
	b _081F667E
_081F6678:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F667E:
	strh r0, [r5, #4]
	movs r0, #0x20
	mov r2, r8
	strh r0, [r2, #2]
	adds r0, r7, #0
	mov r1, r8
	b _081F67CA
_081F668C:
	cmp r0, #0xb
	bgt _081F6698
	ldr r0, _081F6694 @ =0x0000FFE8
	b _081F67C4
	.align 2, 0
_081F6694: .4byte 0x0000FFE8
_081F6698:
	cmp r0, #0x15
	bgt _081F66AC
	ldr r0, _081F66A8 @ =0x0000FFF8
	mov r2, r8
	strh r0, [r2, #2]
	adds r0, r7, #0
	mov r1, r8
	b _081F67CA
	.align 2, 0
_081F66A8: .4byte 0x0000FFF8
_081F66AC:
	cmp r0, #0x1d
	bgt _081F670A
	ldr r1, _081F66D8 @ =0x000006DA
	adds r0, r7, r1
	mov r4, r8
	ldrb r3, [r0]
	movs r5, #0xc
	ldr r2, _081F66DC @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	mov sl, r2
	cmp r0, #0
	blt _081F66E0
	asrs r1, r0, #0xc
	b _081F66E6
	.align 2, 0
_081F66D8: .4byte 0x000006DA
_081F66DC: .4byte 0x085B0A08
_081F66E0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F66E6:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r3, #1
	add r0, sl
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _081F66FE
	asrs r0, r0, #0xc
	b _081F6704
_081F66FE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F6704:
	strh r0, [r4, #4]
	movs r0, #0x2a
	b _081F67C4
_081F670A:
	cmp r0, #0x27
	bgt _081F6768
	ldr r2, _081F6734 @ =0x000006DA
	adds r0, r7, r2
	mov r4, r8
	ldrb r3, [r0]
	ldr r2, _081F6738 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	mov sl, r2
	cmp r0, #0
	blt _081F673C
	asrs r1, r0, #0xc
	b _081F6742
	.align 2, 0
_081F6734: .4byte 0x000006DA
_081F6738: .4byte 0x085B0A08
_081F673C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F6742:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r3, #1
	add r0, sl
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _081F675C
	asrs r0, r0, #0xc
	b _081F6762
_081F675C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F6762:
	strh r0, [r4, #4]
	movs r0, #0xc
	b _081F67C4
_081F6768:
	cmp r0, #0x35
	bgt _081F67D8
	ldr r2, _081F6794 @ =0x000006DA
	adds r0, r7, r2
	mov r4, r8
	ldrb r3, [r0]
	movs r5, #0x30
	ldr r2, _081F6798 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	mov sl, r2
	cmp r0, #0
	blt _081F679C
	asrs r1, r0, #0xc
	b _081F67A2
	.align 2, 0
_081F6794: .4byte 0x000006DA
_081F6798: .4byte 0x085B0A08
_081F679C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F67A2:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r3, #1
	add r0, sl
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _081F67BA
	asrs r0, r0, #0xc
	b _081F67C0
_081F67BA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F67C0:
	strh r0, [r4, #4]
	ldr r0, _081F67D4 @ =0x0000FFE0
_081F67C4:
	mov r1, r8
	strh r0, [r1, #2]
	adds r0, r7, #0
_081F67CA:
	movs r2, #5
	bl FUN_081f57e0
	b _081F6892
	.align 2, 0
_081F67D4: .4byte 0x0000FFE0
_081F67D8:
	movs r2, #0xdb
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r5, [r0]
	movs r5, #1
	mov r6, r8
	movs r0, #0xff
	mov sb, r0
	ldr r1, _081F6818 @ =0x085B0A08
	mov sl, r1
	movs r2, #0x88
	lsls r2, r2, #2
	adds r4, r7, r2
	movs r3, #8
_081F67F4:
	ldr r1, _081F681C @ =0x000006DA
	adds r0, r7, r1
	ldrb r2, [r0]
	ldr r0, _081F6818 @ =0x085B0A08
	mov ip, r0
	adds r0, r2, #0
	adds r0, #0x40
	mov r1, sb
	ands r0, r1
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _081F6820
	asrs r1, r0, #0xc
	b _081F6826
	.align 2, 0
_081F6818: .4byte 0x085B0A08
_081F681C: .4byte 0x000006DA
_081F6820:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F6826:
	movs r0, #0
	strh r1, [r6]
	strh r0, [r6, #2]
	mov r0, sb
	ands r2, r0
	lsls r0, r2, #1
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _081F6842
	asrs r0, r0, #0xc
	b _081F6848
_081F6842:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F6848:
	strh r0, [r6, #4]
	ldrb r0, [r4]
	adds r0, #0xa
	strb r0, [r4]
	ldrb r0, [r4]
	adds r0, #0x40
	mov r2, sb
	ands r0, r2
	lsls r0, r0, #1
	add r0, sl
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x16
	muls r0, r5, r0
	muls r0, r1, r0
	cmp r0, #0
	blt _081F686E
	asrs r0, r0, #0xc
	b _081F6874
_081F686E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F6874:
	strh r0, [r6, #2]
	adds r0, r7, #0
	adds r1, r6, #0
	adds r2, r5, #0
	str r3, [sp, #0xc]
	bl FUN_081f57e0
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r4, r0
	ldr r3, [sp, #0xc]
	adds r3, #8
	adds r5, #1
	cmp r5, #5
	ble _081F67F4
_081F6892:
	movs r1, #0xdd
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0x1e
	bl Mod
	cmp r0, #0
	bne _081F6954
	movs r1, #0xdb
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrb r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r7, r0
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [sp, #4]
	str r1, [sp, #8]
	add r0, sp, #4
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r1, r8
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081F68EA
	cmp r1, #0
	blt _081F68EA
	ldr r0, _081F68F0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081F68EA
	ldr r0, _081F68F4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081F68F8
_081F68EA:
	movs r5, #0
	b _081F6906
	.align 2, 0
_081F68F0: .4byte 0x030046A8
_081F68F4: .4byte 0x030046AC
_081F68F8:
	ldr r0, _081F6918 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081F6906:
	mov r4, r8
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081F691C
	adds r0, #4
	b _081F6928
	.align 2, 0
_081F6918: .4byte 0x030046A4
_081F691C:
	ldr r0, _081F693C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081F6928:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081F6940
	cmp r2, #2
	beq _081F6944
	b _081F6948
	.align 2, 0
_081F693C: .4byte 0x030046A4
_081F6940:
	ldrb r0, [r4, #4]
	b _081F6946
_081F6944:
	ldrb r0, [r4]
_081F6946:
	subs r1, r1, r0
_081F6948:
	mov r2, r8
	strh r1, [r2, #2]
	mov r0, r8
	movs r1, #1
	bl FUN_081f624c
_081F6954:
	adds r0, r7, #0
	bl FUN_081f5cc0
	adds r0, r7, #0
	bl FUN_081f5b7c
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r2, #0x92
	lsls r2, r2, #1
	movs r5, #5
_081F696C:
	ldrh r0, [r1]
	cmp r0, #0
	beq _081F6976
	subs r0, #1
	strh r0, [r1]
_081F6976:
	adds r1, r1, r2
	subs r5, #1
	cmp r5, #0
	bge _081F696C
	ldr r2, _081F699C @ =0x000006DB
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081F698C
	subs r0, #1
	strb r0, [r1]
_081F698C:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F699C: .4byte 0x000006DB

	thumb_func_start FUN_081f69a0
FUN_081f69a0: @ 0x081F69A0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	adds r7, r0, #0
	movs r5, #2
	ldr r3, _081F69E0 @ =0xFFFF0000
	mov r6, sp
	movs r0, #0xd1
	lsls r0, r0, #2
	adds r4, r7, r0
_081F69B2:
	lsls r2, r5, #3
	movs r1, #0xdd
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r0, #0x10
	ldrb r1, [r4]
	adds r0, r0, r1
	strb r0, [r4]
	ldr r1, _081F69E4 @ =0x085B0A08
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _081F69E8
	asrs r0, r0, #0xc
	b _081F69EE
	.align 2, 0
_081F69E0: .4byte 0xFFFF0000
_081F69E4: .4byte 0x085B0A08
_081F69E8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F69EE:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp]
	ands r0, r3
	orrs r0, r1
	str r0, [sp]
	ldr r0, [r6, #4]
	ands r0, r3
	str r0, [r6, #4]
	ldr r1, _081F6A80 @ =0x0000FFFF
	ldr r0, [sp]
	ands r0, r1
	str r0, [sp]
	adds r0, r7, #0
	mov r1, sp
	adds r2, r5, #0
	str r3, [sp, #0x10]
	bl FUN_081f57e0
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r4, r0
	adds r5, #1
	ldr r3, [sp, #0x10]
	cmp r5, #5
	ble _081F69B2
	movs r1, #0xdd
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl Mod
	cmp r0, #0
	bne _081F6AE6
	movs r1, #0xdb
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrb r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r7, r0
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r1, sp, #8
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	adds r6, r1, #0
	cmp r3, #0
	blt _081F6A7A
	cmp r2, #0
	blt _081F6A7A
	ldr r0, _081F6A84 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _081F6A7A
	ldr r0, _081F6A88 @ =0x030046AC
	ldr r0, [r0]
	cmp r2, r0
	blo _081F6A8C
_081F6A7A:
	movs r4, #0
	b _081F6A9A
	.align 2, 0
_081F6A80: .4byte 0x0000FFFF
_081F6A84: .4byte 0x030046A8
_081F6A88: .4byte 0x030046AC
_081F6A8C:
	ldr r0, _081F6AAC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r2, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_081F6A9A:
	adds r5, r6, #0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081F6AB0
	adds r0, #4
	b _081F6ABC
	.align 2, 0
_081F6AAC: .4byte 0x030046A4
_081F6AB0:
	ldr r0, _081F6AD0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081F6ABC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081F6AD4
	cmp r2, #2
	beq _081F6AD8
	b _081F6ADC
	.align 2, 0
_081F6AD0: .4byte 0x030046A4
_081F6AD4:
	ldrb r0, [r5, #4]
	b _081F6ADA
_081F6AD8:
	ldrb r0, [r5]
_081F6ADA:
	subs r1, r1, r0
_081F6ADC:
	strh r1, [r6, #2]
	adds r0, r6, #0
	movs r1, #1
	bl FUN_081f624c
_081F6AE6:
	adds r0, r7, #0
	bl FUN_081f61b4
	adds r0, r7, #0
	bl FUN_081f5cc0
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081f6afc
FUN_081f6afc: @ 0x081F6AFC
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r1, #0
	ldr r0, _081F6B74 @ =0x000006EA
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081F6BB2
	ldr r2, _081F6B78 @ =0x000006DC
	adds r1, r5, r2
	movs r4, #0
	str r4, [sp]
	mov r0, sp
	ldr r2, _081F6B7C @ =0x05000002
	bl CpuSet
	movs r3, #0xdd
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strh r4, [r0]
	strb r1, [r6]
	ldr r0, _081F6B80 @ =0x03002BE0
	add r2, sp, #4
	adds r4, r5, #0
	adds r4, #0x1c
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r5, #0x1c]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	ldr r2, _081F6B84 @ =0x000006DA
	adds r1, r5, r2
	strb r0, [r1]
	movs r1, #1
	ldr r3, _081F6B88 @ =0x000006E4
	adds r0, r5, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	ands r0, r1
	cmp r0, #0
	beq _081F6B8C
	movs r0, #1
	b _081F6B8E
	.align 2, 0
_081F6B74: .4byte 0x000006EA
_081F6B78: .4byte 0x000006DC
_081F6B7C: .4byte 0x05000002
_081F6B80: .4byte 0x03002BE0
_081F6B84: .4byte 0x000006DA
_081F6B88: .4byte 0x000006E4
_081F6B8C:
	movs r0, #0
_081F6B8E:
	cmp r0, #0
	beq _081F6BA2
	adds r0, r5, #0
	bl FUN_081f6458
	movs r3, #0xdb
	lsls r3, r3, #3
	adds r1, r5, r3
	movs r0, #0
	b _081F6BB0
_081F6BA2:
	adds r0, r5, #0
	bl FUN_081f6474
	movs r0, #0xdb
	lsls r0, r0, #3
	adds r1, r5, r0
	movs r0, #5
_081F6BB0:
	strb r0, [r1]
_081F6BB2:
	movs r1, #1
	ldr r2, _081F6BC8 @ =0x000006E4
	adds r0, r5, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	ands r0, r1
	cmp r0, #0
	beq _081F6BCC
	movs r0, #1
	b _081F6BCE
	.align 2, 0
_081F6BC8: .4byte 0x000006E4
_081F6BCC:
	movs r0, #0
_081F6BCE:
	cmp r0, #0
	beq _081F6BE8
	adds r0, r5, #0
	bl FUN_081f6498
	ldr r2, _081F6BE4 @ =0x00006D60
	adds r0, r5, #0
	movs r1, #8
	bl FUN_081f59a4
	b _081F6BF8
	.align 2, 0
_081F6BE4: .4byte 0x00006D60
_081F6BE8:
	adds r0, r5, #0
	bl FUN_081f65f4
	ldr r2, _081F6C28 @ =0x00004E20
	adds r0, r5, #0
	movs r1, #4
	bl FUN_081f59a4
_081F6BF8:
	adds r0, r5, #0
	bl FUN_081f5610
	adds r0, r5, #0
	bl FUN_081f61b4
	adds r0, r5, #0
	bl FUN_081f5d6c
	ldr r1, _081F6C2C @ =0x000006E4
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _081F6C38
	ldr r2, _081F6C30 @ =0x000006E6
	adds r1, r5, r2
	movs r0, #4
	strb r0, [r1]
	ldr r3, _081F6C34 @ =0x000006EA
	adds r1, r5, r3
	b _081F6C64
	.align 2, 0
_081F6C28: .4byte 0x00004E20
_081F6C2C: .4byte 0x000006E4
_081F6C30: .4byte 0x000006E6
_081F6C34: .4byte 0x000006EA
_081F6C38:
	movs r0, #0xdd
	lsls r0, r0, #3
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _081F6C54 @ =0x000006EB
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081F6C58
	subs r0, #1
	b _081F6C66
	.align 2, 0
_081F6C54: .4byte 0x000006EB
_081F6C58:
	ldr r3, _081F6C70 @ =0x000006E6
	adds r1, r5, r3
	movs r0, #5
	strb r0, [r1]
	ldr r0, _081F6C74 @ =0x000006EA
	adds r1, r5, r0
_081F6C64:
	movs r0, #1
_081F6C66:
	strb r0, [r1]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081F6C70: .4byte 0x000006E6
_081F6C74: .4byte 0x000006EA

	thumb_func_start FUN_081f6c78
FUN_081f6c78: @ 0x081F6C78
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r1, #0
	ldr r0, _081F6CEC @ =0x000006EA
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081F6CBA
	ldr r2, _081F6CF0 @ =0x000006DC
	adds r1, r5, r2
	movs r4, #0
	str r4, [sp]
	mov r0, sp
	ldr r2, _081F6CF4 @ =0x05000002
	bl CpuSet
	movs r3, #0xdd
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strh r4, [r0]
	strb r1, [r6]
	movs r2, #0xdb
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r1, [r0]
	adds r0, r5, #0
	bl FUN_081f6458
	movs r0, #0xd1
	lsls r0, r0, #1
	bl PlaySound_082406e0
_081F6CBA:
	adds r0, r5, #0
	bl FUN_081f69a0
	ldr r2, _081F6CF8 @ =0x00006D60
	adds r0, r5, #0
	movs r1, #8
	bl FUN_081f59a4
	adds r0, r5, #0
	bl FUN_081f5610
	adds r0, r5, #0
	bl FUN_081f5d6c
	movs r3, #0xdd
	lsls r3, r3, #3
	adds r1, r5, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0x1d
	bgt _081F6CFC
	adds r0, r2, #1
	strh r0, [r1]
	b _081F6D08
	.align 2, 0
_081F6CEC: .4byte 0x000006EA
_081F6CF0: .4byte 0x000006DC
_081F6CF4: .4byte 0x05000002
_081F6CF8: .4byte 0x00006D60
_081F6CFC:
	ldr r1, _081F6D10 @ =0x000006E6
	adds r0, r5, r1
	movs r1, #5
	strb r1, [r0]
	movs r0, #1
	strb r0, [r6]
_081F6D08:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081F6D10: .4byte 0x000006E6

	thumb_func_start FUN_081f6d14
FUN_081f6d14: @ 0x081F6D14
	push {r4, r5, r6, r7, lr}
	sub sp, #0x3c
	adds r7, r1, #0
	ldr r0, _081F6D9C @ =0x000006EA
	adds r3, r7, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081F6D32
	movs r1, #0xdd
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r3]
_081F6D32:
	ldr r1, _081F6DA0 @ =0x000006D9
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #9
	bls _081F6D3E
	b _081F6EFC
_081F6D3E:
	adds r1, #0xf
	adds r0, r7, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #4
	bl Mod
	cmp r0, #0
	beq _081F6D52
	b _081F7088
_081F6D52:
	movs r1, #0xdb
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrb r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r7, r0
	adds r5, r0, #0
	adds r5, #0x1c
	ldr r1, [r0, #0x1c]
	ldr r2, [r0, #0x20]
	str r1, [sp, #0x2c]
	str r2, [sp, #0x30]
	ldrh r0, [r0, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081F6D96
	cmp r1, #0
	blt _081F6D96
	ldr r0, _081F6DA4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081F6D96
	ldr r0, _081F6DA8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081F6DAC
_081F6D96:
	movs r4, #0
	b _081F6DBA
	.align 2, 0
_081F6D9C: .4byte 0x000006EA
_081F6DA0: .4byte 0x000006D9
_081F6DA4: .4byte 0x030046A8
_081F6DA8: .4byte 0x030046AC
_081F6DAC:
	ldr r0, _081F6DCC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081F6DBA:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081F6DD0
	adds r0, #4
	b _081F6DDC
	.align 2, 0
_081F6DCC: .4byte 0x030046A4
_081F6DD0:
	ldr r0, _081F6DF0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081F6DDC:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081F6DF4
	cmp r3, #2
	beq _081F6DF8
	b _081F6DFC
	.align 2, 0
_081F6DF0: .4byte 0x030046A4
_081F6DF4:
	ldrb r0, [r5, #4]
	b _081F6DFA
_081F6DF8:
	ldrb r0, [r5]
_081F6DFA:
	subs r2, r2, r0
_081F6DFC:
	lsls r2, r2, #0x10
	ldr r1, _081F6E58 @ =0x0000FFFF
	ldr r0, [sp, #0x2c]
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x2c]
	add r0, sp, #0x2c
	movs r1, #2
	bl FUN_081f624c
	ldr r4, _081F6E5C @ =0x0203B400
	ldr r3, _081F6E60 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _081F6E64 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r5, #0xff
	ldrb r6, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	add r2, sp, #0x34
	adds r3, r0, #0
	adds r3, #0xa
	ldr r1, _081F6E68 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	adds r5, r2, #0
	cmp r0, #0
	blt _081F6E6C
	asrs r1, r0, #0xc
	b _081F6E72
	.align 2, 0
_081F6E58: .4byte 0x0000FFFF
_081F6E5C: .4byte 0x0203B400
_081F6E60: .4byte 0x030046B8
_081F6E64: .4byte 0x000003FF
_081F6E68: .4byte 0x085B0A08
_081F6E6C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F6E72:
	movs r0, #0
	strh r1, [r2]
	strh r0, [r2, #2]
	ldr r1, _081F6E8C @ =0x085B0A08
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _081F6E90
	asrs r0, r0, #0xc
	b _081F6E96
	.align 2, 0
_081F6E8C: .4byte 0x085B0A08
_081F6E90:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F6E96:
	movs r4, #0
	strh r0, [r2, #4]
	ldr r2, _081F6EE4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081F6EE8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081F6EEC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	adds r0, #0x18
	strh r0, [r5, #2]
	ldr r2, _081F6EF0 @ =0x00009D41
	ldr r3, _081F6EF4 @ =0x0000E677
	movs r0, #2
	str r0, [sp]
	movs r0, #0x28
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	ldr r0, _081F6EF8 @ =0x0000023D
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	movs r0, #1
	str r0, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	add r0, sp, #0x2c
	adds r1, r5, #0
	bl FUN_081ef708
	b _081F7088
	.align 2, 0
_081F6EE4: .4byte 0x030046B8
_081F6EE8: .4byte 0x000003FF
_081F6EEC: .4byte 0x0203B400
_081F6EF0: .4byte 0x00009D41
_081F6EF4: .4byte 0x0000E677
_081F6EF8: .4byte 0x0000023D
_081F6EFC:
	movs r1, #0xdd
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0x14
	bl Mod
	cmp r0, #0
	beq _081F6F12
	b _081F7088
_081F6F12:
	movs r1, #0xdb
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrb r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r7, r0
	adds r5, r0, #0
	adds r5, #0x1c
	ldr r1, [r0, #0x1c]
	ldr r2, [r0, #0x20]
	str r1, [sp, #0x2c]
	str r2, [sp, #0x30]
	ldrh r0, [r0, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081F6F56
	cmp r1, #0
	blt _081F6F56
	ldr r0, _081F6F5C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081F6F56
	ldr r0, _081F6F60 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081F6F64
_081F6F56:
	movs r4, #0
	b _081F6F72
	.align 2, 0
_081F6F5C: .4byte 0x030046A8
_081F6F60: .4byte 0x030046AC
_081F6F64:
	ldr r0, _081F6F84 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081F6F72:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081F6F88
	adds r0, #4
	b _081F6F94
	.align 2, 0
_081F6F84: .4byte 0x030046A4
_081F6F88:
	ldr r0, _081F6FA8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081F6F94:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081F6FAC
	cmp r2, #2
	beq _081F6FB0
	b _081F6FB4
	.align 2, 0
_081F6FA8: .4byte 0x030046A4
_081F6FAC:
	ldrb r0, [r5, #4]
	b _081F6FB2
_081F6FB0:
	ldrb r0, [r5]
_081F6FB2:
	subs r1, r1, r0
_081F6FB4:
	add r0, sp, #0x2c
	strh r1, [r0, #2]
	movs r1, #1
	bl FUN_081f624c
	ldr r4, _081F7004 @ =0x0203B400
	ldr r3, _081F7008 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _081F700C @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r5, #0xff
	ldrb r6, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	add r2, sp, #0x34
	adds r3, r0, #6
	ldr r1, _081F7010 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	adds r5, r2, #0
	cmp r0, #0
	blt _081F7014
	asrs r1, r0, #0xc
	b _081F701A
	.align 2, 0
_081F7004: .4byte 0x0203B400
_081F7008: .4byte 0x030046B8
_081F700C: .4byte 0x000003FF
_081F7010: .4byte 0x085B0A08
_081F7014:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F701A:
	movs r0, #0
	strh r1, [r2]
	strh r0, [r2, #2]
	ldr r1, _081F7034 @ =0x085B0A08
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _081F7038
	asrs r0, r0, #0xc
	b _081F703E
	.align 2, 0
_081F7034: .4byte 0x085B0A08
_081F7038:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F703E:
	movs r4, #0
	strh r0, [r2, #4]
	ldr r2, _081F70A4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081F70A8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081F70AC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #0x10
	strh r0, [r5, #2]
	ldr r2, _081F70B0 @ =0x00009D41
	ldr r3, _081F70B4 @ =0x0000E677
	movs r0, #2
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	ldr r0, _081F70B8 @ =0x0000023D
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	movs r0, #1
	str r0, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	add r0, sp, #0x2c
	adds r1, r5, #0
	bl FUN_081ef708
_081F7088:
	movs r0, #0xdd
	lsls r0, r0, #3
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r0, _081F70BC @ =0x000006D9
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081F70C0
	subs r0, #1
	b _081F70F4
	.align 2, 0
_081F70A4: .4byte 0x030046B8
_081F70A8: .4byte 0x000003FF
_081F70AC: .4byte 0x0203B400
_081F70B0: .4byte 0x00009D41
_081F70B4: .4byte 0x0000E677
_081F70B8: .4byte 0x0000023D
_081F70BC: .4byte 0x000006D9
_081F70C0:
	ldr r1, _081F70D8 @ =0x000006E4
	adds r0, r7, r1
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081F70E0
	ldr r0, _081F70DC @ =0x0000019D
	bl PlaySound_082406e0
	b _081F70E6
	.align 2, 0
_081F70D8: .4byte 0x000006E4
_081F70DC: .4byte 0x0000019D
_081F70E0:
	ldr r0, _081F7100 @ =0x000003DA
	bl PlaySound_082406e0
_081F70E6:
	ldr r0, _081F7104 @ =0x000006E6
	adds r1, r7, r0
	movs r0, #2
	strb r0, [r1]
	ldr r0, _081F7108 @ =0x000006EA
	adds r1, r7, r0
	movs r0, #1
_081F70F4:
	strb r0, [r1]
	add sp, #0x3c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F7100: .4byte 0x000003DA
_081F7104: .4byte 0x000006E6
_081F7108: .4byte 0x000006EA

	thumb_func_start FUN_081f710c
FUN_081f710c: @ 0x081F710C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r1, #0
	ldr r0, _081F7188 @ =0x000006EA
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081F713E
	movs r4, #0
	strb r4, [r6]
	ldr r0, _081F718C @ =0x000006DC
	adds r1, r5, r0
	str r4, [sp]
	mov r0, sp
	ldr r2, _081F7190 @ =0x05000002
	bl CpuSet
	ldr r0, _081F7194 @ =0x000006DE
	adds r1, r5, r0
	movs r0, #0x7c
	strh r0, [r1]
	movs r1, #0xdd
	lsls r1, r1, #3
	adds r0, r5, r1
	strh r4, [r0]
_081F713E:
	ldr r0, _081F7194 @ =0x000006DE
	adds r4, r5, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	ble _081F7198
	movs r6, #0xdb
	lsls r6, r6, #3
	adds r0, r5, r6
	ldrb r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r5, r0
	adds r3, r0, #0
	adds r3, #0x1c
	ldr r1, _081F718C @ =0x000006DC
	adds r2, r5, r1
	ldrh r1, [r2]
	ldrh r6, [r0, #0x1c]
	adds r1, r1, r6
	strh r1, [r0, #0x1c]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r6, [r3, #4]
	adds r0, r0, r6
	strh r0, [r3, #4]
	ldrh r0, [r4]
	subs r0, #8
	strh r0, [r4]
	b _081F71A4
	.align 2, 0
_081F7188: .4byte 0x000006EA
_081F718C: .4byte 0x000006DC
_081F7190: .4byte 0x05000002
_081F7194: .4byte 0x000006DE
_081F7198:
	ldr r1, _081F71CC @ =0x000006E6
	adds r0, r5, r1
	movs r1, #3
	strb r1, [r0]
	movs r0, #1
	strb r0, [r6]
_081F71A4:
	movs r2, #0xfa
	lsls r2, r2, #7
	adds r0, r5, #0
	movs r1, #4
	bl FUN_081f59a4
	adds r0, r5, #0
	bl FUN_081f5610
	adds r0, r5, #0
	bl FUN_081f61b4
	adds r0, r5, #0
	bl FUN_081f5d6c
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081F71CC: .4byte 0x000006E6

	thumb_func_start FUN_081f71d0
FUN_081f71d0: @ 0x081F71D0
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r6, #0
	movs r2, #1
	ldr r3, _081F71F4 @ =0x000006EC
	ldr r0, _081F71F8 @ =0x00000723
	adds r7, r5, r0
	adds r4, r5, #0
	adds r4, #0x3c
_081F71E4:
	adds r1, r2, #0
	lsls r1, r6
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F71FC
	movs r0, #1
	b _081F71FE
	.align 2, 0
_081F71F4: .4byte 0x000006EC
_081F71F8: .4byte 0x00000723
_081F71FC:
	movs r0, #0
_081F71FE:
	cmp r0, #0
	bne _081F721E
	adds r0, r4, #0
	adds r1, r3, #0
	str r2, [sp]
	bl ClearMemory
	ldr r2, [sp]
	adds r1, r2, #0
	lsls r1, r6
	ldr r0, [r5, #0x38]
	orrs r0, r1
	str r0, [r5, #0x38]
	strb r6, [r7]
	adds r0, r4, #0
	b _081F722C
_081F721E:
	ldr r0, _081F7234 @ =0x000006EC
	adds r7, r7, r0
	adds r4, r4, r0
	adds r6, #1
	cmp r6, #0
	ble _081F71E4
	movs r0, #0
_081F722C:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081F7234: .4byte 0x000006EC

	thumb_func_start FUN_081f7238
FUN_081f7238: @ 0x081F7238
	push {lr}
	bl FUN_081f71d0
	cmp r0, #0
	bne _081F7244
	movs r0, #0
_081F7244:
	pop {r1}
	bx r1

	thumb_func_start FUN_081f7248
FUN_081f7248: @ 0x081F7248
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x18
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	mov r8, r3
	ldr r0, _081F72A4 @ =0x030001FC
	ldr r0, [r0]
	cmp r0, #0
	bne _081F7268
	bl Entity081f73ec_Create
	cmp r0, #0
	beq _081F7306
_081F7268:
	bl FUN_081f7238
	adds r4, r0, #0
	cmp r4, #0
	beq _081F7306
	ldr r1, _081F72A8 @ =0x000006E6
	adds r0, r4, r1
	movs r1, #0
	movs r3, #1
	strb r3, [r0]
	ldr r0, _081F72AC @ =0x000006E4
	adds r2, r4, r0
	strh r1, [r2]
	subs r0, #0xb
	adds r1, r4, r0
	ldr r0, [sp, #0x40]
	strb r0, [r1]
	ldr r0, _081F72B0 @ =0x000006EB
	adds r1, r4, r0
	ldr r0, [sp, #0x34]
	strb r0, [r1]
	ldr r1, _081F72B4 @ =0x000006EA
	adds r0, r4, r1
	strb r3, [r0]
	ldr r0, [sp, #0x44]
	cmp r0, #0
	bne _081F72B8
	strh r3, [r2]
	b _081F72BC
	.align 2, 0
_081F72A4: .4byte 0x030001FC
_081F72A8: .4byte 0x000006E6
_081F72AC: .4byte 0x000006E4
_081F72B0: .4byte 0x000006EB
_081F72B4: .4byte 0x000006EA
_081F72B8:
	movs r0, #2
	strh r0, [r2]
_081F72BC:
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r2, [sp, #0x10]
	asrs r1, r2, #0x10
	ldr r0, _081F7314 @ =0xFFFFFF00
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _081F7318 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r1, _081F731C @ =0x0000D636
	ldr r2, _081F7320 @ =0x0000C102
	adds r0, r4, #0
	movs r3, #0
	bl FUN_081f5458
	adds r0, r4, #0
	add r1, sp, #0x10
	bl FUN_081f5b0c
	ldr r0, [sp, #0x30]
	str r0, [sp]
	ldr r0, [sp, #0x48]
	str r0, [sp, #4]
	ldr r0, [sp, #0x4c]
	str r0, [sp, #8]
	ldr r0, [sp, #0x50]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl FUN_081f602c
_081F7306:
	add sp, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F7314: .4byte 0xFFFFFF00
_081F7318: .4byte 0x0000FFFF
_081F731C: .4byte 0x0000D636
_081F7320: .4byte 0x0000C102

	thumb_func_start Entity081f73ec_Update
Entity081f73ec_Update: @ 0x081F7324
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r7, r6, #0
	adds r7, #0x3c
	movs r5, #0
	ldr r0, _081F7348 @ =0x085AE588
	mov r8, r0
_081F7336:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F734C
	movs r0, #1
	b _081F734E
	.align 2, 0
_081F7348: .4byte 0x085AE588
_081F734C:
	movs r0, #0
_081F734E:
	cmp r0, #0
	beq _081F7374
	ldr r0, _081F7388 @ =0x000006EC
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, r4, r7
	ldr r1, _081F738C @ =0x000006E6
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	bl _call_via_r2
	adds r0, r4, #0
	bl FUN_081f6170
_081F7374:
	adds r5, #1
	cmp r5, #0
	ble _081F7336
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081F7388: .4byte 0x000006EC
_081F738C: .4byte 0x000006E6

	thumb_func_start Entity081f73ec_Destroy
Entity081f73ec_Destroy: @ 0x081F7390
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
_081F7396:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F73A6
	movs r0, #1
	b _081F73A8
_081F73A6:
	movs r0, #0
_081F73A8:
	cmp r0, #0
	beq _081F73C2
	ldr r0, _081F73D4 @ =0x000006EC
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #0x3c
	adds r4, r6, r4
	adds r0, r4, #0
	bl FUN_081f5788
	adds r0, r4, #0
	bl FUN_081f57a8
_081F73C2:
	adds r5, #1
	cmp r5, #0
	ble _081F7396
	ldr r1, _081F73D8 @ =0x030001FC
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081F73D4: .4byte 0x000006EC
_081F73D8: .4byte 0x030001FC

	thumb_func_start Entity081f73ec_Init
Entity081f73ec_Init: @ 0x081F73DC
	movs r1, #0
	str r1, [r0, #0x38]
	ldr r1, _081F73E8 @ =0x030001FC
	str r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_081F73E8: .4byte 0x030001FC

	thumb_func_start Entity081f73ec_Create
Entity081f73ec_Create: @ 0x081F73EC
	push {r4, lr}
	ldr r0, _081F7424 @ =0x030001FC
	ldr r0, [r0]
	cmp r0, #0
	bne _081F7432
	movs r1, #0xe5
	lsls r1, r1, #3
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081F7430
	ldr r1, _081F7428 @ =Entity081f73ec_Update
	ldr r2, _081F742C @ =Entity081f73ec_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081f73ec_Init
	cmp r0, #0
	bge _081F7430
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081F7432
	.align 2, 0
_081F7424: .4byte 0x030001FC
_081F7428: .4byte Entity081f73ec_Update
_081F742C: .4byte Entity081f73ec_Destroy
_081F7430:
	adds r0, r4, #0
_081F7432:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081f7438
FUN_081f7438: @ 0x081F7438
	ldr r1, _081F7440 @ =0x030001FC
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081F7440: .4byte 0x030001FC

	thumb_func_start FUN_081f7444
FUN_081f7444: @ 0x081F7444
	push {lr}
	ldr r0, _081F745C @ =0x030001FC
	ldr r0, [r0]
	cmp r0, #0
	beq _081F7464
	ldr r1, _081F7460 @ =0x00000722
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081F7464
	movs r0, #0
	b _081F7466
	.align 2, 0
_081F745C: .4byte 0x030001FC
_081F7460: .4byte 0x00000722
_081F7464:
	movs r0, #1
_081F7466:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081f746c
FUN_081f746c: @ 0x081F746C
	push {lr}
	ldr r0, _081F7498 @ =0x030001FC
	ldr r1, [r0]
	cmp r1, #0
	beq _081F7494
	ldr r0, _081F749C @ =0x00000722
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _081F7494
	cmp r0, #5
	beq _081F7494
	cmp r0, #6
	beq _081F7494
	movs r0, #5
	strb r0, [r2]
	ldr r0, _081F74A0 @ =0x00000726
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
_081F7494:
	pop {r0}
	bx r0
	.align 2, 0
_081F7498: .4byte 0x030001FC
_081F749C: .4byte 0x00000722
_081F74A0: .4byte 0x00000726
