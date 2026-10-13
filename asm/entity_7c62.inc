	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a3ae8
FUN_080a3ae8: @ 0x080A3AE8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080A3B5C @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bls _080A3B64
	ldr r0, _080A3B60 @ =0x03002BE0
	ldr r3, [r0]
	movs r2, #0xe0
	lsls r2, r2, #2
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A3B64
	movs r1, #0x2c
	ldrsh r0, [r3, r1]
	adds r1, r4, #0
	adds r1, #0xac
	movs r2, #0
	ldrsh r1, [r1, r2]
	subs r2, r0, r1
	cmp r2, #0
	bge _080A3B26
	rsbs r2, r2, #0
_080A3B26:
	movs r1, #0x30
	ldrsh r0, [r3, r1]
	adds r1, r4, #0
	adds r1, #0xb0
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r1, r0, r1
	cmp r1, #0
	bge _080A3B3A
	rsbs r1, r1, #0
_080A3B3A:
	cmp r2, #0x60
	bgt _080A3B64
	cmp r1, #0x60
	bgt _080A3B64
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	movs r1, #0x90
	lsls r1, r1, #6
	cmp r0, r1
	bgt _080A3B64
	movs r0, #1
	b _080A3B66
	.align 2, 0
_080A3B5C: .4byte 0x030046A0
_080A3B60: .4byte 0x03002BE0
_080A3B64:
	movs r0, #0
_080A3B66:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a3b6c
FUN_080a3b6c: @ 0x080A3B6C
	adds r2, r0, #0
	movs r3, #0x88
	lsls r3, r3, #1
	adds r0, r2, r3
	str r1, [r0]
	movs r0, #0x86
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #0
	strh r0, [r1]
	bx lr
	.align 2, 0

	thumb_func_start FUN_080a3b84
FUN_080a3b84: @ 0x080A3B84
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080A3BE4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080A3BA6
	movs r0, #0x81
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #9
	bhi _080A3BA6
	adds r0, #1
	strh r0, [r1]
_080A3BA6:
	adds r0, r4, #0
	bl FUN_080a3ae8
	adds r5, r0, #0
	cmp r5, #0
	beq _080A3C44
	ldrb r0, [r4, #0x1a]
	cmp r0, #1
	beq _080A3BC4
	movs r0, #0xcc
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #1
	strb r0, [r4, #0x1a]
_080A3BC4:
	adds r0, r4, #0
	adds r0, #0xfe
	ldrh r1, [r0]
	adds r6, r0, #0
	cmp r1, #7
	bhi _080A3BD4
	adds r0, r1, #1
	strh r0, [r6]
_080A3BD4:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0x16
	bhi _080A3BE8
	adds r0, #2
	b _080A3BEA
	.align 2, 0
_080A3BE4: .4byte 0x030047A4
_080A3BE8:
	movs r0, #0x18
_080A3BEA:
	strh r0, [r1]
	movs r2, #1
	ldr r0, _080A3C34 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	beq _080A3C7A
	ldr r0, _080A3C38 @ =0x030044E0
	ldrh r1, [r0, #2]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080A3C7A
	movs r1, #0x81
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #9
	bls _080A3C7A
	movs r0, #8
	strh r0, [r6]
	movs r0, #1
	bl FUN_080a6e88
	ldr r0, _080A3C3C @ =0x03002BE0
	ldr r0, [r0]
	adds r1, r4, #0
	adds r1, #0xac
	movs r2, #0
	movs r3, #4
	bl FUN_0807ba94
	ldr r1, _080A3C40 @ =FUN_080a3cec
	adds r0, r4, #0
	bl FUN_080a3b6c
	b _080A3C7A
	.align 2, 0
_080A3C34: .4byte 0x03002BC0
_080A3C38: .4byte 0x030044E0
_080A3C3C: .4byte 0x03002BE0
_080A3C40: .4byte FUN_080a3cec
_080A3C44:
	ldrb r0, [r4, #0x1a]
	cmp r0, #0
	beq _080A3C52
	ldr r0, _080A3C74 @ =0x00000199
	bl PlaySound_082406e0
	strb r5, [r4, #0x1a]
_080A3C52:
	adds r0, r4, #0
	adds r0, #0xfe
	ldrh r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	beq _080A3C62
	subs r0, r1, #1
	strh r0, [r6]
_080A3C62:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #2
	bls _080A3C78
	subs r0, #2
	strh r0, [r1]
	b _080A3C7A
	.align 2, 0
_080A3C74: .4byte 0x00000199
_080A3C78:
	strh r5, [r1]
_080A3C7A:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r0, [r2]
	cmp r0, #0
	bne _080A3C90
	ldr r0, [r4, #0x64]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x64]
	b _080A3CAA
_080A3C90:
	ldr r0, [r4, #0x64]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x64]
	adds r1, r4, #0
	adds r1, #0xae
	ldrh r0, [r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x82
	strh r0, [r1]
_080A3CAA:
	ldrh r0, [r6]
	cmp r0, #7
	bls _080A3CC2
	adds r0, r4, #0
	adds r0, #0x90
	adds r1, r4, #0
	adds r1, #0xfc
	ldrh r1, [r1]
	adds r1, #2
	bl Video_SetAuxSpritePltt
	b _080A3CE6
_080A3CC2:
	cmp r0, #0
	beq _080A3CD8
	adds r0, r4, #0
	adds r0, #0x90
	adds r1, r4, #0
	adds r1, #0xfc
	ldrh r1, [r1]
	adds r1, #1
	bl Video_SetAuxSpritePltt
	b _080A3CE6
_080A3CD8:
	adds r0, r4, #0
	adds r0, #0x90
	adds r1, r4, #0
	adds r1, #0xfc
	ldrh r1, [r1]
	bl Video_SetAuxSpritePltt
_080A3CE6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a3cec
FUN_080a3cec: @ 0x080A3CEC
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #1
	bls _080A3D02
	subs r0, #2
	b _080A3D04
_080A3D02:
	movs r0, #0
_080A3D04:
	strh r0, [r1]
	adds r2, r4, #0
	adds r2, #0xae
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r1, [r0]
	ldrh r2, [r2]
	adds r1, r1, r2
	adds r2, r4, #0
	adds r2, #0x82
	strh r1, [r2]
	ldrh r0, [r0]
	cmp r0, #0
	bne _080A3D8A
	ldr r0, _080A3D94 @ =0x03002BE0
	ldr r0, [r0]
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A3D8A
	ldr r0, [r4, #0x64]
	ldr r1, _080A3D98 @ =0xFFFFFDFF
	ands r0, r1
	str r0, [r4, #0x64]
	adds r1, r4, #0
	adds r1, #0x6b
	movs r0, #3
	strb r0, [r1]
	adds r2, #0x32
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _080A3D9C @ =FUN_080a3da4
	adds r0, r4, #0
	bl FUN_080a3b6c
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080A3D8A
	ldr r1, _080A3DA0 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	str r0, [sp, #8]
	add r1, sp, #8
	mov r3, sp
	str r3, [r1, #4]
	movs r3, #0x82
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrh r0, [r0]
	str r0, [sp]
	adds r3, #2
	adds r0, r4, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r2, #0
	bl VM_ExecByID
_080A3D8A:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A3D94: .4byte 0x03002BE0
_080A3D98: .4byte 0xFFFFFDFF
_080A3D9C: .4byte FUN_080a3da4
_080A3DA0: .4byte 0xFFFF0000

	thumb_func_start FUN_080a3da4
FUN_080a3da4: @ 0x080A3DA4
	bx lr
	.align 2, 0

	thumb_func_start Entity7C62_Update
Entity7C62_Update: @ 0x080A3DA8
	push {lr}
	movs r2, #0x88
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r1, [r1]
	bl _call_via_r1
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start Entity7C62_Destroy
Entity7C62_Destroy: @ 0x080A3DBC
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x64
	bl AuxSprite_Remove
	adds r0, r4, #0
	adds r0, #0xb4
	bl AuxSprite_Remove
	ldrb r0, [r4, #0x1b]
	cmp r0, #0
	beq _080A3DDC
	adds r0, r4, #0
	adds r0, #0x20
	bl Mover_Unlink
_080A3DDC:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start Entity7C62_Init
Entity7C62_Init: @ 0x080A3DE4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r7, r0, #0
	strh r1, [r7, #0x18]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	adds r3, r0, #0
	cmp r3, #0
	beq _080A3EA4
	bl VM_GetValue
	adds r4, r7, #0
	adds r4, #0xac
	strh r0, [r4]
	bl VM_GetValue
	adds r5, r7, #0
	adds r5, #0xae
	strh r0, [r5]
	bl VM_GetValue
	adds r1, r7, #0
	adds r1, #0xb0
	strh r0, [r1]
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r4, [sp, #0xc]
	cmp r2, #0
	blt _080A3E44
	cmp r1, #0
	blt _080A3E44
	ldr r0, _080A3E48 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A3E44
	ldr r0, _080A3E4C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A3E50
_080A3E44:
	movs r6, #0
	b _080A3E5E
	.align 2, 0
_080A3E48: .4byte 0x030046A8
_080A3E4C: .4byte 0x030046AC
_080A3E50:
	ldr r0, _080A3E70 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r2
_080A3E5E:
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080A3E74
	adds r0, #4
	b _080A3E80
	.align 2, 0
_080A3E70: .4byte 0x030046A4
_080A3E74:
	ldr r0, _080A3E94 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A3E80:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080A3E98
	cmp r2, #2
	beq _080A3E9C
	b _080A3EA0
	.align 2, 0
_080A3E94: .4byte 0x030046A4
_080A3E98:
	ldrb r0, [r4, #4]
	b _080A3E9E
_080A3E9C:
	ldrb r0, [r4]
_080A3E9E:
	subs r1, r1, r0
_080A3EA0:
	strh r1, [r5]
	b _080A3EB6
_080A3EA4:
	adds r1, r7, #0
	adds r1, #0xac
	strh r3, [r1]
	adds r0, r7, #0
	adds r0, #0xae
	strh r3, [r0]
	adds r0, #2
	strh r3, [r0]
	str r1, [sp, #0xc]
_080A3EB6:
	movs r0, #0x73
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A3ED0
	bl VM_GetValue
	movs r2, #0x84
	lsls r2, r2, #1
	adds r1, r7, r2
	str r0, [r1]
	b _080A3ED8
_080A3ED0:
	movs r2, #0x84
	lsls r2, r2, #1
	adds r0, r7, r2
	str r1, [r0]
_080A3ED8:
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A3F2C
	adds r0, r7, #0
	adds r0, #0xfc
	str r0, [sp, #8]
	movs r1, #0x90
	adds r1, r1, r7
	mov r8, r1
	adds r2, r7, #0
	adds r2, #0x64
	str r2, [sp, #0x18]
	subs r0, #0x91
	str r0, [sp, #0x1c]
	adds r1, r7, #0
	adds r1, #0x80
	str r1, [sp, #0x20]
	movs r2, #0xe0
	adds r2, r2, r7
	mov sl, r2
	movs r0, #0xb4
	adds r0, r0, r7
	mov sb, r0
	adds r1, #0x3b
	str r1, [sp, #0x10]
	adds r2, r7, #0
	adds r2, #0xd0
	str r2, [sp, #0x14]
	movs r0, #0x82
	lsls r0, r0, #1
	adds r4, r7, r0
	movs r5, #1
_080A3F1C:
	bl VM_GetValue
	strh r0, [r4]
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge _080A3F1C
	b _080A3F72
_080A3F2C:
	adds r1, r7, #0
	adds r1, #0xfc
	str r1, [sp, #8]
	movs r2, #0x90
	adds r2, r2, r7
	mov r8, r2
	adds r0, r7, #0
	adds r0, #0x64
	str r0, [sp, #0x18]
	subs r1, #0x91
	str r1, [sp, #0x1c]
	adds r2, r7, #0
	adds r2, #0x80
	str r2, [sp, #0x20]
	movs r0, #0xe0
	adds r0, r0, r7
	mov sl, r0
	movs r1, #0xb4
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0x3b
	str r2, [sp, #0x10]
	adds r0, r7, #0
	adds r0, #0xd0
	str r0, [sp, #0x14]
	movs r1, #0
	movs r5, #1
	movs r2, #0x83
	lsls r2, r2, #1
	adds r0, r7, r2
_080A3F68:
	strh r1, [r0]
	subs r0, #2
	subs r5, #1
	cmp r5, #0
	bge _080A3F68
_080A3F72:
	movs r0, #0x68
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A3F80
	bl VM_GetValue
_080A3F80:
	strb r0, [r7, #0x1b]
	ldrb r0, [r7, #0x1b]
	cmp r0, #0
	beq _080A3FA4
	adds r4, r7, #0
	adds r4, #0x20
	ldrh r1, [r7, #0x18]
	movs r0, #7
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r4, #0
	ldr r2, [sp, #0xc]
	movs r3, #0
	bl Mover_Init
	adds r0, r4, #0
	bl FUN_08002a48
_080A3FA4:
	movs r0, #0x6a
	ldr r1, [sp, #8]
	strh r0, [r1]
	ldr r6, _080A4044 @ =0x00000BA8
	mov r0, r8
	adds r1, r6, #0
	bl Video_GetAuxSprite
	ldr r0, [sp, #0x18]
	mov r1, r8
	movs r2, #0
	bl AuxSprite_Add
	movs r5, #7
	ldr r2, [sp, #0x18]
	strh r5, [r2, #0x10]
	ldr r0, [sp, #8]
	ldrh r1, [r0]
	mov r0, r8
	bl Video_SetAuxSpritePltt
	ldr r0, [r7, #0x64]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r7, #0x64]
	movs r4, #3
	ldr r1, [sp, #0x1c]
	strb r4, [r1]
	ldr r2, [sp, #0xc]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	ldr r2, [sp, #0x20]
	str r0, [r2]
	str r1, [r2, #4]
	mov r0, sl
	adds r1, r6, #0
	bl Video_GetAuxSprite
	mov r0, sb
	mov r1, sl
	movs r2, #0
	bl AuxSprite_Add
	mov r0, sb
	strh r5, [r0, #0x10]
	ldr r2, [sp, #8]
	ldrh r1, [r2]
	mov r0, sl
	bl Video_SetAuxSpritePltt
	mov r1, sb
	ldr r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	mov r2, sb
	str r0, [r2]
	ldr r0, [sp, #0x10]
	strb r4, [r0]
	ldr r2, [sp, #0xc]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	ldr r2, [sp, #0x14]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _080A4048 @ =FUN_080a3b84
	adds r0, r7, #0
	bl FUN_080a3b6c
	movs r0, #0
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A4044: .4byte 0x00000BA8
_080A4048: .4byte FUN_080a3b84

	thumb_func_start Entity7C62_Create
Entity7C62_Create: @ 0x080A404C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0x8a
	lsls r1, r1, #1
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A408C
	ldr r1, _080A4084 @ =Entity7C62_Update
	ldr r2, _080A4088 @ =Entity7C62_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Entity7C62_Init
	cmp r0, #0
	bge _080A408C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A408E
	.align 2, 0
_080A4084: .4byte Entity7C62_Update
_080A4088: .4byte Entity7C62_Destroy
_080A408C:
	adds r0, r4, #0
_080A408E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
