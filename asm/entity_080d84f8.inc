	.include "asm/macros.inc"

	.syntax unified
	
	.text

@ Entity080d84f8_Update と Entity080d84f8_Destroy を使う Entity が 3つあって、まだファイル分けに自信がないので .s として保留

	thumb_func_start Entity080d84f8_Update
Entity080d84f8_Update: @ 0x080D8334
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xb0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080D8348
	subs r0, #1
	strh r0, [r1]
	b _080D838A
_080D8348:
	adds r5, r4, #0
	adds r5, #0xb2
	ldrh r0, [r5]
	lsrs r0, r0, #2
	strh r0, [r4, #0x28]
	ldrh r0, [r5]
	cmp r0, #0
	bne _080D8368
	ldr r0, [r4, #0x18]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x18]
	ldr r0, _080D8394 @ =0x00000195
	bl PlaySound_082406e0
_080D8368:
	ldrh r0, [r5]
	cmp r0, #7
	bhi _080D8376
	adds r0, r4, #0
	adds r0, #0x60
	bl Hitbox_Register
_080D8376:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x17
	bls _080D838A
	adds r0, r4, #0
	bl KillEntity
_080D838A:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080D8394: .4byte 0x00000195

	thumb_func_start Entity080d84f8_Destroy
Entity080d84f8_Destroy: @ 0x080D8398
	push {lr}
	adds r0, #0x18
	bl AuxSprite_Remove
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d83a8
FUN_080d83a8: @ 0x080D83A8
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r5, r0, #0
	adds r6, r1, #0
	mov r8, r2
	adds r4, r3, #0
	ldr r1, _080D83F8 @ =0x00008639
	adds r0, r6, #0
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r0, #0
	strh r0, [r5, #0x10]
	ldr r0, _080D83FC @ =0x00000113
	adds r4, r4, r0
	adds r0, r6, #0
	adds r1, r4, #0
	bl Video_SetAuxSpritePltt
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	movs r1, #1
	strb r1, [r5, #7]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D83F8: .4byte 0x00008639
_080D83FC: .4byte 0x00000113

	thumb_func_start FUN_080d8400
FUN_080d8400: @ 0x080D8400
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	mov sb, r0
	adds r5, r1, #0
	mov r8, r3
	ldr r6, [sp, #0x3c]
	ldr r7, [sp, #0x40]
	ldr r3, _080D8480 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r3
	movs r4, #0x80
	orrs r0, r4
	ldr r1, _080D8484 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r3
	orrs r0, r4
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r3
	str r0, [r1, #4]
	ldr r3, _080D8488 @ =0x00002001
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	adds r2, r3, #0
	movs r3, #0
	bl Hitbox_Init
	str r6, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	mov r1, r8
	ldr r2, [sp, #0x38]
	movs r3, #0x40
	bl Hitbox_SetAttack
	adds r0, r5, #0
	movs r1, #0
	mov r2, sb
	bl Hitbox_SetHandler
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D8480: .4byte 0xFFFF0000
_080D8484: .4byte 0x0000FFFF
_080D8488: .4byte 0x00002001

	thumb_func_start Entity080d84f8_Init
Entity080d84f8_Init: @ 0x080D848C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	mov r8, r1
	mov sb, r2
	mov sl, r3
	ldr r5, [sp, #0x2c]
	ldr r6, [sp, #0x30]
	ldr r3, [sp, #0x38]
	adds r0, #0x18
	adds r1, r7, #0
	adds r1, #0x44
	mov r2, r8
	bl FUN_080d83a8
	adds r4, r7, #0
	adds r4, #0x60
	str r5, [sp]
	str r6, [sp, #4]
	ldr r0, [sp, #0x34]
	str r0, [sp, #8]
	adds r0, r7, #0
	adds r1, r4, #0
	mov r2, sb
	mov r3, sl
	bl FUN_080d8400
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r7, #0
	adds r0, #0xb0
	movs r1, #0
	mov r2, sp
	ldrh r2, [r2, #0x3c]
	strh r2, [r0]
	adds r0, #2
	strh r1, [r0]
	movs r0, #0
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity080d84f8_Create
Entity080d84f8_Create: @ 0x080D84F8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	movs r0, #0xa
	movs r1, #0xb4
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080D8558
	ldr r1, _080D854C @ =Entity080d84f8_Update
	ldr r2, _080D8550 @ =Entity080d84f8_Destroy
	bl SetEntityRoutine
	str r5, [sp]
	ldr r0, _080D8554 @ =0x00240004
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #0xc]
	movs r0, #0
	str r0, [sp, #0x10]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl Entity080d84f8_Init
	cmp r0, #0
	bge _080D8558
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080D855A
	.align 2, 0
_080D854C: .4byte Entity080d84f8_Update
_080D8550: .4byte Entity080d84f8_Destroy
_080D8554: .4byte 0x00240004
_080D8558:
	adds r0, r4, #0
_080D855A:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d8568
FUN_080d8568: @ 0x080D8568
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	movs r0, #0xa
	movs r1, #0xb4
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080D85C8
	ldr r1, _080D85BC @ =Entity080d84f8_Update
	ldr r2, _080D85C0 @ =Entity080d84f8_Destroy
	bl SetEntityRoutine
	str r5, [sp]
	ldr r0, _080D85C4 @ =0x00240004
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x30]
	str r0, [sp, #0x10]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl Entity080d84f8_Init
	cmp r0, #0
	bge _080D85C8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080D85CA
	.align 2, 0
_080D85BC: .4byte Entity080d84f8_Update
_080D85C0: .4byte Entity080d84f8_Destroy
_080D85C4: .4byte 0x00240004
_080D85C8:
	adds r0, r4, #0
_080D85CA:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d85d8
FUN_080d85d8: @ 0x080D85D8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	movs r0, #0xa
	movs r1, #0xb4
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080D8634
	ldr r1, _080D862C @ =Entity080d84f8_Update
	ldr r2, _080D8630 @ =Entity080d84f8_Destroy
	bl SetEntityRoutine
	str r5, [sp]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #4]
	ldr r0, [sp, #0x30]
	str r0, [sp, #8]
	ldr r0, [sp, #0x34]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x38]
	str r0, [sp, #0x10]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl Entity080d84f8_Init
	cmp r0, #0
	bge _080D8634
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080D8636
	.align 2, 0
_080D862C: .4byte Entity080d84f8_Update
_080D8630: .4byte Entity080d84f8_Destroy
_080D8634:
	adds r0, r4, #0
_080D8636:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
