	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0801a170
FUN_0801a170: @ 0x0801A170
	bx lr
	.align 2, 0

	thumb_func_start FUN_0801a174
FUN_0801a174: @ 0x0801A174
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	adds r7, r1, #0
	movs r1, #0xa
	ldrsh r0, [r7, r1]
	mov r2, r8
	movs r3, #0x1e
	ldrsh r1, [r2, r3]
	ldrb r5, [r7, #5]
	adds r1, r1, r5
	subs r1, r0, r1
	movs r0, #0x96
	lsls r0, r0, #3
	cmp r1, r0
	ble _0801A1B8
	ldrh r0, [r7, #0xa]
	subs r0, #0x18
	strh r0, [r7, #0xa]
	adds r6, r7, #0
	adds r6, #0x18
	movs r1, #1
	movs r4, #2
_0801A1A8:
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	subs r4, #1
	adds r6, #0x28
	cmp r4, #0
	bge _0801A1A8
	b _0801A3A0
_0801A1B8:
	cmp r1, #0x18
	bgt _0801A1BE
	b _0801A2FA
_0801A1BE:
	ldrh r0, [r7, #0xa]
	subs r0, #0x18
	strh r0, [r7, #0xa]
	adds r6, r7, #0
	adds r6, #0x18
	ldr r0, [r7, #0x18]
	movs r1, #2
	rsbs r1, r1, #0
	mov sb, r1
	ands r0, r1
	str r0, [r7, #0x18]
	ldrb r0, [r7, #2]
	cmp r0, #0
	bne _0801A2AC
	movs r0, #0x18
	strb r0, [r7, #2]
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r1, [r0]
	movs r2, #1
	mov ip, r2
	orrs r1, r2
	str r1, [r0]
	ldrb r0, [r7, #1]
	adds r0, #1
	strb r0, [r7, #1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0801A204
	mov r3, ip
	strb r3, [r7, #1]
_0801A204:
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r6, r0
	ldr r5, _0801A2A0 @ =0x0203B400
	mov sl, r5
	ldr r4, _0801A2A4 @ =0x030046B8
	ldr r2, [r4]
	adds r2, #1
	ldr r3, _0801A2A8 @ =0x000003FF
	ands r2, r3
	lsls r1, r2, #1
	add r1, sl
	ldrh r1, [r1]
	mov r5, ip
	ands r1, r5
	subs r1, #4
	adds r2, #1
	ands r2, r3
	str r2, [r4]
	lsls r2, r2, #1
	add r2, sl
	ldrh r2, [r2]
	ands r2, r5
	subs r2, #4
	bl Particle_SetOffset
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r6, r0
	mov r2, r8
	ldr r1, [r2, #0x28]
	movs r2, #2
	bl FUN_0822dafc
	ldrb r0, [r7, #1]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r3, r8
	ldr r0, [r3, #0x28]
	ldrb r0, [r0, #6]
	adds r0, #1
	strb r0, [r1, #0xe]
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r1, [r0]
	mov r5, sb
	ands r1, r5
	str r1, [r0]
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #2
	orrs r1, r2
	str r1, [r0]
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r1, [r7, #8]
	ldr r2, [r7, #0xc]
	str r1, [r0, #0x18]
	str r2, [r0, #0x1c]
	b _0801A3A0
	.align 2, 0
_0801A2A0: .4byte 0x0203B400
_0801A2A4: .4byte 0x030046B8
_0801A2A8: .4byte 0x000003FF
_0801A2AC:
	subs r0, #1
	strb r0, [r7, #2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x16
	bne _0801A2E0
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r6, r0
	mov r2, r8
	ldr r1, [r2, #0x28]
	movs r2, #2
	bl FUN_0822dafc
	ldrb r0, [r7, #1]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r3, r8
	ldr r0, [r3, #0x28]
	ldrb r0, [r0, #6]
	adds r0, #1
	strb r0, [r1, #0xe]
_0801A2E0:
	ldrb r0, [r7, #2]
	cmp r0, #0x14
	bne _0801A3A0
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _0801A3A0
_0801A2FA:
	movs r1, #0
	movs r0, #2
	strb r0, [r7]
	strh r1, [r7, #6]
	ldr r2, _0801A3B8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0801A3BC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r5, _0801A3C0 @ =0x0203B400
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	adds r0, #4
	strb r0, [r7, #3]
	adds r6, r7, #0
	adds r6, #0x18
	movs r4, #0
	movs r0, #0x10
	adds r0, r0, r7
	mov sl, r0
	movs r1, #0x13
	adds r1, r1, r7
	mov sb, r1
	adds r5, r2, #0
_0801A332:
	ldr r1, [r6]
	movs r0, #0x80
	lsls r0, r0, #2
	orrs r1, r0
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r6]
	mov r2, r8
	ldr r1, [r2, #0x28]
	adds r0, r6, #0
	movs r2, #2
	bl FUN_0822dafc
	mov r3, r8
	ldr r0, [r3, #0x28]
	ldrb r0, [r0, #6]
	adds r0, #1
	strb r0, [r6, #0xe]
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r6, #0
	adds r1, r2, #0
	bl Particle_SetOffset
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r6, #0x18]
	str r1, [r6, #0x1c]
	mov r0, sl
	adds r1, r0, r4
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _0801A3BC @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r1, _0801A3C0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	mov r3, sb
	adds r2, r3, r4
	movs r0, #3
	ands r1, r0
	strb r1, [r2]
	adds r4, #1
	adds r6, #0x28
	cmp r4, #2
	ble _0801A332
	ldr r0, _0801A3C4 @ =0x03002BE0
	ldr r0, [r0]
	bl FUN_0807a8e0
_0801A3A0:
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r7, #0x30]
	str r1, [r7, #0x34]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801A3B8: .4byte 0x030046B8
_0801A3BC: .4byte 0x000003FF
_0801A3C0: .4byte 0x0203B400
_0801A3C4: .4byte 0x03002BE0

	thumb_func_start FUN_0801a3c8
FUN_0801a3c8: @ 0x0801A3C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sl, r0
	adds r6, r1, #0
	ldrb r0, [r6, #4]
	mov sb, r0
	adds r4, r6, #0
	adds r4, #0x18
	movs r1, #0
	mov r8, r1
_0801A3E4:
	mov r0, sb
	adds r0, #0x40
	movs r2, #0xff
	ands r0, r2
	lsls r0, r0, #1
	ldr r7, _0801A424 @ =0x085B0A08
	adds r0, r0, r7
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrb r0, [r6, #3]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	ldrh r7, [r4, #0x18]
	adds r0, r0, r7
	strh r0, [r4, #0x18]
	ldrh r0, [r6, #6]
	cmp r0, #0x18
	bhi _0801A43A
	lsls r0, r0, #2
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r2, _0801A424 @ =0x085B0A08
	adds r0, r0, r2
	movs r7, #0
	ldrsh r0, [r0, r7]
	lsls r0, r0, #6
	cmp r0, #0
	blt _0801A428
	asrs r1, r0, #0xc
	b _0801A42E
	.align 2, 0
_0801A424: .4byte 0x085B0A08
_0801A428:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0801A42E:
	mov r2, sl
	ldrh r0, [r2, #0x1e]
	adds r0, r0, r1
	ldrb r7, [r6, #5]
	adds r0, r0, r7
	b _0801A43E
_0801A43A:
	ldrh r0, [r4, #0x1a]
	subs r0, #0xa
_0801A43E:
	strh r0, [r4, #0x1a]
	mov r1, sb
	lsls r0, r1, #1
	ldr r2, _0801A524 @ =0x085B0A08
	adds r0, r0, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldrb r0, [r6, #3]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	ldrh r1, [r4, #0x1c]
	adds r0, r0, r1
	movs r2, #0
	mov ip, r2
	strh r0, [r4, #0x1c]
	adds r0, r6, #0
	adds r0, #0x13
	mov r7, r8
	adds r5, r0, r7
	ldrb r1, [r5]
	adds r1, #1
	strb r1, [r5]
	movs r2, #0xff
	mov r0, sp
	strb r2, [r0]
	lsls r1, r1, #0x18
	ldr r2, _0801A528 @ =0x085AA970
	adds r0, r6, #0
	adds r0, #0x10
	adds r3, r0, r7
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	lsrs r1, r1, #0x18
	ldrh r0, [r0]
	cmp r1, r0
	blo _0801A4B6
	mov r7, ip
	strb r7, [r5]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	mov r1, sp
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #1
	bls _0801A4A0
	mov r2, ip
	strb r2, [r3]
_0801A4A0:
	mov r7, sl
	ldr r1, [r7, #0x28]
	ldrb r2, [r3]
	adds r2, #2
	adds r0, r4, #0
	bl FUN_0822dafc
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #6]
	adds r0, #1
	strb r0, [r4, #0xe]
_0801A4B6:
	ldr r2, _0801A52C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0801A530 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0801A534 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	adds r1, #0x4c
	mov r2, sb
	lsls r0, r2, #0x18
	asrs r0, r0, #0x18
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	movs r7, #1
	add r8, r7
	adds r4, #0x28
	mov r0, r8
	cmp r0, #2
	bgt _0801A4EC
	b _0801A3E4
_0801A4EC:
	ldrh r0, [r6, #6]
	cmp r0, #0x1f
	bls _0801A514
	adds r4, r6, #0
	adds r4, #0x18
	movs r1, #1
	movs r2, #2
	mov r8, r2
_0801A4FC:
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r7, #1
	rsbs r7, r7, #0
	add r8, r7
	adds r4, #0x28
	mov r0, r8
	cmp r0, #0
	bge _0801A4FC
	movs r0, #0
	strb r0, [r6]
_0801A514:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801A524: .4byte 0x085B0A08
_0801A528: .4byte 0x085AA970
_0801A52C: .4byte 0x030046B8
_0801A530: .4byte 0x000003FF
_0801A534: .4byte 0x0203B400

	thumb_func_start Entity4F5C_Update
Entity4F5C_Update: @ 0x0801A538
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	movs r7, #0
	adds r4, r5, #0
	adds r4, #0x2c
	ldr r0, _0801A568 @ =0x085AA974
	mov r8, r0
	movs r6, #2
_0801A55C:
	ldrb r0, [r4]
	cmp r0, #0
	bne _0801A56C
	adds r7, #1
	b _0801A582
	.align 2, 0
_0801A568: .4byte 0x085AA974
_0801A56C:
	ldrb r0, [r4]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	bl _call_via_r2
	ldrh r0, [r4, #6]
	adds r0, #1
	strh r0, [r4, #6]
_0801A582:
	subs r6, #1
	adds r4, #0x90
	cmp r6, #0
	bge _0801A55C
	cmp r7, #3
	bne _0801A5A4
	ldrh r0, [r5, #0x1a]
	cmp r0, #0
	beq _0801A59E
	movs r1, #0
	bl VM_ExecByID
	movs r0, #0
	strh r0, [r5, #0x1a]
_0801A59E:
	adds r0, r5, #0
	bl KillEntity
_0801A5A4:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity4F5C_Destroy
Entity4F5C_Destroy: @ 0x0801A5B0
	push {r4, r5, r6, r7, lr}
	adds r0, #0x2c
	movs r1, #0
_0801A5B6:
	adds r6, r1, #1
	adds r7, r0, #0
	adds r7, #0x90
	adds r4, r0, #0
	adds r4, #0x18
	movs r5, #2
_0801A5C2:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x28
	subs r5, #1
	cmp r5, #0
	bge _0801A5C2
	adds r1, r6, #0
	adds r0, r7, #0
	cmp r1, #2
	ble _0801A5B6
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity4F5C_Init
Entity4F5C_Init: @ 0x0801A5E0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r0, _0801A604 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xee
	lsls r1, r1, #1
	adds r5, r7, r1
	str r0, [r5]
	cmp r0, #0
	bne _0801A608
	movs r0, #1
	rsbs r0, r0, #0
	b _0801A7FA
	.align 2, 0
_0801A604: .4byte 0x03002BE0
_0801A608:
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	movs r4, #0
	strh r0, [r7, #0x1a]
	ldr r3, [r5]
	ldr r0, [r3, #0x2c]
	ldr r1, [r3, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, [sp]
	asrs r0, r2, #0x10
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldr r1, _0801A6E4 @ =0x0000FFFF
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	ldr r0, [r3, #0x2c]
	ldr r1, [r3, #0x30]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	strh r4, [r7, #0x18]
	ldr r0, _0801A6E8 @ =0x00001C1C
	bl GetParticleGroup
	str r0, [r7, #0x24]
	ldr r0, _0801A6EC @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r7, #0x28]
	adds r5, r7, #0
	adds r5, #0x2c
	mov r8, r4
	ldr r2, _0801A6F0 @ =0x030046B8
	mov sl, r2
_0801A656:
	adds r4, r5, #0
	adds r4, #0x18
	movs r0, #1
	strb r0, [r5]
	strb r0, [r5, #1]
	mov r3, sl
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _0801A6F4 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _0801A6F8 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	strb r0, [r5, #2]
	movs r3, #0
	strb r3, [r5, #3]
	mov r1, r8
	lsls r0, r1, #8
	movs r1, #3
	bl Div
	mov r3, sl
	ldr r2, [r3]
	adds r2, #1
	ldr r1, _0801A6F4 @ =0x000003FF
	ands r2, r1
	str r2, [r3]
	lsls r1, r2, #1
	ldr r3, _0801A6F8 @ =0x0203B400
	adds r1, r1, r3
	ldrh r1, [r1]
	movs r3, #0x3f
	ands r1, r3
	adds r0, r0, r1
	strb r0, [r5, #4]
	movs r0, #0
	strh r0, [r5, #6]
	ldrb r1, [r5, #4]
	adds r2, #1
	ldr r3, _0801A6F4 @ =0x000003FF
	ands r2, r3
	mov r0, sl
	str r2, [r0]
	lsls r2, r2, #1
	ldr r3, _0801A6F8 @ =0x0203B400
	adds r2, r2, r3
	ldrh r2, [r2]
	movs r0, #0x3f
	adds r3, r5, #0
	adds r3, #8
	adds r6, r1, #0
	ands r2, r0
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r1, _0801A6FC @ =0x085B0A08
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _0801A700
	asrs r0, r0, #0xc
	b _0801A706
	.align 2, 0
_0801A6E4: .4byte 0x0000FFFF
_0801A6E8: .4byte 0x00001C1C
_0801A6EC: .4byte 0x00001C1E
_0801A6F0: .4byte 0x030046B8
_0801A6F4: .4byte 0x000003FF
_0801A6F8: .4byte 0x0203B400
_0801A6FC: .4byte 0x085B0A08
_0801A700:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0801A706:
	strh r0, [r3]
	movs r0, #0
	strh r0, [r3, #2]
	lsls r0, r6, #1
	ldr r1, _0801A720 @ =0x085B0A08
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _0801A724
	asrs r0, r0, #0xc
	b _0801A72A
	.align 2, 0
_0801A720: .4byte 0x085B0A08
_0801A724:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0801A72A:
	strh r0, [r3, #4]
	mov r2, sl
	ldr r0, [r2]
	adds r0, #1
	ldr r3, _0801A7A8 @ =0x000003FF
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0801A7AC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	subs r0, #0x24
	strb r0, [r5, #5]
	mov r2, sp
	ldrh r0, [r2]
	ldrh r3, [r5, #8]
	adds r0, r0, r3
	strh r0, [r5, #8]
	ldr r1, _0801A7B0 @ =0x085AA980
	mov r2, r8
	lsls r0, r2, #1
	adds r0, r0, r1
	ldr r3, [sp]
	asrs r1, r3, #0x10
	ldrh r0, [r0]
	adds r1, r1, r0
	ldrh r0, [r5, #0xa]
	adds r0, r0, r1
	strh r0, [r5, #0xa]
	mov r1, sp
	ldrh r0, [r1, #4]
	ldrh r2, [r5, #0xc]
	adds r0, r0, r2
	strh r0, [r5, #0xc]
	movs r6, #0
	movs r3, #1
	add r8, r3
	movs r0, #0x90
	adds r0, r0, r5
	mov sb, r0
_0801A77E:
	ldr r1, [r7, #0x24]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl Particle_SetOffset
	cmp r6, #0
	bne _0801A7B4
	ldr r1, [r7, #0x24]
	adds r0, r4, #0
	movs r2, #0x1c
	bl FUN_0822dafc
	ldr r0, [r7, #0x24]
	ldrh r0, [r0, #6]
	b _0801A7C4
	.align 2, 0
_0801A7A8: .4byte 0x000003FF
_0801A7AC: .4byte 0x0203B400
_0801A7B0: .4byte 0x085AA980
_0801A7B4:
	ldr r1, [r7, #0x28]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_0822dafc
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #6]
	adds r0, #1
_0801A7C4:
	strb r0, [r4, #0xe]
	ldrh r0, [r5, #8]
	ldrh r1, [r4, #0x18]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldrh r0, [r5, #0xa]
	ldrh r2, [r4, #0x1a]
	adds r0, r0, r2
	strh r0, [r4, #0x1a]
	ldrh r0, [r5, #0xc]
	ldrh r3, [r4, #0x1c]
	adds r0, r0, r3
	strh r0, [r4, #0x1c]
	adds r6, #1
	adds r4, #0x28
	cmp r6, #2
	ble _0801A77E
	mov r5, sb
	mov r0, r8
	cmp r0, #2
	bgt _0801A7F0
	b _0801A656
_0801A7F0:
	movs r0, #0x9f
	lsls r0, r0, #2
	bl PlaySound_082406e0
	movs r0, #0
_0801A7FA:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity4F5C_Create
Entity4F5C_Create: @ 0x0801A80C
	push {r4, lr}
	movs r1, #0xf0
	lsls r1, r1, #1
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801A844
	ldr r1, _0801A83C @ =Entity4F5C_Update
	ldr r2, _0801A840 @ =Entity4F5C_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity4F5C_Init
	cmp r0, #0
	bge _0801A844
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801A846
	.align 2, 0
_0801A83C: .4byte Entity4F5C_Update
_0801A840: .4byte Entity4F5C_Destroy
_0801A844:
	adds r0, r4, #0
_0801A846:
	pop {r4}
	pop {r1}
	bx r1
