	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a9044
FUN_080a9044: @ 0x080A9044
	movs r3, #0x80
	lsls r3, r3, #2
	adds r2, r0, r3
	str r1, [r2]
	movs r1, #0xff
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr

	thumb_func_start FUN_080a9058
FUN_080a9058: @ 0x080A9058
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	movs r0, #0
	mov sl, r0
	movs r1, #0xff
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0xb
	bhi _080A907C
	adds r0, r5, #0
	adds r0, #0x24
	bl FUN_08236400
_080A907C:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r2, r2, r5
	mov r8, r2
	movs r7, #0
	adds r6, r5, #0
	adds r6, #0x74
	adds r4, r5, #0
	adds r4, #0x8c
	movs r0, #7
	mov sb, r0
_080A9092:
	mov r1, r8
	ldrh r0, [r1]
	ldrb r2, [r4, #0x15]
	cmp r0, r2
	blo _080A90AC
	adds r0, r5, #0
	adds r0, #0x74
	adds r0, r0, r7
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _080A9170
_080A90AC:
	movs r0, #1
	mov sl, r0
	ldrb r0, [r4, #0x14]
	ldrb r1, [r4, #0x10]
	adds r0, r0, r1
	strb r0, [r4, #0x10]
	ldrh r3, [r4, #0x16]
	ldr r2, _080A90D8 @ =0x085B0A08
	ldrb r0, [r4, #0x10]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080A90DC
	asrs r3, r0, #0xc
	b _080A90E2
	.align 2, 0
_080A90D8: .4byte 0x085B0A08
_080A90DC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080A90E2:
	ldrh r0, [r5, #0x1c]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r1, [r4, #0x16]
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080A90FE
	asrs r1, r0, #0xc
	b _080A9104
_080A90FE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A9104:
	ldrh r0, [r5, #0x20]
	adds r0, r0, r1
	strh r0, [r4, #4]
	mov r0, r8
	ldrh r1, [r0]
	ldrb r2, [r4, #0x12]
	cmp r1, r2
	blo _080A912E
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _080A9126
	ldrb r0, [r4, #0x14]
	cmp r0, #2
	bls _080A9126
	subs r0, #1
	strb r0, [r4, #0x14]
_080A9126:
	ldrh r0, [r4, #2]
	ldrb r1, [r4, #0x11]
	adds r0, r0, r1
	strh r0, [r4, #2]
_080A912E:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _080A9146
	movs r2, #0xfa
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r6, #0
	movs r2, #0xc
	bl FUN_0822dafc
	b _080A915E
_080A9146:
	cmp r0, #4
	bne _080A915E
	adds r0, r7, #0
	adds r0, #0x74
	adds r0, r5, r0
	movs r2, #0xfa
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r1, [r1]
	movs r2, #0xd
	bl FUN_0822dafc
_080A915E:
	ldrb r0, [r4, #0x13]
	adds r0, #1
	movs r1, #0
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _080A9170
	strb r1, [r4, #0x13]
_080A9170:
	adds r7, #0x30
	adds r6, #0x30
	adds r4, #0x30
	movs r0, #1
	rsbs r0, r0, #0
	add sb, r0
	mov r1, sb
	cmp r1, #0
	bge _080A9092
	movs r2, #0xff
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	mov r0, sl
	cmp r0, #0
	bne _080A919A
	adds r0, r5, #0
	bl KillEntity
_080A919A:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start HealingParticles_Update
HealingParticles_Update: @ 0x080A91A8
  .include "asm/func/HealingParticles_Update.inc"

	thumb_func_start HealingParticles_Destroy
HealingParticles_Destroy: @ 0x080A91BC
  .include "asm/func/HealingParticles_Destroy.inc"

	thumb_func_start FUN_080a91dc
FUN_080a91dc: @ 0x080A91DC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r6, _080A92C4 @ =0x0203B400
	ldr r4, _080A92C8 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080A92CC @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrb r0, [r0]
	str r0, [sp]
	ldr r0, _080A92D0 @ =0x00001C1E
	bl GetParticleGroup
	movs r2, #0xfa
	lsls r2, r2, #1
	adds r1, r7, r2
	str r0, [r1]
	movs r3, #0
	mov sb, r3
	adds r6, r4, #0
	mov r8, r5
	movs r0, #0xf
	mov sl, r0
	adds r4, r7, #0
	adds r4, #0x84
	adds r5, r7, #0
	adds r5, #0x74
_080A9222:
	movs r1, #0xfa
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0822d9f0
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r5, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0822dadc
	ldr r2, [r6]
	adds r2, #1
	mov r3, r8
	ands r2, r3
	lsls r0, r2, #1
	ldr r1, _080A92C4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	mov r3, sb
	lsls r0, r3, #5
	ldr r3, [sp]
	adds r0, r3, r0
	mov r3, sl
	ands r1, r3
	adds r0, r0, r1
	strb r0, [r4, #0x18]
	movs r1, #3
	mov r0, sb
	ands r0, r1
	lsls r0, r0, #1
	adds r0, #3
	strb r0, [r4, #0x19]
	adds r2, #1
	mov r0, r8
	ands r2, r0
	lsls r0, r2, #1
	ldr r1, _080A92C4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	adds r0, #0x40
	strh r0, [r4, #0x1e]
	adds r2, #1
	mov r3, r8
	ands r2, r3
	str r2, [r6]
	lsls r2, r2, #1
	ldr r0, _080A92C4 @ =0x0203B400
	adds r2, r2, r0
	ldrh r0, [r2]
	mov r1, sl
	ands r0, r1
	adds r0, #0xc
	strb r0, [r4, #0x1a]
	movs r0, #7
	strb r0, [r4, #0x1c]
	ldrh r2, [r4, #0x1e]
	ldrb r0, [r4, #0x18]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r3, _080A92D4 @ =0x085B0A08
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080A92D8
	asrs r2, r0, #0xc
	b _080A92DE
	.align 2, 0
_080A92C4: .4byte 0x0203B400
_080A92C8: .4byte 0x030046B8
_080A92CC: .4byte 0x000003FF
_080A92D0: .4byte 0x00001C1E
_080A92D4: .4byte 0x085B0A08
_080A92D8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080A92DE:
	ldrh r0, [r7, #0x1c]
	adds r0, r0, r2
	strh r0, [r4, #8]
	ldrh r0, [r7, #0x1e]
	strh r0, [r4, #0xa]
	ldrh r1, [r4, #0x1e]
	ldrb r0, [r4, #0x18]
	lsls r0, r0, #1
	ldr r2, _080A9300 @ =0x085B0A08
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _080A9304
	asrs r1, r0, #0xc
	b _080A930A
	.align 2, 0
_080A9300: .4byte 0x085B0A08
_080A9304:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A930A:
	ldrh r0, [r7, #0x20]
	adds r0, r0, r1
	strh r0, [r4, #0xc]
	movs r0, #2
	strb r0, [r5, #0xf]
	movs r0, #0xec
	strb r0, [r4]
	ldr r0, [r6]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _080A9348 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	strb r1, [r4, #0x1b]
	cmp r1, #3
	bhi _080A934C
	movs r3, #0xfa
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	adds r0, r5, #0
	movs r2, #0xc
	bl FUN_0822dafc
	b _080A935C
	.align 2, 0
_080A9348: .4byte 0x0203B400
_080A934C:
	movs r1, #0xfa
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r5, #0
	movs r2, #0xd
	bl FUN_0822dafc
_080A935C:
	ldr r0, [r6]
	adds r0, #1
	mov r2, r8
	ands r0, r2
	str r0, [r6]
	lsls r0, r0, #1
	ldr r3, _080A9398 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	mov r1, sl
	ands r0, r1
	adds r0, #0x38
	strb r0, [r4, #0x1d]
	adds r4, #0x30
	adds r5, #0x30
	movs r2, #1
	add sb, r2
	mov r3, sb
	cmp r3, #7
	bgt _080A9386
	b _080A9222
_080A9386:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A9398: .4byte 0x0203B400

	thumb_func_start FUN_080a939c
FUN_080a939c: @ 0x080A939C
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x24
	ldr r2, _080A9418 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x64
	orrs r0, r3
	ldr r1, _080A941C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r4, #0
	str r4, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #1
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	movs r3, #0x80
	lsls r3, r3, #8
	str r4, [sp]
	str r4, [sp, #4]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_082364f8
	adds r0, r6, #0
	movs r1, #0
	adds r2, r5, #0
	bl FUN_0823651c
	adds r5, #0x1c
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_082364c4
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A9418: .4byte 0xFFFF0000
_080A941C: .4byte 0x0000FFFF


