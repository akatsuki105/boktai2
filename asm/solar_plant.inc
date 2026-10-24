	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a4598
FUN_080a4598: @ 0x080A4598
	movs r3, #0x84
	lsls r3, r3, #1
	adds r2, r0, r3
	str r1, [r2]
	adds r0, #0xec
	movs r1, #0
	strh r1, [r0]
	bx lr

	thumb_func_start FUN_080a45a8
FUN_080a45a8: @ 0x080A45A8
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r0, #0xe4
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A45DE
	ldr r0, [r4]
	movs r1, #4
	ands r0, r1
	movs r5, #1
	cmp r0, #0
	beq _080A45C4
	movs r5, #2
_080A45C4:
	adds r0, r4, #0
	adds r0, #0xde
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _080A45D4
	asrs r0, r0, #8
	b _080A45DA
_080A45D4:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080A45DA:
	adds r3, r0, #1
	b _080A45F6
_080A45DE:
	movs r5, #0
	adds r0, r4, #0
	adds r0, #0xde
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _080A45F0
	asrs r3, r0, #8
	b _080A45F6
_080A45F0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r3, r0, #0
_080A45F6:
	adds r0, r4, #0
	adds r0, #0xf8
	adds r1, r4, #0
	adds r1, #0xea
	ldrh r1, [r1]
	movs r2, #0xff
	str r2, [sp]
	movs r2, #0
	str r2, [sp, #4]
	adds r2, r5, #0
	bl Map_AddTileOverride
	adds r1, r4, #0
	adds r1, #0xf7
	movs r0, #1
	strb r0, [r1]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a4620
FUN_080a4620: @ 0x080A4620
	push {r4, lr}
	adds r3, r0, #0
	adds r4, r2, #0
	adds r4, #0xf4
	ldrb r0, [r4]
	cmp r0, #0
	bne _080A465C
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r3, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _080A465C
	ldr r0, _080A4664 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080A4668 @ =0x00000942
	adds r0, r0, r1
	adds r1, r2, #0
	adds r1, #0xf0
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0x20
	strb r0, [r4]
	ldr r0, _080A466C @ =0x03002C44
	ldr r1, [r0]
	movs r0, #1
	strb r0, [r1, #0x19]
_080A465C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A4664: .4byte 0x030046A0
_080A4668: .4byte 0x00000942
_080A466C: .4byte 0x03002C44

	thumb_func_start FUN_080a4670
FUN_080a4670: @ 0x080A4670
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xf0
	adds r1, r4, #0
	adds r1, #0xf2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	blo _080A46A4
	adds r1, r4, #0
	adds r1, #0xf6
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_080a45a8
	adds r2, r4, #0
	adds r2, #0x4e
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _080A46AC @ =FUN_080a46b0
	adds r0, r4, #0
	bl FUN_080a4598
_080A46A4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A46AC: .4byte FUN_080a46b0

	thumb_func_start FUN_080a46b0
FUN_080a46b0: @ 0x080A46B0
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	movs r6, #2
	strb r6, [r5, #7]
	adds r4, r5, #0
	adds r4, #0xec
	ldrh r0, [r4]
	cmp r0, #0
	bne _080A46CC
	movs r0, #0xd5
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080A46CC:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _080A46E0
	movs r0, #1
	strh r0, [r5, #0x10]
	b _080A4718
_080A46E0:
	strh r6, [r5, #0x10]
	ldr r1, _080A4720 @ =FUN_080a4728
	adds r0, r5, #0
	bl FUN_080a4598
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080A4718
	ldr r1, _080A4724 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	mov r3, sp
	str r3, [r1, #4]
	adds r0, r5, #0
	adds r0, #0xe8
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp]
	adds r0, r2, #0
	bl VM_ExecByID
_080A4718:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A4720: .4byte FUN_080a4728
_080A4724: .4byte 0xFFFF0000

	thumb_func_start FUN_080a4728
FUN_080a4728: @ 0x080A4728
	bx lr
	.align 2, 0

	thumb_func_start FUN_080a472c
FUN_080a472c: @ 0x080A472C
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r2, r5, #0
	adds r2, #0xee
	ldrh r0, [r2]
	cmp r0, #0
	beq _080A4794
	adds r4, r5, #0
	adds r4, #0xec
	ldrh r1, [r4]
	lsls r0, r1, #8
	subs r0, r0, r1
	ldrh r1, [r2]
	bl Div
	ldr r2, _080A4768 @ =gSineTable
	movs r1, #0xff
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r2
	movs r0, #0
	ldrsh r1, [r1, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _080A476C
	asrs r1, r0, #0xc
	b _080A4772
	.align 2, 0
_080A4768: .4byte gSineTable
_080A476C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A4772:
	adds r0, r5, #0
	adds r0, #0xde
	ldrh r0, [r0]
	adds r0, r0, r1
	strh r0, [r5, #0x1e]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	adds r1, r5, #0
	adds r1, #0xee
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _080A4794
	movs r0, #0
	strh r0, [r4]
_080A4794:
	adds r0, r5, #0
	adds r0, #0xf0
	adds r1, r5, #0
	adds r1, #0xf2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	blo _080A47C6
	adds r1, r5, #0
	adds r1, #0xf6
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_080a45a8
	adds r2, r5, #0
	adds r2, #0x4e
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _080A47CC @ =FUN_080a47d0
	adds r0, r5, #0
	bl FUN_080a4598
_080A47C6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A47CC: .4byte FUN_080a47d0

	thumb_func_start FUN_080a47d0
FUN_080a47d0: @ 0x080A47D0
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xec
	ldrh r0, [r4]
	cmp r0, #0
	bne _080A47E8
	movs r0, #0xd5
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080A47E8:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _080A4808
	adds r0, r5, #0
	adds r0, #0xdc
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	movs r0, #1
	strh r0, [r5, #0x10]
	b _080A4842
_080A4808:
	movs r0, #2
	strh r0, [r5, #0x10]
	ldr r1, _080A484C @ =FUN_080a4854
	adds r0, r5, #0
	bl FUN_080a4598
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080A4842
	ldr r1, _080A4850 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	mov r3, sp
	str r3, [r1, #4]
	adds r0, r5, #0
	adds r0, #0xe8
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp]
	adds r0, r2, #0
	bl VM_ExecByID
_080A4842:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A484C: .4byte FUN_080a4854
_080A4850: .4byte 0xFFFF0000

	thumb_func_start FUN_080a4854
FUN_080a4854: @ 0x080A4854
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080A4898 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0xea
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _080A48A0
	adds r5, r4, #0
	adds r5, #0xde
	movs r2, #0x1e
	ldrsh r1, [r4, r2]
	movs r3, #0
	ldrsh r0, [r5, r3]
	cmp r1, r0
	bne _080A4884
	ldr r0, _080A489C @ =0x000002B3
	bl PlaySound_082406e0
_080A4884:
	movs r0, #0x1e
	ldrsh r1, [r4, r0]
	movs r2, #0
	ldrsh r0, [r5, r2]
	subs r0, #0x10
	cmp r1, r0
	ble _080A48B6
	ldrh r0, [r4, #0x1e]
	subs r0, #2
	b _080A48B4
	.align 2, 0
_080A4898: .4byte 0x03002BE0
_080A489C: .4byte 0x000002B3
_080A48A0:
	adds r0, r4, #0
	adds r0, #0xde
	ldrh r2, [r4, #0x1e]
	movs r3, #0x1e
	ldrsh r1, [r4, r3]
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bge _080A48B6
	adds r0, r2, #2
_080A48B4:
	strh r0, [r4, #0x1e]
_080A48B6:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a48bc
FUN_080a48bc: @ 0x080A48BC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _080A48DE
	ldr r0, _080A48FC @ =0x000001A9
	bl PlaySound_082406e0
	movs r1, #0
	movs r0, #0x20
	strb r0, [r4, #0x1b]
	strb r1, [r4, #0x19]
_080A48DE:
	ldrb r0, [r4, #0x1b]
	cmp r0, #0
	beq _080A49BC
	subs r0, #1
	strb r0, [r4, #0x1b]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _080A4904
	ldr r0, _080A4900 @ =0x03003584
	ldr r0, [r0]
	movs r1, #0xbe
	lsls r1, r1, #4
	adds r0, r0, r1
	b _080A4912
	.align 2, 0
_080A48FC: .4byte 0x000001A9
_080A4900: .4byte 0x03003584
_080A4904:
	cmp r0, #0xf
	bls _080A4928
	ldr r0, _080A4920 @ =0x03003584
	ldr r0, [r0]
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r0, r0, r2
_080A4912:
	adds r1, r4, #0
	adds r1, #0x1c
	ldr r2, _080A4924 @ =0x04000008
	bl CpuSet
	b _080A49BC
	.align 2, 0
_080A4920: .4byte 0x03003584
_080A4924: .4byte 0x04000008
_080A4928:
	ldrb r7, [r4, #0x1b]
	movs r0, #0x10
	subs r0, r0, r7
	str r0, [sp]
	ldr r0, _080A49CC @ =0x03003584
	ldr r0, [r0]
	movs r3, #0xc0
	lsls r3, r3, #4
	adds r3, r3, r0
	mov sl, r3
	movs r5, #0xbe
	lsls r5, r5, #4
	adds r5, r5, r0
	mov r8, r5
	movs r6, #0
	mov sb, r6
	adds r4, #0x1c
	str r4, [sp, #4]
	movs r0, #0x1f
	mov ip, r0
_080A4950:
	mov r1, sl
	ldrh r3, [r1]
	movs r2, #0x1f
	ands r2, r3
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x15
	mov r5, ip
	ands r6, r5
	lsrs r3, r3, #0x1a
	ands r3, r5
	mov r0, r8
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x15
	ands r4, r5
	lsrs r1, r1, #0x1a
	ands r1, r5
	adds r5, r2, #0
	muls r5, r7, r5
	ldr r2, [sp]
	muls r0, r2, r0
	adds r5, r5, r0
	asrs r5, r5, #4
	adds r2, r6, #0
	muls r2, r7, r2
	ldr r6, [sp]
	adds r0, r4, #0
	muls r0, r6, r0
	adds r2, r2, r0
	asrs r2, r2, #4
	adds r0, r3, #0
	muls r0, r7, r0
	muls r1, r6, r1
	adds r0, r0, r1
	asrs r0, r0, #4
	mov r3, sb
	lsls r1, r3, #1
	ldr r6, [sp, #4]
	adds r1, r6, r1
	lsls r0, r0, #0xa
	lsls r2, r2, #5
	orrs r0, r2
	orrs r0, r5
	strh r0, [r1]
	movs r0, #2
	add sl, r0
	add r8, r0
	movs r1, #1
	add sb, r1
	mov r2, sb
	cmp r2, #0xf
	ble _080A4950
_080A49BC:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A49CC: .4byte 0x03003584

	thumb_func_start Entity1E98_Update
Entity1E98_Update: @ 0x080A49D0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	bl FUN_080a48bc
	movs r0, #0
	mov r8, r0
	ldrb r0, [r6, #0x18]
	cmp r8, r0
	bge _080A4A34
	adds r5, r6, #0
	adds r5, #0x68
	movs r0, #0x98
	lsls r0, r0, #1
	adds r4, r6, r0
	adds r7, r6, #0
	adds r7, #0x3c
_080A49F4:
	ldr r1, [r4, #0x14]
	adds r0, r7, #0
	bl _call_via_r1
	ldrb r0, [r4]
	cmp r0, #0
	beq _080A4A20
	subs r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080A4A18
	movs r0, #0x60
	strh r0, [r5, #6]
	adds r0, r6, #0
	adds r0, #0x1c
	str r0, [r5, #0xc]
	b _080A4A20
_080A4A18:
	adds r0, r5, #0
	movs r1, #0x5f
	bl Video_SetAuxSpritePltt
_080A4A20:
	movs r0, #0x88
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, r4, r0
	adds r7, r7, r0
	movs r0, #1
	add r8, r0
	ldrb r0, [r6, #0x18]
	cmp r8, r0
	blt _080A49F4
_080A4A34:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity1E98_Destroy
Entity1E98_Destroy: @ 0x080A4A40
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	movs r0, #0
	mov sl, r0
	ldrb r0, [r5, #0x18]
	cmp sl, r0
	bge _080A4AAC
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r0, r0, r5
	mov sb, r0
	movs r0, #0x84
	adds r0, r0, r5
	mov r8, r0
	adds r7, r5, #0
	adds r7, #0xd4
	ldr r0, _080A4AC0 @ =0x00000121
	adds r4, r5, r0
	adds r6, r5, #0
	adds r6, #0x3c
_080A4A70:
	ldrb r0, [r4]
	cmp r0, #0
	beq _080A4A7C
	adds r0, r7, #0
	bl Mover_Unlink
_080A4A7C:
	adds r0, r6, #0
	bl AuxSprite_Remove
	mov r0, r8
	bl Hitbox_Unregister
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080A4A94
	mov r0, sb
	bl Map_RemoveTileOverride
_080A4A94:
	movs r0, #0x88
	lsls r0, r0, #1
	add sb, r0
	add r8, r0
	adds r7, r7, r0
	adds r4, r4, r0
	adds r6, r6, r0
	movs r0, #1
	add sl, r0
	ldrb r0, [r5, #0x18]
	cmp sl, r0
	blt _080A4A70
_080A4AAC:
	ldr r1, _080A4AC4 @ =0x03002C44
	movs r0, #0
	str r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A4AC0: .4byte 0x00000121
_080A4AC4: .4byte 0x03002C44

	thumb_func_start FUN_080a4ac8
FUN_080a4ac8: @ 0x080A4AC8
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x48
	ldr r2, _080A4B3C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x80
	orrs r0, r3
	ldr r1, _080A4B40 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	adds r0, r4, #0
	adds r0, #0xe6
	ldrh r1, [r0]
	ldr r2, _080A4B44 @ =0x00004002
	movs r0, #0x20
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl Hitbox_Init
	ldr r1, _080A4B48 @ =0x080A4621
	adds r0, r5, #0
	adds r2, r4, #0
	bl Hitbox_SetHandler
	adds r4, #0xdc
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r5, #0
	bl Hitbox_Register
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A4B3C: .4byte 0xFFFF0000
_080A4B40: .4byte 0x0000FFFF
_080A4B44: .4byte 0x00004002
_080A4B48: .4byte 0x080A4621

	thumb_func_start Entity1E98_Init
Entity1E98_Init: @ 0x080A4B4C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	ldrb r1, [r0, #0x18]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, #0x3c
	mov r1, sb
	adds r5, r1, r0
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A4B82
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xe6
	strh r0, [r1]
	mov sl, r1
	b _080A4B8A
_080A4B82:
	adds r0, r5, #0
	adds r0, #0xe6
	strh r1, [r0]
	mov sl, r0
_080A4B8A:
	movs r0, #0x70
	bl VM_SeekToNamedArg
	adds r2, r0, #0
	cmp r2, #0
	beq _080A4BB8
	bl VM_GetValue
	adds r4, r5, #0
	adds r4, #0xdc
	strh r0, [r4]
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xde
	strh r0, [r1]
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xe0
	strh r0, [r1]
	adds r6, r4, #0
	b _080A4BCA
_080A4BB8:
	adds r1, r5, #0
	adds r1, #0xdc
	strh r2, [r1]
	adds r0, r5, #0
	adds r0, #0xde
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r6, r1, #0
_080A4BCA:
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A4BEE
	cmp r1, #0
	blt _080A4BEE
	ldr r0, _080A4BF4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A4BEE
	ldr r0, _080A4BF8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A4BFC
_080A4BEE:
	movs r0, #0
	b _080A4C0A
	.align 2, 0
_080A4BF4: .4byte 0x030046A8
_080A4BF8: .4byte 0x030046AC
_080A4BFC:
	ldr r0, _080A4C24 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080A4C0A:
	adds r2, r5, #0
	adds r2, #0xea
	strh r0, [r2]
	movs r0, #0x74
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4C28
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xe4
	b _080A4C2E
	.align 2, 0
_080A4C24: .4byte 0x030046A4
_080A4C28:
	adds r1, r5, #0
	adds r1, #0xe4
	movs r0, #0
_080A4C2E:
	strb r0, [r1]
	mov r8, r1
	mov r2, r8
	ldrb r0, [r2]
	ldr r1, _080A4CB8 @ =0x0000D166
	cmp r0, #0
	bne _080A4C3E
	ldr r1, _080A4CBC @ =0x0000C3C3
_080A4C3E:
	adds r7, r5, #0
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r0, #3
	strb r0, [r5, #7]
	movs r0, #0x72
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4C72
	bl VM_GetValue
	cmp r0, #0
	beq _080A4C72
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	str r0, [r5]
_080A4C72:
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	movs r0, #0x68
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4CC0
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xe5
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080A4CC6
	adds r4, r5, #0
	adds r4, #0x98
	mov r0, sl
	ldrh r1, [r0]
	adds r2, r7, #0
	adds r2, #0x1c
	movs r0, #7
	str r0, [sp]
	str r5, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl Mover_Init
	adds r0, r4, #0
	bl FUN_08002a48
	b _080A4CC6
	.align 2, 0
_080A4CB8: .4byte 0x0000D166
_080A4CBC: .4byte 0x0000C3C3
_080A4CC0:
	adds r1, r5, #0
	adds r1, #0xe5
	strb r0, [r1]
_080A4CC6:
	adds r0, r5, #0
	adds r0, #0xf0
	movs r1, #0
	strh r1, [r0]
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4CE2
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xf2
	b _080A4CE8
_080A4CE2:
	adds r1, r5, #0
	adds r1, #0xf2
	movs r0, #0xa
_080A4CE8:
	strh r0, [r1]
	movs r0, #0x57
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4CF8
	bl VM_GetValue
_080A4CF8:
	adds r1, r5, #0
	adds r1, #0xee
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080a4ac8
	adds r1, r5, #0
	adds r1, #0xf4
	movs r0, #0
	strb r0, [r1]
	movs r0, #0x73
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A4D26
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xf6
	strb r0, [r1]
	adds r0, r1, #0
	b _080A4D2C
_080A4D26:
	adds r0, r5, #0
	adds r0, #0xf6
	strb r1, [r0]
_080A4D2C:
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A4D64
	adds r0, r5, #0
	bl FUN_080a45a8
	adds r2, r5, #0
	adds r2, #0x4e
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	movs r0, #2
	strh r0, [r7, #0x10]
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0
	bne _080A4D5C
	movs r0, #2
	strb r0, [r7, #7]
	ldr r1, _080A4D58 @ =0x080A4729
	b _080A4D7A
	.align 2, 0
_080A4D58: .4byte 0x080A4729
_080A4D5C:
	ldr r1, _080A4D60 @ =FUN_080a4854
	b _080A4D7A
	.align 2, 0
_080A4D60: .4byte FUN_080a4854
_080A4D64:
	adds r1, r5, #0
	adds r1, #0xf7
	strb r0, [r1]
	strh r0, [r7, #0x10]
	movs r0, #3
	strb r0, [r7, #7]
	mov r2, r8
	ldrb r0, [r2]
	cmp r0, #0
	bne _080A4D88
	ldr r1, _080A4D84 @ =FUN_080a4670
_080A4D7A:
	adds r0, r5, #0
	bl FUN_080a4598
	b _080A4D90
	.align 2, 0
_080A4D84: .4byte FUN_080a4670
_080A4D88:
	ldr r1, _080A4DB4 @ =FUN_080a472c
	adds r0, r5, #0
	bl FUN_080a4598
_080A4D90:
	movs r0, #0x67
	bl VM_SeekToNamedArg
	adds r2, r0, #0
	cmp r2, #0
	beq _080A4DB8
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xe8
	strh r0, [r1]
	bl VM_GetValue
	movs r2, #0x86
	lsls r2, r2, #1
	adds r1, r5, r2
	str r0, [r1]
	b _080A4DC8
	.align 2, 0
_080A4DB4: .4byte FUN_080a472c
_080A4DB8:
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, _080A4DE0 @ =0x0000FFFF
	strh r1, [r0]
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r5, r1
	str r2, [r0]
_080A4DC8:
	mov r2, sb
	ldrb r0, [r2, #0x18]
	adds r0, #1
	strb r0, [r2, #0x18]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A4DE0: .4byte 0x0000FFFF

	thumb_func_start Entity1E98_Create_Internal
Entity1E98_Create_Internal: @ 0x080A4DE4
	push {r4, lr}
	ldr r1, _080A4E0C @ =0x000008BC
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A4E00
	ldr r1, _080A4E10 @ =Entity1E98_Update
	ldr r2, _080A4E14 @ =Entity1E98_Destroy
	bl SetEntityRoutine
	movs r0, #0
	strb r0, [r4, #0x18]
_080A4E00:
	ldr r0, _080A4E18 @ =0x03002C44
	str r4, [r0]
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A4E0C: .4byte 0x000008BC
_080A4E10: .4byte Entity1E98_Update
_080A4E14: .4byte Entity1E98_Destroy
_080A4E18: .4byte 0x03002C44

	thumb_func_start FUN_080a4e1c
FUN_080a4e1c: @ 0x080A4E1C
	push {r4, r5, r6, r7, lr}
	ldr r0, _080A4E38 @ =0x03002C44
	ldr r4, [r0]
	cmp r4, #0
	beq _080A4E70
	movs r0, #0x69
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4E46
	bl VM_GetValue
	adds r5, r0, #0
	b _080A4E48
	.align 2, 0
_080A4E38: .4byte 0x03002C44
_080A4E3C:
	movs r1, #0x99
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	b _080A4E72
_080A4E46:
	movs r5, #0
_080A4E48:
	movs r3, #0
	ldrb r0, [r4, #0x18]
	cmp r3, r0
	bge _080A4E70
	adds r6, r0, #0
	movs r7, #0x92
	lsls r7, r7, #1
	adds r1, r4, r7
	adds r2, r4, #0
	movs r4, #0x88
	lsls r4, r4, #1
_080A4E5E:
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, r5
	beq _080A4E3C
	adds r1, r1, r4
	adds r2, r2, r4
	adds r3, #1
	cmp r3, r6
	blt _080A4E5E
_080A4E70:
	movs r0, #0
_080A4E72:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity1E98_Create
Entity1E98_Create: @ 0x080A4E78
	push {lr}
	ldr r0, _080A4E90 @ =0x03002C44
	ldr r0, [r0]
	cmp r0, #0
	bne _080A4E86
	bl Entity1E98_Create_Internal
_080A4E86:
	bl Entity1E98_Init
	pop {r1}
	bx r1
	.align 2, 0
_080A4E90: .4byte 0x03002C44
