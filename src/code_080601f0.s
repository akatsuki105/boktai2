	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080601f0
FUN_080601f0: @ 0x080601F0
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r3, #0x44
	movs r2, #0
	movs r5, #1
	ldr r4, [r0, #0x1c]
_080601FC:
	adds r0, r5, #0
	lsls r0, r2
	ands r0, r4
	cmp r0, #0
	bne _0806020C
	str r2, [r1]
	adds r0, r3, #0
	b _08060218
_0806020C:
	adds r2, #1
	adds r3, #0x3c
	cmp r2, #0x1f
	ble _080601FC
	movs r0, #0
	str r0, [r1]
_08060218:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08060220
FUN_08060220: @ 0x08060220
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r4, r1, #0
	adds r7, r2, #0
	mov r8, r3
	adds r6, r0, #0
	mov r1, sp
	bl FUN_080601f0
	adds r5, r0, #0
	cmp r5, #0
	bne _08060242
	movs r0, #1
	rsbs r0, r0, #0
	b _080602E6
_08060242:
	movs r0, #1
	movs r1, #0
	strb r0, [r5]
	strb r0, [r5, #1]
	strh r1, [r5, #2]
	ldr r0, [sp, #0x1c]
	strh r0, [r5, #0xe]
	strb r4, [r5, #8]
	strh r7, [r5, #4]
	mov r0, r8
	strh r0, [r5, #6]
	ldr r0, [sp, #0x24]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x2c]
	str r1, [r5, #0x30]
	ldr r4, _080602B0 @ =0x0203B400
	ldr r2, _080602B4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r3, _080602B8 @ =0x000003FF
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r3, #0
	ldrb r0, [r0]
	cmp r0, #0x7f
	ble _08060292
	movs r3, #1
_08060292:
	ldr r0, [sp, #0x20]
	strb r0, [r5, #0xd]
	ldrb r0, [r5, #0xa]
	adds r1, r5, #0
	adds r1, #0x10
	adds r0, #0x36
	strh r0, [r1, #0x10]
	adds r2, r1, #0
	cmp r3, #0
	beq _080602BC
	ldr r0, [r5, #0x10]
	movs r1, #4
	orrs r0, r1
	b _080602C4
	.align 2, 0
_080602B0: .4byte 0x0203B400
_080602B4: .4byte 0x030046B8
_080602B8: .4byte 0x000003FF
_080602BC:
	ldr r0, [r5, #0x10]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080602C4:
	str r0, [r5, #0x10]
	ldr r0, [r5, #0x10]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x10]
	adds r0, r2, #0
	movs r1, #0
	bl FUN_0822a340
	ldr r0, [sp]
	movs r1, #1
	lsls r1, r0
	ldr r0, [r6, #0x1c]
	orrs r0, r1
	str r0, [r6, #0x1c]
	movs r0, #0
_080602E6:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080602f4
FUN_080602f4: @ 0x080602F4
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r4, #8
	movs r2, #0
	strb r2, [r1]
	movs r0, #1
	strb r0, [r1, #1]
	strh r2, [r1, #2]
	strh r2, [r1, #4]
	ldr r1, [r5, #0x20]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822da70
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	ldr r1, [r5, #0x20]
	adds r0, r4, #0
	movs r2, #3
	bl FUN_0822dafc
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08060338
FUN_08060338: @ 0x08060338
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, r1, #0
	adds r4, r2, #0
	adds r0, #8
	bl FUN_0822dabc
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x1c]
	bics r0, r1
	str r0, [r5, #0x1c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08060358
FUN_08060358: @ 0x08060358
	bx lr
	.align 2, 0

	thumb_func_start FUN_0806035c
FUN_0806035c: @ 0x0806035C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	adds r3, r4, #0
	adds r3, #8
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _08060372
	movs r0, #0
	strb r0, [r4, #1]
_08060372:
	adds r1, r4, #0
	adds r1, #0x20
	adds r2, r4, #0
	adds r2, #0x30
	ldrh r0, [r4, #0x30]
	ldrh r7, [r3, #0x18]
	adds r0, r0, r7
	strh r0, [r3, #0x18]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r7, [r1, #4]
	adds r0, r0, r7
	strh r0, [r1, #4]
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	cmp r0, r1
	blo _080603B0
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl FUN_08060338
	movs r0, #0
	strb r0, [r4]
	movs r0, #1
	strb r0, [r4, #1]
	movs r0, #0
	strh r0, [r4, #2]
_080603B0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080603b8
FUN_080603b8: @ 0x080603B8
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x24
	movs r5, #0
	ldr r7, _080603F8 @ =0x085ABAAC
_080603C4:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x1c]
	ands r0, r1
	cmp r0, #0
	beq _080603E8
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r3, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl _call_via_r3
	ldrh r0, [r4, #2]
	adds r0, #1
	strh r0, [r4, #2]
_080603E8:
	adds r5, #1
	adds r4, #0x38
	cmp r5, #0xf
	ble _080603C4
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080603F8: .4byte 0x085ABAAC

	thumb_func_start FUN_080603fc
FUN_080603fc: @ 0x080603FC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x24
	movs r4, #0
_08060406:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6, #0x1c]
	ands r0, r1
	cmp r0, #0
	beq _0806041C
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08060338
_0806041C:
	adds r4, #1
	adds r5, #0x38
	cmp r4, #0xf
	ble _08060406
	ldr r1, _08060430 @ =0x03000134
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08060430: .4byte 0x03000134

	thumb_func_start FUN_08060434
FUN_08060434: @ 0x08060434
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _08060468 @ =0x03000134
	str r6, [r0]
	movs r0, #0
	str r0, [r6, #0x1c]
	ldr r0, _0806046C @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x20]
	adds r5, r6, #0
	adds r5, #0x24
	movs r4, #0
_0806044E:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080602f4
	adds r4, #1
	adds r5, #0x38
	cmp r4, #0xf
	ble _0806044E
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08060468: .4byte 0x03000134
_0806046C: .4byte 0x00001C1E

	thumb_func_start FUN_08060470
FUN_08060470: @ 0x08060470
	push {r4, lr}
	ldr r0, _080604A8 @ =0x03000134
	ldr r4, [r0]
	cmp r4, #0
	bne _080604B4
	movs r1, #0xe9
	lsls r1, r1, #2
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080604B4
	ldr r1, _080604AC @ =FUN_080603b8
	ldr r2, _080604B0 @ =FUN_080603fc
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_08060434
	cmp r0, #0
	bge _080604B4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080604B6
	.align 2, 0
_080604A8: .4byte 0x03000134
_080604AC: .4byte FUN_080603b8
_080604B0: .4byte FUN_080603fc
_080604B4:
	adds r0, r4, #0
_080604B6:
	pop {r4}
	pop {r1}
	bx r1

