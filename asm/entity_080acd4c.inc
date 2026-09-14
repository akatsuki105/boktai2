	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080acc14
FUN_080acc14: @ 0x080ACC14
	ldr r1, _080ACC1C @ =0x03002C54
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080ACC1C: .4byte 0x03002C54

	thumb_func_start FUN_080acc20
FUN_080acc20: @ 0x080ACC20
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x28]
	ldrh r2, [r4, #0x2e]
	lsrs r2, r2, #1
	adds r2, #0xc
	bl FUN_0822dafc
	ldrh r0, [r4, #0x1a]
	adds r0, #0xa
	strh r0, [r4, #0x1a]
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x10
	bne _080ACC54
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	adds r1, r4, #0
	adds r1, #0x2c
	movs r0, #0
	strb r0, [r1]
_080ACC54:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Entity080acd4c_Update
Entity080acd4c_Update: @ 0x080ACC5C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r5, #0x18
	adds r4, r0, #0
	adds r4, #0x44
	movs r6, #7
_080ACC68:
	ldrb r0, [r4]
	cmp r0, #0
	beq _080ACC74
	adds r0, r5, #0
	bl FUN_080acc20
_080ACC74:
	adds r5, #0x30
	adds r4, #0x30
	subs r6, #1
	cmp r6, #0
	bge _080ACC68
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity080acd4c_Destroy
Entity080acd4c_Destroy: @ 0x080ACC88
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x18
	movs r5, #7
_080ACC90:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x30
	subs r5, #1
	cmp r5, #0
	bge _080ACC90
	movs r1, #0
	ldr r0, _080ACCAC @ =0x03002C54
	str r1, [r0]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080ACCAC: .4byte 0x03002C54

	thumb_func_start FUN_080accb0
FUN_080accb0: @ 0x080ACCB0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r1, #0
	mov r8, r1
	adds r4, r0, #0
	adds r4, #0x18
	adds r6, r0, #0
	adds r6, #0x44
	adds r5, r4, #0
	movs r0, #8
	rsbs r0, r0, #0
	mov sb, r0
	movs r7, #7
_080ACCCE:
	mov r1, r8
	strb r1, [r6]
	strb r1, [r6, #1]
	mov r0, r8
	strh r0, [r4, #0x2e]
	ldr r0, _080ACD24 @ =0x00001C1A
	bl GetParticleGroup
	adds r1, r0, #0
	str r1, [r4, #0x28]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0822d9f0
	adds r0, r5, #0
	mov r1, sb
	mov r2, sb
	bl FUN_0822dad4
	ldr r1, [r4, #0x28]
	adds r0, r5, #0
	movs r2, #0xc
	bl FUN_0822dafc
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	movs r0, #2
	strb r0, [r4, #0xf]
	adds r4, #0x30
	adds r6, #0x30
	adds r5, #0x30
	subs r7, #1
	cmp r7, #0
	bge _080ACCCE
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ACD24: .4byte 0x00001C1A

	thumb_func_start Entity080acd4c_Init
Entity080acd4c_Init: @ 0x080ACD28
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080accb0
	movs r0, #0xcc
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	ldr r0, _080ACD48 @ =0x03002C54
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080ACD48: .4byte 0x03002C54

	thumb_func_start Entity080acd4c_Create
Entity080acd4c_Create: @ 0x080ACD4C
	push {r4, lr}
	ldr r0, _080ACD84 @ =0x03002C54
	ldr r0, [r0]
	cmp r0, #0
	bne _080ACD92
	movs r1, #0xce
	lsls r1, r1, #1
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080ACD90
	ldr r1, _080ACD88 @ =Entity080acd4c_Update
	ldr r2, _080ACD8C @ =Entity080acd4c_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity080acd4c_Init
	cmp r0, #0
	bge _080ACD90
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080ACD92
	.align 2, 0
_080ACD84: .4byte 0x03002C54
_080ACD88: .4byte Entity080acd4c_Update
_080ACD8C: .4byte Entity080acd4c_Destroy
_080ACD90:
	adds r0, r4, #0
_080ACD92:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080acd98
FUN_080acd98: @ 0x080ACD98
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, _080ACDF4 @ =0x03002C54
	ldr r0, [r4]
	cmp r0, #0
	bne _080ACDA8
	bl Entity080acd4c_Create
_080ACDA8:
	ldr r2, [r4]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, #0x18
	adds r2, r2, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r2, #0x18]
	str r1, [r2, #0x1c]
	movs r1, #0
	strh r1, [r2, #0x2e]
	adds r2, #0x2c
	movs r0, #1
	strb r0, [r2]
	ldr r0, [r4]
	adds r2, r0, r3
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080ACDEC
	strh r1, [r2]
_080ACDEC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080ACDF4: .4byte 0x03002C54
