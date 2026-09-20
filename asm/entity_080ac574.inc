	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080ac3d4
FUN_080ac3d4: @ 0x080AC3D4
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	ldr r1, [r6, #0x30]
	adds r0, r6, #0
	movs r2, #3
	bl FUN_0822dafc
	ldr r0, [r6, #0x28]
	ldr r1, [r6, #0x2c]
	str r0, [r6, #0x18]
	str r1, [r6, #0x1c]
	ldr r5, _080AC454 @ =0x0203B400
	ldr r0, _080AC458 @ =0x030046B8
	mov ip, r0
	ldr r2, [r0]
	adds r2, #1
	ldr r7, _080AC45C @ =0x000003FF
	ands r2, r7
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	ldrh r0, [r6, #0x18]
	subs r0, #0x1f
	movs r3, #0x3f
	ands r1, r3
	adds r0, r0, r1
	movs r4, #0
	strh r0, [r6, #0x18]
	adds r2, #1
	ands r2, r7
	mov r1, ip
	str r2, [r1]
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	ldrh r0, [r6, #0x1c]
	subs r0, #0x1f
	ands r1, r3
	adds r0, r0, r1
	strh r0, [r6, #0x1c]
	strh r4, [r6, #0x38]
	ldrh r0, [r6, #0x3e]
	cmp r0, #0
	beq _080AC460
	adds r0, r2, #1
	ands r0, r7
	mov r1, ip
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ldrh r1, [r6, #0x3e]
	bl Mod
	ldrh r1, [r6, #0x3c]
	adds r1, r1, r0
	strh r1, [r6, #0x3a]
	b _080AC464
	.align 2, 0
_080AC454: .4byte 0x0203B400
_080AC458: .4byte 0x030046B8
_080AC45C: .4byte 0x000003FF
_080AC460:
	ldrh r0, [r6, #0x3c]
	strh r0, [r6, #0x3a]
_080AC464:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ac46c
FUN_080ac46c: @ 0x080AC46C
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x38]
	adds r0, #1
	strh r0, [r2, #0x38]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi _080AC48A
	ldr r1, [r2, #0x30]
	adds r0, r2, #0
	movs r2, #3
	bl FUN_0822dafc
	b _080AC4B0
_080AC48A:
	cmp r0, #7
	bhi _080AC49A
	ldr r1, [r2, #0x30]
	adds r0, r2, #0
	movs r2, #2
	bl FUN_0822dafc
	b _080AC4B0
_080AC49A:
	ldrh r1, [r2, #0x3a]
	cmp r0, r1
	bhs _080AC4AA
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	b _080AC4B0
_080AC4AA:
	adds r0, r2, #0
	bl FUN_080ac3d4
_080AC4B0:
	pop {r0}
	bx r0

	thumb_func_start Entity080ac574_Update
Entity080ac574_Update: @ 0x080AC4B4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x18
	movs r5, #3
_080AC4BC:
	ldrh r0, [r4, #0x36]
	cmp r0, #0
	beq _080AC4C8
	adds r0, r4, #0
	bl FUN_080ac46c
_080AC4C8:
	adds r4, #0x40
	subs r5, #1
	cmp r5, #0
	bge _080AC4BC
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start Entity080ac574_Destroy
Entity080ac574_Destroy: @ 0x080AC4D8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x18
	movs r5, #3
_080AC4E0:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x40
	subs r5, #1
	cmp r5, #0
	bge _080AC4E0
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity080ac574_Init
Entity080ac574_Init: @ 0x080AC4F8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	movs r0, #4
	rsbs r0, r0, #0
	mov r8, r0
	movs r7, #0
	mov r5, sb
	adds r5, #0x18
	adds r4, r5, #0
	movs r6, #3
_080AC512:
	ldr r0, _080AC56C @ =0x00001C1E
	bl GetParticleGroup
	adds r1, r0, #0
	str r1, [r4, #0x30]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0822d9f0
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0822dadc
	adds r0, r5, #0
	mov r1, r8
	mov r2, r8
	bl Particle_SetOffset
	movs r0, #2
	strb r0, [r4, #0xf]
	movs r0, #0xec
	strb r0, [r4, #0x10]
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	strh r7, [r4, #0x34]
	strh r7, [r4, #0x36]
	adds r4, #0x40
	adds r5, #0x40
	subs r6, #1
	cmp r6, #0
	bge _080AC512
	ldr r0, _080AC570 @ =0x0000A854
	mov r1, sb
	movs r2, #0
	bl FUN_08230e30
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AC56C: .4byte 0x00001C1E
_080AC570: .4byte 0x0000A854

	thumb_func_start Entity080ac574_Create
Entity080ac574_Create: @ 0x080AC574
	push {r4, lr}
	movs r1, #0x8c
	lsls r1, r1, #1
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080AC5AC
	ldr r1, _080AC5A4 @ =Entity080ac574_Update
	ldr r2, _080AC5A8 @ =Entity080ac574_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity080ac574_Init
	cmp r0, #0
	bge _080AC5AC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080AC5AE
	.align 2, 0
_080AC5A4: .4byte Entity080ac574_Update
_080AC5A8: .4byte Entity080ac574_Destroy
_080AC5AC:
	adds r0, r4, #0
_080AC5AE:
	pop {r4}
	pop {r1}
	bx r1
