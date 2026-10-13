	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a19b4
FUN_080a19b4: @ 0x080A19B4
	push {lr}
	movs r1, #0x40
	ldr r0, [r0, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _080A19C8
	adds r1, r2, #0
	adds r1, #0xc4
	movs r0, #1
	strb r0, [r1]
_080A19C8:
	pop {r0}
	bx r0

	thumb_func_start FUN_080a19cc
FUN_080a19cc: @ 0x080A19CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	str r0, [sp, #0x30]
	mov r0, sp
	movs r3, #0
	movs r2, #2
	strh r2, [r0]
	strh r3, [r0, #2]
	mov r1, sp
	movs r0, #0x40
	strh r0, [r1, #6]
	movs r0, #3
	strh r0, [r1, #8]
	movs r0, #6
	strh r0, [r1, #0xa]
	mov r0, sp
	strh r2, [r0, #0xc]
	strh r2, [r0, #0xe]
	movs r0, #0x3c
	strh r0, [r1, #0x10]
	movs r0, #8
	strh r0, [r1, #0x12]
	mov r0, sp
	strh r3, [r0, #0x14]
	movs r1, #0xff
	strh r1, [r0, #0x16]
	strh r1, [r0, #0x18]
	strh r3, [r0, #0x1a]
	strh r1, [r0, #0x1c]
	strh r3, [r0, #0x1e]
	strh r1, [r0, #0x20]
	strh r3, [r0, #0x22]
	strh r1, [r0, #0x24]
	strh r3, [r0, #0x26]
	add r6, sp, #0x28
	ldr r0, _080A1AD4 @ =0x0203B400
	mov sl, r0
	ldr r4, _080A1AD8 @ =0x030046B8
	ldr r1, _080A1ADC @ =0x000003FF
	mov sb, r1
	movs r2, #0x96
	lsls r2, r2, #1
	mov r8, r2
	movs r7, #5
	adds r5, r6, #0
_080A1A2E:
	ldr r2, [sp, #0x30]
	ldr r0, [r2, #0x34]
	ldr r1, [r2, #0x38]
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	ldr r0, [r4]
	adds r0, #1
	mov r1, sb
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	mov r1, r8
	bl Mod
	ldrh r1, [r6]
	subs r1, #0x96
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x28]
	ldr r2, _080A1AE0 @ =0xFFFF0000
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x28]
	ldr r0, [r4]
	adds r0, #1
	mov r1, sb
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	mov r1, r8
	bl Mod
	ldr r2, [sp, #0x28]
	asrs r1, r2, #0x10
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _080A1AE4 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x28]
	ldr r0, [r4]
	adds r0, #1
	mov r2, sb
	ands r0, r2
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	mov r1, r8
	bl Mod
	ldrh r1, [r5, #4]
	subs r1, #0x96
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r5, #4]
	ldr r2, _080A1AE0 @ =0xFFFF0000
	ands r0, r2
	orrs r0, r1
	str r0, [r5, #4]
	movs r0, #1
	adds r1, r5, #0
	mov r2, sp
	bl FUN_080155e4
	subs r7, #1
	cmp r7, #0
	bge _080A1A2E
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A1AD4: .4byte 0x0203B400
_080A1AD8: .4byte 0x030046B8
_080A1ADC: .4byte 0x000003FF
_080A1AE0: .4byte 0xFFFF0000
_080A1AE4: .4byte 0x0000FFFF

	thumb_func_start Entity3DB0_Update
Entity3DB0_Update: @ 0x080A1AE8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xc4
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A1B1E
	ldr r0, [r4, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x18]
	adds r0, r4, #0
	bl FUN_080a19cc
	adds r1, r4, #0
	adds r1, #0xc8
	ldr r2, [r1]
	cmp r2, #0
	beq _080A1B18
	movs r0, #0
	str r0, [r1]
	adds r0, r2, #0
	movs r1, #0
	bl VM_ExecByID
_080A1B18:
	adds r0, r4, #0
	bl KillEntity
_080A1B1E:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity3DB0_Destroy
Entity3DB0_Destroy: @ 0x080A1B28
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x18
	bl AuxSprite_Remove
	adds r0, r4, #0
	adds r0, #0x60
	bl Hitbox_Unregister
	adds r0, r4, #0
	adds r0, #0xb0
	bl Map_RemoveTileOverride
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a1b48
FUN_080a1b48: @ 0x080A1B48
	push {r4, r5, r6, lr}
	adds r6, r1, #0
	adds r5, r0, #0
	adds r5, #0x18
	adds r4, r0, #0
	adds r4, #0x44
	movs r0, #0x74
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1B6C
	bl VM_GetValue
	adds r1, r0, #0
	adds r0, r4, #0
	bl Video_GetAuxSprite
	b _080A1B74
_080A1B6C:
	ldr r1, _080A1BB8 @ =0x00009D41
	adds r0, r4, #0
	bl Video_GetAuxSprite
_080A1B74:
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r0, #0x69
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1B8C
	bl VM_GetValue
_080A1B8C:
	strh r0, [r5, #0x10]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	movs r0, #0x72
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1BB0
	bl VM_GetValue
	cmp r0, #0
	beq _080A1BB0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	str r0, [r5]
_080A1BB0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A1BB8: .4byte 0x00009D41

	thumb_func_start FUN_080a1bbc
FUN_080a1bbc: @ 0x080A1BBC
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x1c
	adds r6, r0, #0
	mov r8, r2
	adds r5, r6, #0
	adds r5, #0x60
	ldr r4, _080A1C34 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r4
	movs r3, #0x80
	orrs r0, r3
	ldr r2, _080A1C38 @ =0x0000FFFF
	ands r0, r2
	movs r2, #0x80
	lsls r2, r2, #0x10
	orrs r0, r2
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r4
	orrs r0, r3
	str r0, [sp, #0x10]
	str r2, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r4
	str r0, [r3, #4]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080A1C3C @ =0x00004001
	movs r0, #0x20
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl Hitbox_Init
	ldr r1, _080A1C40 @ =FUN_080a19b4
	adds r0, r5, #0
	adds r2, r6, #0
	bl Hitbox_SetHandler
	adds r0, r5, #0
	mov r1, r8
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r5, #0
	bl Hitbox_Register
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A1C34: .4byte 0xFFFF0000
_080A1C38: .4byte 0x0000FFFF
_080A1C3C: .4byte 0x00004001
_080A1C40: .4byte FUN_080a19b4

	thumb_func_start Entity3DB0_Init
Entity3DB0_Init: @ 0x080A1C44
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	adds r7, r1, #0
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1CA0
	bl VM_GetValue
	asrs r0, r0, #8
	lsls r0, r0, #8
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080A1C98 @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080A1C9C @ =0x0000FFFF
	ldr r1, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	bl VM_GetValue
	asrs r0, r0, #8
	lsls r0, r0, #8
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	b _080A1CAA
	.align 2, 0
_080A1C98: .4byte 0xFFFF0000
_080A1C9C: .4byte 0x0000FFFF
_080A1CA0:
	ldr r1, _080A1CD8 @ =0xFFFF0000
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
_080A1CAA:
	add r6, sp, #8
	adds r0, r6, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A1CD2
	cmp r1, #0
	blt _080A1CD2
	ldr r0, _080A1CDC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A1CD2
	ldr r0, _080A1CE0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A1CE4
_080A1CD2:
	movs r4, #0
	b _080A1CF2
	.align 2, 0
_080A1CD8: .4byte 0xFFFF0000
_080A1CDC: .4byte 0x030046A8
_080A1CE0: .4byte 0x030046AC
_080A1CE4:
	ldr r0, _080A1D04 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080A1CF2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080A1D08
	adds r0, #4
	b _080A1D14
	.align 2, 0
_080A1D04: .4byte 0x030046A4
_080A1D08:
	ldr r0, _080A1D28 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A1D14:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _080A1D2C
	cmp r3, #2
	beq _080A1D30
	b _080A1D34
	.align 2, 0
_080A1D28: .4byte 0x030046A4
_080A1D2C:
	ldrb r0, [r6, #4]
	b _080A1D32
_080A1D30:
	ldrb r0, [r6]
_080A1D32:
	subs r2, r2, r0
_080A1D34:
	add r1, sp, #8
	strh r2, [r1, #2]
	adds r0, r1, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A1D5E
	cmp r1, #0
	blt _080A1D5E
	ldr r0, _080A1D64 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A1D5E
	ldr r0, _080A1D68 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A1D6C
_080A1D5E:
	movs r0, #0
	b _080A1D7A
	.align 2, 0
_080A1D64: .4byte 0x030046A8
_080A1D68: .4byte 0x030046AC
_080A1D6C:
	ldr r0, _080A1DD0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080A1D7A:
	adds r1, r5, #0
	adds r1, #0xc2
	strh r0, [r1]
	add r0, sp, #8
	ldrh r0, [r0, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	adds r0, #1
	adds r2, r5, #0
	adds r2, #0xc1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xb0
	ldrh r1, [r1]
	ldrb r3, [r2]
	movs r2, #0xff
	str r2, [sp]
	adds r2, #4
	str r2, [sp, #4]
	movs r2, #0
	bl Map_AddTileOverride
	adds r0, r5, #0
	add r1, sp, #8
	bl FUN_080a1b48
	adds r0, r5, #0
	adds r1, r7, #0
	add r2, sp, #8
	bl FUN_080a1bbc
	movs r0, #0x52
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A1DD4
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xc8
	str r0, [r1]
	b _080A1DDA
	.align 2, 0
_080A1DD0: .4byte 0x030046A4
_080A1DD4:
	adds r0, r5, #0
	adds r0, #0xc8
	str r1, [r0]
_080A1DDA:
	movs r0, #0
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity3DB0_Create
Entity3DB0_Create: @ 0x080A1DE4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #8
	movs r1, #0xcc
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A1E20
	ldr r1, _080A1E18 @ =Entity3DB0_Update
	ldr r2, _080A1E1C @ =Entity3DB0_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Entity3DB0_Init
	cmp r0, #0
	bge _080A1E20
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A1E22
	.align 2, 0
_080A1E18: .4byte Entity3DB0_Update
_080A1E1C: .4byte Entity3DB0_Destroy
_080A1E20:
	adds r0, r4, #0
_080A1E22:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
