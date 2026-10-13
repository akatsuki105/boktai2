	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a4094
FUN_080a4094: @ 0x080A4094
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080A40E4 @ =0x030046A0
	ldr r3, [r0]
	movs r0, #0x30
	ldrsh r1, [r3, r0]
	adds r0, r4, #0
	adds r0, #0x64
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r2, r1, r0
	cmp r2, #0
	bge _080A40B0
	rsbs r2, r2, #0
_080A40B0:
	movs r1, #0x34
	ldrsh r0, [r3, r1]
	adds r1, r4, #0
	adds r1, #0x68
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r1, r0, r1
	cmp r1, #0
	bge _080A40C4
	rsbs r1, r1, #0
_080A40C4:
	cmp r2, #0x60
	bgt _080A40E8
	cmp r1, #0x60
	bgt _080A40E8
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	movs r1, #0x90
	lsls r1, r1, #6
	cmp r0, r1
	bgt _080A40E8
	movs r0, #1
	b _080A40EA
	.align 2, 0
_080A40E4: .4byte 0x030046A0
_080A40E8:
	movs r0, #0
_080A40EA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a40f0
FUN_080a40f0: @ 0x080A40F0
	adds r2, r0, #0
	adds r2, #0xc8
	str r1, [r2]
	adds r0, #0xc4
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_080a4100
FUN_080a4100: @ 0x080A4100
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r0, _080A4160 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080A4120
	adds r1, r4, #0
	adds r1, #0xba
	ldrh r0, [r1]
	cmp r0, #9
	bhi _080A4120
	adds r0, #1
	strh r0, [r1]
_080A4120:
	adds r0, r4, #0
	bl FUN_080a4094
	adds r6, r0, #0
	cmp r6, #0
	beq _080A41CC
	ldrh r0, [r4, #0x18]
	cmp r0, #1
	beq _080A413E
	movs r0, #0xcc
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #1
	strh r0, [r4, #0x18]
_080A413E:
	adds r0, r4, #0
	adds r0, #0xb6
	ldrh r1, [r0]
	adds r7, r0, #0
	cmp r1, #7
	bhi _080A414E
	adds r0, r1, #1
	strh r0, [r7]
_080A414E:
	adds r0, r4, #0
	adds r0, #0xb8
	ldrh r1, [r0]
	adds r5, r0, #0
	cmp r1, #0x16
	bhi _080A4164
	adds r0, r1, #2
	b _080A4166
	.align 2, 0
_080A4160: .4byte 0x030047A4
_080A4164:
	movs r0, #0x18
_080A4166:
	strh r0, [r5]
	movs r2, #1
	ldr r0, _080A41BC @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	beq _080A4202
	ldr r0, _080A41C0 @ =0x030044E0
	ldrh r1, [r0, #2]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080A4202
	ldr r6, _080A41C4 @ =0x03002BE0
	ldr r0, [r6]
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A4202
	adds r0, r4, #0
	adds r0, #0xba
	ldrh r0, [r0]
	cmp r0, #9
	bls _080A4202
	movs r0, #8
	strh r0, [r7]
	movs r0, #1
	bl FUN_080a6e88
	ldr r0, [r6]
	adds r1, r4, #0
	adds r1, #0x64
	movs r2, #0
	movs r3, #4
	bl FUN_0807ba94
	ldr r1, _080A41C8 @ =FUN_080a4250
	adds r0, r4, #0
	bl FUN_080a40f0
	b _080A4202
	.align 2, 0
_080A41BC: .4byte 0x03002BC0
_080A41C0: .4byte 0x030044E0
_080A41C4: .4byte 0x03002BE0
_080A41C8: .4byte FUN_080a4250
_080A41CC:
	ldrh r0, [r4, #0x18]
	cmp r0, #0
	beq _080A41DA
	ldr r0, _080A41FC @ =0x00000199
	bl PlaySound_082406e0
	strh r6, [r4, #0x18]
_080A41DA:
	adds r0, r4, #0
	adds r0, #0xb6
	ldrh r1, [r0]
	adds r7, r0, #0
	cmp r1, #0
	beq _080A41EA
	subs r0, r1, #1
	strh r0, [r7]
_080A41EA:
	adds r0, r4, #0
	adds r0, #0xb8
	ldrh r1, [r0]
	adds r5, r0, #0
	cmp r1, #2
	bls _080A4200
	subs r0, r1, #2
	strh r0, [r5]
	b _080A4202
	.align 2, 0
_080A41FC: .4byte 0x00000199
_080A4200:
	strh r6, [r5]
_080A4202:
	ldrh r0, [r5]
	cmp r0, #0
	bne _080A4212
	ldr r0, [r4, #0x1c]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x1c]
	b _080A4228
_080A4212:
	ldr r0, [r4, #0x1c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x1c]
	adds r1, r4, #0
	adds r1, #0x66
	ldrh r0, [r5]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #0x3a]
_080A4228:
	ldrh r0, [r7]
	cmp r0, #7
	bls _080A423C
	adds r0, r4, #0
	adds r0, #0x48
	movs r1, #0x8f
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	b _080A424A
_080A423C:
	adds r0, r4, #0
	adds r0, #0x48
	adds r1, r4, #0
	adds r1, #0xb4
	ldrh r1, [r1]
	bl Video_SetAuxSpritePltt
_080A424A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a4250
FUN_080a4250: @ 0x080A4250
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xb8
	ldrh r0, [r1]
	cmp r0, #1
	bls _080A4264
	subs r0, #2
	b _080A4266
_080A4264:
	movs r0, #0
_080A4266:
	strh r0, [r1]
	adds r2, r4, #0
	adds r2, #0x66
	adds r0, r4, #0
	adds r0, #0xb8
	ldrh r1, [r0]
	ldrh r2, [r2]
	adds r1, r1, r2
	strh r1, [r4, #0x3a]
	ldrh r0, [r0]
	cmp r0, #0
	bne _080A42E0
	ldr r0, _080A42E8 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A42E0
	ldr r0, [r4, #0x1c]
	ldr r1, _080A42EC @ =0xFFFFFDFF
	ands r0, r1
	str r0, [r4, #0x1c]
	adds r1, r4, #0
	adds r1, #0x23
	movs r0, #3
	strb r0, [r1]
	ldr r0, [r4, #0x6c]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x6c]
	ldr r1, _080A42F0 @ =FUN_080a42f8
	adds r0, r4, #0
	bl FUN_080a40f0
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r2, [r0]
	cmp r2, #0
	beq _080A42E0
	ldr r1, _080A42F4 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	str r0, [sp, #8]
	add r1, sp, #8
	mov r0, sp
	str r0, [r1, #4]
	adds r0, r4, #0
	adds r0, #0xbc
	ldrh r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	adds r0, #0xbe
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r2, #0
	bl VM_ExecByID
_080A42E0:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A42E8: .4byte 0x03002BE0
_080A42EC: .4byte 0xFFFFFDFF
_080A42F0: .4byte FUN_080a42f8
_080A42F4: .4byte 0xFFFF0000

	thumb_func_start FUN_080a42f8
FUN_080a42f8: @ 0x080A42F8
	bx lr
	.align 2, 0

	thumb_func_start Entity4759_Update
Entity4759_Update: @ 0x080A42FC
	push {lr}
	adds r1, r0, #0
	adds r1, #0xc8
	ldr r1, [r1]
	bl _call_via_r1
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity4759_Destroy
Entity4759_Destroy: @ 0x080A4310
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x1c
	bl AuxSprite_Remove
	adds r4, #0x6c
	adds r0, r4, #0
	bl AuxSprite_Remove
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity4759_Init
Entity4759_Init: @ 0x080A432C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	movs r0, #0x74
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4348
	bl VM_GetValue
_080A4348:
	strb r0, [r6, #0x1a]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A43FC
	bl VM_GetValue
	adds r4, r6, #0
	adds r4, #0x64
	strh r0, [r4]
	bl VM_GetValue
	adds r5, r6, #0
	adds r5, #0x66
	strh r0, [r5]
	bl VM_GetValue
	adds r1, r6, #0
	adds r1, #0x68
	strh r0, [r1]
	adds r7, r4, #0
	ldrh r0, [r7]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A439A
	cmp r1, #0
	blt _080A439A
	ldr r0, _080A43A0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A439A
	ldr r0, _080A43A4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A43A8
_080A439A:
	movs r4, #0
	b _080A43B6
	.align 2, 0
_080A43A0: .4byte 0x030046A8
_080A43A4: .4byte 0x030046AC
_080A43A8:
	ldr r0, _080A43C8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080A43B6:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080A43CC
	adds r0, #4
	b _080A43D8
	.align 2, 0
_080A43C8: .4byte 0x030046A4
_080A43CC:
	ldr r0, _080A43EC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A43D8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080A43F0
	cmp r2, #2
	beq _080A43F4
	b _080A43F8
	.align 2, 0
_080A43EC: .4byte 0x030046A4
_080A43F0:
	ldrb r0, [r7, #4]
	b _080A43F6
_080A43F4:
	ldrb r0, [r7]
_080A43F6:
	subs r1, r1, r0
_080A43F8:
	strh r1, [r5]
	b _080A440A
_080A43FC:
	adds r0, r6, #0
	adds r0, #0x64
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
_080A440A:
	movs r0, #0x52
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A4422
	bl VM_GetValue
	adds r1, r6, #0
	adds r1, #0xc0
	str r0, [r1]
	b _080A4428
_080A4422:
	adds r0, r6, #0
	adds r0, #0xc0
	str r1, [r0]
_080A4428:
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4474
	movs r0, #0xb4
	adds r0, r0, r6
	mov r8, r0
	adds r7, r6, #0
	adds r7, #0x48
	movs r1, #0x1c
	adds r1, r1, r6
	mov sl, r1
	adds r2, r6, #0
	adds r2, #0x23
	str r2, [sp, #0xc]
	movs r0, #0x98
	adds r0, r0, r6
	mov sb, r0
	adds r1, r6, #0
	adds r1, #0x6c
	str r1, [sp]
	adds r2, #0x50
	str r2, [sp, #4]
	adds r0, r6, #0
	adds r0, #0x88
	str r0, [sp, #8]
	adds r4, r6, #0
	adds r4, #0xbc
	movs r5, #1
_080A4464:
	bl VM_GetValue
	strh r0, [r4]
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge _080A4464
	b _080A44AE
_080A4474:
	movs r1, #0xb4
	adds r1, r1, r6
	mov r8, r1
	adds r7, r6, #0
	adds r7, #0x48
	movs r2, #0x1c
	adds r2, r2, r6
	mov sl, r2
	adds r0, r6, #0
	adds r0, #0x23
	str r0, [sp, #0xc]
	movs r1, #0x98
	adds r1, r1, r6
	mov sb, r1
	adds r2, r6, #0
	adds r2, #0x6c
	str r2, [sp]
	adds r0, #0x50
	str r0, [sp, #4]
	adds r1, r6, #0
	adds r1, #0x88
	str r1, [sp, #8]
	adds r1, #0x34
	movs r2, #0
	adds r0, #0x4b
_080A44A6:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _080A44A6
_080A44AE:
	ldrb r0, [r6, #0x1a]
	cmp r0, #0
	bne _080A44BE
	movs r0, #0x8e
	lsls r0, r0, #1
	mov r2, r8
	strh r0, [r2]
	b _080A44C4
_080A44BE:
	ldr r0, _080A4548 @ =0x0000011D
	mov r1, r8
	strh r0, [r1]
_080A44C4:
	ldr r5, _080A454C @ =0x0000A152
	adds r0, r7, #0
	adds r1, r5, #0
	bl Video_GetAuxSprite
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0
	bl AuxSprite_Add
	mov r2, r8
	ldrh r1, [r2]
	adds r0, r7, #0
	bl Video_SetAuxSpritePltt
	ldr r0, [r6, #0x1c]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r6, #0x1c]
	movs r4, #3
	ldr r0, [sp, #0xc]
	strb r4, [r0]
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x68]
	str r0, [r6, #0x38]
	str r1, [r6, #0x3c]
	mov r0, sb
	adds r1, r5, #0
	bl Video_GetAuxSprite
	ldr r0, [sp]
	mov r1, sb
	movs r2, #0
	bl AuxSprite_Add
	mov r2, r8
	ldrh r1, [r2]
	mov r0, sb
	bl Video_SetAuxSpritePltt
	ldr r0, [r6, #0x6c]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r6, #0x6c]
	ldr r0, [sp, #4]
	strb r4, [r0]
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x68]
	ldr r2, [sp, #8]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _080A4550 @ =FUN_080a4100
	adds r0, r6, #0
	bl FUN_080a40f0
	movs r0, #0
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A4548: .4byte 0x0000011D
_080A454C: .4byte 0x0000A152
_080A4550: .4byte FUN_080a4100

	thumb_func_start Entity4759_Create
Entity4759_Create: @ 0x080A4554
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #9
	movs r1, #0xcc
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A4590
	ldr r1, _080A4588 @ =Entity4759_Update
	ldr r2, _080A458C @ =Entity4759_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Entity4759_Init
	cmp r0, #0
	bge _080A4590
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A4592
	.align 2, 0
_080A4588: .4byte Entity4759_Update
_080A458C: .4byte Entity4759_Destroy
_080A4590:
	adds r0, r4, #0
_080A4592:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
