	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08204830
FUN_08204830: @ 0x08204830
	push {r4, lr}
	ldr r0, _08204844 @ =0x03000220
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #0xf
	bls _0820484C
	b _0820486A
	.align 2, 0
_08204844: .4byte 0x03000220
_08204848:
	adds r0, r1, #0
	b _0820486C
_0820484C:
	adds r1, #0x40
	movs r2, #0
	movs r3, #1
_08204852:
	movs r4, #0x3c
	ldrsh r0, [r1, r4]
	cmp r0, #0
	bgt _08204862
	ldr r0, [r1]
	ands r0, r3
	cmp r0, #0
	bne _08204848
_08204862:
	adds r1, #0x44
	adds r2, #1
	cmp r2, #0xf
	ble _08204852
_0820486A:
	movs r0, #0
_0820486C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08204874
FUN_08204874: @ 0x08204874
	adds r3, r0, #0
	adds r3, #0x3e
	movs r2, #0
	strb r1, [r3]
	adds r0, #0x3f
	strb r2, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_08204884
FUN_08204884: @ 0x08204884
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	ldr r0, _082048D8 @ =0x03000220
	ldr r4, [r0]
	bl FUN_08204830
	adds r5, r0, #0
	cmp r5, #0
	beq _082048EC
	adds r4, #0x3c
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08204874
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	strh r7, [r5, #0x3c]
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #1
	strb r1, [r0]
	ldr r2, [r5]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r5]
	ldrb r0, [r4]
	ands r1, r0
	cmp r1, #0
	bne _082048E0
	movs r0, #0x80
	lsls r0, r0, #2
	orrs r2, r0
	ldr r0, _082048DC @ =0xFFFFFBFF
	b _082048E8
	.align 2, 0
_082048D8: .4byte 0x03000220
_082048DC: .4byte 0xFFFFFBFF
_082048E0:
	movs r0, #0x80
	lsls r0, r0, #3
	orrs r2, r0
	ldr r0, _082048F4 @ =0xFFFFFDFF
_082048E8:
	ands r2, r0
	str r2, [r5]
_082048EC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082048F4: .4byte 0xFFFFFDFF

	thumb_func_start FUN_082048f8
FUN_082048f8: @ 0x082048F8
	push {lr}
	adds r3, r0, #0
	ldr r0, _08204928 @ =0x03000220
	ldr r0, [r0]
	cmp r3, #0
	beq _08204922
	adds r1, r0, #0
	adds r1, #0x3c
	ldrb r0, [r1]
	subs r0, #1
	movs r2, #0
	strb r0, [r1]
	movs r1, #0
	strh r2, [r3, #0x3c]
	adds r0, r3, #0
	adds r0, #0x40
	strb r1, [r0]
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
_08204922:
	pop {r0}
	bx r0
	.align 2, 0
_08204928: .4byte 0x03000220

	thumb_func_start FUN_0820492c
FUN_0820492c: @ 0x0820492C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r3, r0, #0
	adds r5, r1, #0
	adds r4, r5, #0
	adds r4, #0x3f
	ldrb r2, [r4]
	cmp r2, #0
	bne _08204952
	adds r0, r5, #0
	adds r0, #0x2c
	ldr r1, [r3, #0x34]
	str r2, [sp]
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	movs r0, #1
	strb r0, [r4]
_08204952:
	adds r4, r5, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08204982
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0820498A
_08204982:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0820498A:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _082049AE
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _082049B6
_082049AE:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_082049B6:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _082049F0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _08204A36
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _082049FA
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _082049F4
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08204A10
	.align 2, 0
_082049F0: .4byte 0x0000FFFF
_082049F4:
	subs r0, #1
	strh r0, [r4, #8]
	b _08204A0E
_082049FA:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08204A0E
	strh r1, [r4, #8]
	movs r2, #1
	b _08204A10
_08204A0E:
	movs r2, #0
_08204A10:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08204A38
	movs r0, #1
	strb r0, [r4, #7]
	b _08204A38
_08204A36:
	movs r2, #0
_08204A38:
	ldrh r1, [r5, #0x3c]
	movs r3, #0x3c
	ldrsh r0, [r5, r3]
	cmp r0, #0
	ble _08204A46
	subs r0, r1, #1
	strh r0, [r5, #0x3c]
_08204A46:
	movs r1, #0x3c
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bne _08204A5A
	cmp r2, #0
	beq _08204A5A
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08204874
_08204A5A:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08204a64
FUN_08204a64: @ 0x08204A64
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r3, r0, #0
	adds r6, r1, #0
	adds r4, r6, #0
	adds r4, #0x3f
	ldrb r2, [r4]
	cmp r2, #0
	bne _08204A8A
	adds r0, r6, #0
	adds r0, #0x2c
	ldr r1, [r3, #0x34]
	str r2, [sp]
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	movs r0, #1
	strb r0, [r4]
_08204A8A:
	adds r4, r6, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08204ABA
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _08204AC2
_08204ABA:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08204AC2:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08204AE6
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _08204AEE
_08204AE6:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08204AEE:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08204B28 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08204B6E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08204B32
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08204B2C
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08204B48
	.align 2, 0
_08204B28: .4byte 0x0000FFFF
_08204B2C:
	subs r0, #1
	strh r0, [r4, #8]
	b _08204B46
_08204B32:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08204B46
	strh r1, [r4, #8]
	movs r2, #1
	b _08204B48
_08204B46:
	movs r2, #0
_08204B48:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08204B70
	movs r0, #1
	strb r0, [r4, #7]
	b _08204B70
_08204B6E:
	movs r2, #0
_08204B70:
	cmp r2, #0
	beq _08204B7A
	adds r0, r6, #0
	bl FUN_082048f8
_08204B7A:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Entity08204cb8_Update
Entity08204cb8_Update: @ 0x08204B84
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x40
	movs r7, #0
	ldr r0, _08204BC8 @ =0x085AE834
	mov r8, r0
	adds r4, r6, #0
	adds r4, #0x7e
_08204B9A:
	ldrb r0, [r4, #2]
	cmp r0, #1
	bne _08204BB4
	ldrb r0, [r4]
	cmp r0, #1
	bhi _08204BBE
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r6, #0
	adds r1, r5, #0
	bl _call_via_r2
_08204BB4:
	adds r4, #0x44
	adds r5, #0x44
	adds r7, #1
	cmp r7, #0xf
	ble _08204B9A
_08204BBE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08204BC8: .4byte 0x085AE834

	thumb_func_start Entity08204cb8_Destroy
Entity08204cb8_Destroy: @ 0x08204BCC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x40
	movs r5, #0xf
_08204BD4:
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _08204BE0
	adds r0, r4, #0
	bl AuxSprite_Remove
_08204BE0:
	adds r4, #0x44
	subs r5, #1
	cmp r5, #0
	bge _08204BD4
	ldr r1, _08204BF4 @ =0x03000220
	movs r0, #0
	str r0, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08204BF4: .4byte 0x03000220

	thumb_func_start FUN_08204bf8
FUN_08204bf8: @ 0x08204BF8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	adds r4, r7, #0
	adds r4, #0x18
	ldr r1, _08204C70 @ =0x00002E78
	adds r0, r4, #0
	bl Video_GetAuxSprite
	ldr r1, _08204C74 @ =0x00000235
	adds r0, r4, #0
	bl Video_SetAuxSpritePltt
	ldr r0, _08204C78 @ =0x0000922E
	ldr r1, _08204C7C @ =0x000038E2
	bl GetFile
	str r0, [r7, #0x34]
	mov r8, r0
	adds r4, #0x28
	movs r6, #0
	movs r5, #0xf
_08204C28:
	adds r0, r4, #0
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0
	bl AuxSprite_Add
	movs r0, #3
	strb r0, [r4, #7]
	adds r0, r4, #0
	adds r0, #0x2c
	str r6, [sp]
	mov r1, r8
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	strh r6, [r4, #0x3c]
	adds r0, r4, #0
	adds r0, #0x40
	strb r6, [r0]
	adds r4, #0x44
	subs r5, #1
	cmp r5, #0
	bge _08204C28
	movs r0, #0
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08204C70: .4byte 0x00002E78
_08204C74: .4byte 0x00000235
_08204C78: .4byte 0x0000922E
_08204C7C: .4byte 0x000038E2

	thumb_func_start Entity08204cb8_Init
Entity08204cb8_Init: @ 0x08204C80
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x3c
	movs r0, #0
	strb r0, [r1]
	str r0, [r4, #0x38]
	adds r0, r4, #0
	adds r0, #0x18
	ldr r1, _08204CA8 @ =0x00002E78
	bl Video_GetAuxSprite
	adds r0, r4, #0
	bl FUN_08204bf8
	cmp r0, #0
	blt _08204CAC
	movs r0, #0
	b _08204CB0
	.align 2, 0
_08204CA8: .4byte 0x00002E78
_08204CAC:
	movs r0, #1
	rsbs r0, r0, #0
_08204CB0:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity08204cb8_Create
Entity08204cb8_Create: @ 0x08204CB8
	push {r4, lr}
	ldr r0, _08204CF0 @ =0x03000220
	ldr r0, [r0]
	cmp r0, #0
	bne _08204CFE
	movs r1, #0x90
	lsls r1, r1, #3
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08204CFC
	ldr r1, _08204CF4 @ =Entity08204cb8_Update
	ldr r2, _08204CF8 @ =Entity08204cb8_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity08204cb8_Init
	cmp r0, #0
	bge _08204CFC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08204CFE
	.align 2, 0
_08204CF0: .4byte 0x03000220
_08204CF4: .4byte Entity08204cb8_Update
_08204CF8: .4byte Entity08204cb8_Destroy
_08204CFC:
	adds r0, r4, #0
_08204CFE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08204d04
FUN_08204d04: @ 0x08204D04
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r4, _08204D28 @ =0x03000220
	ldr r0, [r4]
	cmp r0, #0
	bne _08204D18
	bl Entity08204cb8_Create
	str r0, [r4]
_08204D18:
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_08204884
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08204D28: .4byte 0x03000220
