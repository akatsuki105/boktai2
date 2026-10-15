	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081fa1bc
FUN_081fa1bc: @ 0x081FA1BC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x18
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r4, #0x48]
	str r1, [r4, #0x4c]
	adds r1, r4, #0
	adds r1, #0x44
	movs r0, #0
	strh r0, [r1]
	ldr r0, _081FA220 @ =0x08252698
	bl HashName
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl GetParticleGroup
	adds r1, r0, #0
	str r1, [r4, #0x40]
	cmp r1, #0
	beq _081FA224
	adds r0, r5, #0
	movs r2, #0
	bl Particle_Add
	movs r2, #8
	rsbs r2, r2, #0
	adds r0, r5, #0
	adds r1, r2, #0
	bl Particle_SetOffset
	ldr r0, [r4, #0x48]
	ldr r1, [r4, #0x4c]
	str r0, [r5, #0x18]
	str r1, [r5, #0x1c]
	ldr r1, [r4, #0x40]
	adds r0, r5, #0
	movs r2, #0x20
	bl Particle_SetFrame
	movs r0, #0
	strb r0, [r5, #0xf]
	ldr r0, [r4, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x18]
	movs r0, #0
	b _081FA228
	.align 2, 0
_081FA220: .4byte 0x08252698
_081FA224:
	movs r0, #1
	rsbs r0, r0, #0
_081FA228:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081fa230
FUN_081fa230: @ 0x081FA230
	push {lr}
	adds r0, #0x18
	bl Particle_Remove
	pop {r1}
	bx r1

	thumb_func_start FUN_081fa23c
FUN_081fa23c: @ 0x081FA23C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x18]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r4, #0x18]
	adds r3, r4, #0
	adds r3, #0x44
	ldrh r5, [r3]
	movs r1, #0
	ldrsh r2, [r3, r1]
	movs r1, #0x96
	lsls r1, r1, #1
	cmp r2, r1
	ble _081FA262
	bl KillEntity
	b _081FA266
_081FA262:
	adds r1, r5, #1
	strh r1, [r3]
_081FA266:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_081fa26c
FUN_081fa26c: @ 0x081FA26C
	movs r0, #0
	bx lr

	thumb_func_start Entity3FFD_Update
Entity3FFD_Update: @ 0x081FA270
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	ldr r0, [r0, #0x18]
	cmp r0, #0x32
	bhi _081FA34A
	mov r7, sb
	adds r7, #0x38
	ldrh r0, [r7, #0x1e]
	adds r0, #0x28
	strh r0, [r7, #0x1e]
	mov r4, sp
	movs r0, #6
	mov sl, r0
	mov r6, sb
	adds r6, #0x80
_081FA298:
	ldrh r1, [r6]
	movs r2, #0x1c
	adds r2, r2, r7
	mov r8, r2
	ldrh r0, [r7, #0x1c]
	subs r1, r1, r0
	strh r1, [r4]
	ldrh r0, [r6, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r6, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #2
	ldrsh r0, [r4, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	movs r2, #4
	ldrsh r0, [r4, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #7
	cmp r1, r0
	ble _081FA332
	adds r0, r1, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _081FA316
	movs r1, #0
	ldrsh r0, [r4, r1]
	lsls r0, r0, #7
	adds r1, r5, #0
	bl Div
	strh r0, [r4]
	movs r2, #2
	ldrsh r0, [r4, r2]
	lsls r0, r0, #7
	adds r1, r5, #0
	bl Div
	strh r0, [r4, #2]
	movs r1, #4
	ldrsh r0, [r4, r1]
	lsls r0, r0, #7
	adds r1, r5, #0
	bl Div
	strh r0, [r4, #4]
_081FA316:
	ldrh r0, [r4]
	ldrh r2, [r7, #0x1c]
	adds r0, r0, r2
	strh r0, [r6]
	ldrh r0, [r4, #2]
	mov r1, r8
	ldrh r1, [r1, #2]
	adds r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r4, #4]
	mov r2, r8
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r6, #4]
_081FA332:
	adds r7, #0x2c
	adds r6, #0x2c
	movs r0, #1
	rsbs r0, r0, #0
	add sl, r0
	mov r1, sl
	cmp r1, #0
	bge _081FA298
	mov r2, sb
	ldr r0, [r2, #0x18]
	adds r0, #1
	str r0, [r2, #0x18]
_081FA34A:
	movs r0, #0
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity3FFD_Destroy
Entity3FFD_Destroy: @ 0x081FA35C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x38
	movs r5, #7
_081FA364:
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r4, #0x2c
	subs r5, #1
	cmp r5, #0
	bge _081FA364
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start Entity3FFD_Init
Entity3FFD_Init: @ 0x081FA378
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	movs r0, #0x1c
	add r0, r8
	mov sb, r0
	mov r7, r8
	adds r7, #0x38
	movs r6, #0xcc
	lsls r6, r6, #1
	add r6, r8
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081FA3DC
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _081FA3D4 @ =0xFFFF0000
	adds r4, r5, #0
	ldr r1, [sp, #4]
	ands r4, r1
	orrs r4, r0
	str r4, [sp, #4]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r1, _081FA3D8 @ =0x0000FFFF
	ands r4, r1
	orrs r4, r0
	str r4, [sp, #4]
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, [sp, #8]
	ands r5, r2
	orrs r5, r0
	str r5, [sp, #8]
	b _081FA3EE
	.align 2, 0
_081FA3D4: .4byte 0xFFFF0000
_081FA3D8: .4byte 0x0000FFFF
_081FA3DC:
	ldr r0, _081FA45C @ =0xFFFF0000
	ldr r3, [sp, #4]
	ands r3, r0
	str r3, [sp, #4]
	movs r1, #0
	str r1, [sp, #4]
	ldr r2, [sp, #8]
	ands r2, r0
	str r2, [sp, #8]
_081FA3EE:
	ldr r0, _081FA460 @ =0x0000922E
	ldr r1, _081FA464 @ =0x0000C102
	bl GetFile
	movs r4, #0xd4
	lsls r4, r4, #1
	add r4, r8
	str r0, [r4]
	ldr r1, _081FA468 @ =0x0000D636
	mov r0, sb
	bl Video_GetAuxSprite
	ldr r1, [r4]
	movs r0, #0
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #6
	movs r3, #0
	bl AuxAnim_SetAnim
	movs r5, #1
	movs r4, #7
	movs r3, #2
	mov sl, r3
_081FA41E:
	adds r0, r7, #0
	mov r1, sb
	movs r2, #0
	bl AuxSprite_Add
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r3, r1, r0
	ldrh r0, [r3]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r6, #4]
	adds r2, r5, #0
	ands r2, r0
	ldrh r1, [r3]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	ands r0, r5
	cmp r2, r0
	beq _081FA46C
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081FA474
	.align 2, 0
_081FA45C: .4byte 0xFFFF0000
_081FA460: .4byte 0x0000922E
_081FA464: .4byte 0x0000C102
_081FA468: .4byte 0x0000D636
_081FA46C:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081FA474:
	str r0, [r7]
	ldrb r0, [r6, #4]
	mov r1, sl
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r3]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, sl
	ands r0, r2
	cmp r1, r0
	beq _081FA498
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081FA4A0
_081FA498:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081FA4A0:
	str r0, [r7]
	ldrh r0, [r6, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r6, #0xe]
	ldr r3, _081FA4D8 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r6, #7]
	cmp r0, r3
	blo _081FA50E
	strh r1, [r6, #0xe]
	ldrb r1, [r6, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081FA4DC
	ldrh r0, [r6, #8]
	cmp r0, #0
	bne _081FA4D0
	ldrb r0, [r6, #5]
_081FA4D0:
	subs r0, #1
	strh r0, [r6, #8]
	b _081FA4EC
	.align 2, 0
_081FA4D8: .4byte 0x0000FFFF
_081FA4DC:
	ldrh r0, [r6, #8]
	adds r0, #1
	strh r0, [r6, #8]
	ands r0, r2
	ldrb r2, [r6, #5]
	cmp r0, r2
	blo _081FA4EC
	strh r1, [r6, #8]
_081FA4EC:
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r3, r1, r0
	ldrh r1, [r3]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r6, #6]
	ldrb r1, [r6, #6]
	ldrh r0, [r6, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r6, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081FA50E
	strb r5, [r6, #7]
_081FA50E:
	adds r7, #0x2c
	subs r4, #1
	cmp r4, #0
	bge _081FA41E
	movs r0, #0
	mov r3, r8
	str r0, [r3, #0x18]
	movs r1, #0xf9
	lsls r1, r1, #1
	add r1, r8
	strh r0, [r1]
	movs r1, #0xf8
	lsls r1, r1, #1
	add r1, r8
	strh r0, [r1]
	movs r1, #0xf7
	lsls r1, r1, #1
	add r1, r8
	strh r0, [r1]
	movs r1, #0xf6
	lsls r1, r1, #1
	add r1, r8
	strh r0, [r1]
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity3FFD_Create
Entity3FFD_Create: @ 0x081FA54C
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xfa
	lsls r1, r1, #1
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081FA588
	ldr r1, _081FA580 @ =Entity3FFD_Update
	ldr r2, _081FA584 @ =Entity3FFD_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity3FFD_Init
	cmp r0, #0
	bge _081FA588
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081FA58A
	.align 2, 0
_081FA580: .4byte Entity3FFD_Update
_081FA584: .4byte Entity3FFD_Destroy
_081FA588:
	adds r0, r4, #0
_081FA58A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_081fa590
FUN_081fa590: @ 0x081FA590
	movs r1, #0
	strb r1, [r0, #2]
	strb r1, [r0, #1]
	strb r1, [r0]
	str r1, [r0, #0xc]
	str r1, [r0, #8]
	str r1, [r0, #4]
	bx lr

	thumb_func_start FUN_081fa5a0
FUN_081fa5a0: @ 0x081FA5A0
	movs r2, #0
	strb r1, [r0]
	strb r2, [r0, #2]
	strb r2, [r0, #1]
	str r2, [r0, #0xc]
	str r2, [r0, #8]
	str r2, [r0, #4]
	bx lr

	thumb_func_start FUN_081fa5b0
FUN_081fa5b0: @ 0x081FA5B0
	ldrb r1, [r0]
	adds r1, #1
	movs r2, #0
	strb r1, [r0]
	strb r2, [r0, #2]
	strb r2, [r0, #1]
	str r2, [r0, #0xc]
	str r2, [r0, #8]
	str r2, [r0, #4]
	bx lr

	thumb_func_start FUN_081fa5c4
FUN_081fa5c4: @ 0x081FA5C4
	movs r1, #0
	strb r1, [r0, #2]
	strb r1, [r0, #1]
	str r1, [r0, #0xc]
	str r1, [r0, #8]
	bx lr

	thumb_func_start FUN_081fa5d0
FUN_081fa5d0: @ 0x081FA5D0
	movs r2, #0
	strb r1, [r0, #1]
	strb r2, [r0, #2]
	str r2, [r0, #0xc]
	str r2, [r0, #8]
	bx lr

	thumb_func_start FUN_081fa5dc
FUN_081fa5dc: @ 0x081FA5DC
	ldrb r1, [r0, #1]
	adds r1, #1
	movs r2, #0
	strb r1, [r0, #1]
	strb r2, [r0, #2]
	str r2, [r0, #0xc]
	str r2, [r0, #8]
	bx lr

	thumb_func_start FUN_081fa5ec
FUN_081fa5ec: @ 0x081FA5EC
	movs r1, #0
	strb r1, [r0, #2]
	str r1, [r0, #0xc]
	bx lr

	thumb_func_start FUN_081fa5f4
FUN_081fa5f4: @ 0x081FA5F4
	movs r2, #0
	strb r1, [r0, #2]
	str r2, [r0, #0xc]
	bx lr

	thumb_func_start FUN_081fa5fc
FUN_081fa5fc: @ 0x081FA5FC
	ldrb r1, [r0, #2]
	adds r1, #1
	movs r2, #0
	strb r1, [r0, #2]
	str r2, [r0, #0xc]
	bx lr

