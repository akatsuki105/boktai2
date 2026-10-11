	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a5950
FUN_080a5950: @ 0x080A5950
	push {r4, r5, r6, lr}
	ldr r4, _080A5968 @ =0x03002C4C
	ldr r0, [r4]
	cmp r0, #0
	beq _080A599E
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	bne _080A5974
	b _080A599E
	.align 2, 0
_080A5968: .4byte 0x03002C4C
_080A596C:
	adds r0, r3, #0
	adds r0, #0x1c
	adds r0, r5, r0
	b _080A59A0
_080A5974:
	bl VM_GetValue
	adds r6, r0, #0
	movs r2, #0
	ldr r0, [r4]
	ldrb r1, [r0, #0x19]
	cmp r2, r1
	bge _080A599E
	adds r5, r0, #0
	adds r4, r1, #0
	adds r1, r5, #0
	adds r1, #0xb4
	movs r3, #0
_080A598E:
	ldrh r0, [r1]
	cmp r0, r6
	beq _080A596C
	adds r1, #0xbc
	adds r3, #0xbc
	adds r2, #1
	cmp r2, r4
	blt _080A598E
_080A599E:
	movs r0, #0
_080A59A0:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a59a8
FUN_080a59a8: @ 0x080A59A8
	push {r4, r5, lr}
	bl FUN_080a5950
	adds r5, r0, #0
	cmp r5, #0
	beq _080A59D8
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A59D8
	adds r4, r5, #0
	adds r4, #0x38
	adds r5, #0x18
	bl VM_GetValue
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #0
	bl MainSprite_SetPose
_080A59D8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a59e0
FUN_080a59e0: @ 0x080A59E0
	push {r4, lr}
	bl FUN_080a5950
	adds r4, r0, #0
	cmp r4, #0
	beq _080A5A10
	movs r0, #0x66
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5A10
	bl VM_GetValue
	cmp r0, #0
	beq _080A5A06
	ldr r0, [r4, #0x40]
	movs r1, #4
	orrs r0, r1
	b _080A5A0E
_080A5A06:
	ldr r0, [r4, #0x40]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080A5A0E:
	str r0, [r4, #0x40]
_080A5A10:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a5a18
FUN_080a5a18: @ 0x080A5A18
	push {lr}
	bl FUN_080a5950
	adds r1, r0, #0
	cmp r1, #0
	beq _080A5A3C
	ldr r0, [r1, #0x40]
	movs r2, #1
	orrs r0, r2
	str r0, [r1, #0x40]
	adds r0, r1, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	beq _080A5A3C
	adds r0, r1, #0
	adds r0, #0x9e
	strh r2, [r0]
_080A5A3C:
	pop {r0}
	bx r0

	thumb_func_start FUN_080a5a40
FUN_080a5a40: @ 0x080A5A40
	push {lr}
	bl FUN_080a5950
	adds r2, r0, #0
	cmp r2, #0
	beq _080A5A68
	ldr r0, [r2, #0x40]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #0x40]
	adds r0, r2, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	beq _080A5A68
	adds r1, r2, #0
	adds r1, #0x9e
	movs r0, #0
	strh r0, [r1]
_080A5A68:
	pop {r0}
	bx r0

	thumb_func_start FUN_080a5a6c
FUN_080a5a6c: @ 0x080A5A6C
	push {r4, lr}
	bl FUN_080a5950
	adds r4, r0, #0
	cmp r4, #0
	beq _080A5A8C
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5A8C
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0x52
	strb r0, [r1]
_080A5A8C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a5a94
FUN_080a5a94: @ 0x080A5A94
	push {r4, lr}
	bl FUN_080a5950
	adds r4, r0, #0
	cmp r4, #0
	beq _080A5AFA
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5AC8
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0xb4
	strh r0, [r1]
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0xb6
	strh r0, [r1]
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0xb8
	strh r0, [r1]
_080A5AC8:
	movs r0, #0x66
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5ADC
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0xa2
	strh r0, [r1]
_080A5ADC:
	adds r2, r4, #0
	adds r2, #0xac
	adds r0, r4, #0
	adds r0, #0xa4
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r1, r4, #0
	adds r1, #0xa0
	movs r0, #0
	strh r0, [r1]
	subs r1, #6
	movs r0, #1
	strh r0, [r1]
_080A5AFA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a5b00
FUN_080a5b00: @ 0x080A5B00
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r3, r6, #0
	adds r3, #0x9a
	ldrh r0, [r3]
	cmp r0, #0
	beq _080A5BC0
	adds r7, r6, #0
	adds r7, #0xa0
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	movs r1, #0xa2
	adds r1, r1, r6
	mov r8, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r2, [r1]
	cmp r0, r2
	blo _080A5B42
	adds r2, r6, #0
	adds r2, #0xa4
	adds r0, r6, #0
	adds r0, #0xb4
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0
	strh r0, [r3]
	b _080A5BB8
_080A5B42:
	mov r3, r8
	ldrh r1, [r3]
	ldrh r2, [r7]
	subs r4, r1, r2
	adds r0, r6, #0
	adds r0, #0xb4
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r2, r0
	adds r2, r6, #0
	adds r2, #0xac
	movs r3, #0
	ldrsh r2, [r2, r3]
	muls r2, r4, r2
	adds r0, r0, r2
	bl Div
	adds r5, r6, #0
	adds r5, #0xa4
	strh r0, [r5]
	adds r0, r6, #0
	adds r0, #0xb6
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrh r0, [r7]
	muls r0, r1, r0
	adds r1, r6, #0
	adds r1, #0xae
	movs r3, #0
	ldrsh r1, [r1, r3]
	muls r1, r4, r1
	adds r0, r0, r1
	mov r2, r8
	ldrh r1, [r2]
	bl Div
	adds r1, r6, #0
	adds r1, #0xa6
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0xb8
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldrh r0, [r7]
	muls r0, r1, r0
	adds r1, r6, #0
	adds r1, #0xb0
	movs r2, #0
	ldrsh r1, [r1, r2]
	muls r1, r4, r1
	adds r0, r0, r1
	mov r3, r8
	ldrh r1, [r3]
	bl Div
	adds r1, r6, #0
	adds r1, #0xa8
	strh r0, [r1]
	adds r2, r5, #0
_080A5BB8:
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6, #0x58]
	str r1, [r6, #0x5c]
_080A5BC0:
	adds r0, r6, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	beq _080A5BF8
	adds r0, r6, #0
	adds r0, #0x9e
	ldrh r0, [r0]
	cmp r0, #0
	bne _080A5BF0
	ldr r0, _080A5BEC @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x14
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _080A5BF0
	ldr r0, [r6, #0x40]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _080A5BF6
	.align 2, 0
_080A5BEC: .4byte 0x030046A0
_080A5BF0:
	ldr r0, [r6, #0x40]
	movs r1, #1
	orrs r0, r1
_080A5BF6:
	str r0, [r6, #0x40]
_080A5BF8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a5c04
FUN_080a5c04: @ 0x080A5C04
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	ldr r0, _080A5C44 @ =0x03002C4C
	ldr r2, [r0]
	cmp r2, #0
	bne _080A5C18
	b _080A5D62
_080A5C18:
	ldrb r0, [r2, #0x19]
	ldrb r1, [r2, #0x18]
	cmp r0, r1
	blo _080A5C22
	b _080A5D62
_080A5C22:
	adds r1, r0, #0
	movs r0, #0xbc
	muls r0, r1, r0
	adds r0, #0x1c
	adds r5, r2, r0
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A5C48
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0x98
	strh r0, [r1]
	b _080A5C4E
	.align 2, 0
_080A5C44: .4byte 0x03002C4C
_080A5C48:
	adds r0, r5, #0
	adds r0, #0x98
	strh r1, [r0]
_080A5C4E:
	movs r0, #0x64
	bl VM_SeekToNamedArg
	cmp r0, #0
	bne _080A5C5A
	b _080A5D62
_080A5C5A:
	bl VM_GetValue
	adds r1, r0, #0
	ldr r0, _080A5C9C @ =0x0000CB05
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl GetFile
	adds r1, r0, #0
	adds r2, r5, #0
	adds r2, #0x18
	ldm r0!, {r3, r4, r6}
	stm r2!, {r3, r4, r6}
	ldm r0!, {r3, r4, r6}
	stm r2!, {r3, r4, r6}
	ldm r0!, {r3, r4}
	stm r2!, {r3, r4}
	adds r4, r5, #0
	adds r4, #0x18
	adds r0, r4, #0
	bl OpenMainSpriteFile
	movs r0, #0x69
	bl VM_SeekToNamedArg
	mov r8, r4
	cmp r0, #0
	beq _080A5CA0
	bl VM_GetValue
	adds r7, r0, #0
	b _080A5CA2
	.align 2, 0
_080A5C9C: .4byte 0x0000CB05
_080A5CA0:
	movs r7, #0
_080A5CA2:
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5CB2
	bl VM_GetValue
	b _080A5CB4
_080A5CB2:
	movs r0, #0
_080A5CB4:
	movs r6, #0
	mov sb, r6
	cmp r0, #1
	bne _080A5CC0
	movs r0, #0x10
	mov sb, r0
_080A5CC0:
	movs r0, #0x52
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5CD2
	bl VM_GetValue
	adds r6, r0, #0
	b _080A5CD4
_080A5CD2:
	movs r6, #2
_080A5CD4:
	movs r0, #0x70
	bl VM_SeekToNamedArg
	adds r2, r0, #0
	cmp r2, #0
	beq _080A5D00
	bl VM_GetValue
	adds r4, r5, #0
	adds r4, #0xa4
	strh r0, [r4]
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xa6
	strh r0, [r1]
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xa8
	strh r0, [r1]
	b _080A5D12
_080A5D00:
	adds r1, r5, #0
	adds r1, #0xa4
	strh r2, [r1]
	adds r0, r5, #0
	adds r0, #0xa6
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r4, r1, #0
_080A5D12:
	adds r0, r5, #0
	adds r0, #0x38
	lsls r2, r7, #0x10
	lsrs r2, r2, #0x10
	lsls r1, r6, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	str r4, [sp, #0xc]
	mov r1, r8
	mov r3, sb
	bl MainSprite_Add
	movs r0, #0x41
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A5D4A
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0x9c
	strh r0, [r1]
	b _080A5D50
_080A5D4A:
	adds r0, r5, #0
	adds r0, #0x9c
	strh r1, [r0]
_080A5D50:
	adds r1, r5, #0
	adds r1, #0x9e
	movs r0, #0
	strh r0, [r1]
	ldr r0, _080A5D70 @ =0x03002C4C
	ldr r1, [r0]
	ldrb r0, [r1, #0x19]
	adds r0, #1
	strb r0, [r1, #0x19]
_080A5D62:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A5D70: .4byte 0x03002C4C

	thumb_func_start Entity8AF6_Update
Entity8AF6_Update: @ 0x080A5D74
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	ldrb r0, [r6, #0x19]
	cmp r5, r0
	bge _080A5D94
	adds r4, r6, #0
	adds r4, #0x1c
_080A5D84:
	adds r0, r4, #0
	bl FUN_080a5b00
	adds r4, #0xbc
	adds r5, #1
	ldrb r0, [r6, #0x19]
	cmp r5, r0
	blt _080A5D84
_080A5D94:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start Entity8AF6_Destroy
Entity8AF6_Destroy: @ 0x080A5D9C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	ldrb r0, [r6, #0x19]
	cmp r5, r0
	bge _080A5DBC
	adds r4, r6, #0
	adds r4, #0x54
_080A5DAC:
	adds r0, r4, #0
	bl MainSprite_Remove
	adds r4, #0xbc
	adds r5, #1
	ldrb r0, [r6, #0x19]
	cmp r5, r0
	blt _080A5DAC
_080A5DBC:
	ldr r1, _080A5DC8 @ =0x03002C4C
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A5DC8: .4byte 0x03002C4C

	thumb_func_start Entity8AF6_Init
Entity8AF6_Init: @ 0x080A5DCC
	movs r1, #0
	strb r3, [r0, #0x18]
	strb r1, [r0, #0x19]
	ldr r1, _080A5DDC @ =0x03002C4C
	str r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_080A5DDC: .4byte 0x03002C4C

	thumb_func_start Entity8AF6_Create
Entity8AF6_Create: @ 0x080A5DE0
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	ldr r0, _080A5E00 @ =0x03002C4C
	ldr r0, [r0]
	cmp r0, #0
	bne _080A5E46
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5E04
	bl VM_GetValue
	adds r5, r0, #0
	b _080A5E06
	.align 2, 0
_080A5E00: .4byte 0x03002C4C
_080A5E04:
	movs r5, #1
_080A5E06:
	movs r0, #0xbc
	adds r1, r5, #0
	muls r1, r0, r1
	adds r1, #0x1c
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A5E44
	ldr r1, _080A5E3C @ =Entity8AF6_Update
	ldr r2, _080A5E40 @ =Entity8AF6_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	adds r3, r5, #0
	bl Entity8AF6_Init
	cmp r0, #0
	bge _080A5E44
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A5E46
	.align 2, 0
_080A5E3C: .4byte Entity8AF6_Update
_080A5E40: .4byte Entity8AF6_Destroy
_080A5E44:
	adds r0, r4, #0
_080A5E46:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

