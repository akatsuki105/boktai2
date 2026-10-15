	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081f74a4
FUN_081f74a4: @ 0x081F74A4
	push {r4, r5, r6, lr}
	mov ip, r0
	movs r2, #0
	movs r5, #1
	mov r3, ip
	adds r3, #0x83
	mov r4, ip
	adds r4, #0x3c
_081F74B4:
	adds r0, r5, #0
	lsls r0, r2
	mov r6, ip
	ldr r1, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F74C6
	movs r0, #1
	b _081F74C8
_081F74C6:
	movs r0, #0
_081F74C8:
	cmp r0, #0
	bne _081F74DC
	adds r0, r5, #0
	lsls r0, r2
	orrs r0, r1
	mov r1, ip
	str r0, [r1, #0x38]
	strb r2, [r3]
	adds r0, r4, #0
	b _081F74E8
_081F74DC:
	adds r3, #0x48
	adds r4, #0x48
	adds r2, #1
	cmp r2, #0xf
	ble _081F74B4
	movs r0, #0
_081F74E8:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081f74f0
FUN_081f74f0: @ 0x081F74F0
	bx lr
	.align 2, 0

	thumb_func_start FUN_081f74f4
FUN_081f74f4: @ 0x081F74F4
	push {r4, r5, r6, lr}
	adds r6, r1, #0
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
	beq _081F7528
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081F7530
_081F7528:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F7530:
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
	beq _081F7554
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081F755C
_081F7554:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F755C:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081F7594 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081F75DA
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F759E
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F7598
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081F75B4
	.align 2, 0
_081F7594: .4byte 0x0000FFFF
_081F7598:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F75B2
_081F759E:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F75B2
	strh r1, [r4, #8]
	movs r2, #1
	b _081F75B4
_081F75B2:
	movs r2, #0
_081F75B4:
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
	bne _081F75DC
	movs r0, #1
	strb r0, [r4, #7]
	b _081F75DC
_081F75DA:
	movs r2, #0
_081F75DC:
	cmp r2, #0
	beq _081F75E8
	adds r1, r6, #0
	adds r1, #0x46
	movs r0, #2
	strb r0, [r1]
_081F75E8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081f75f0
FUN_081f75f0: @ 0x081F75F0
	push {r4, lr}
	sub sp, #4
	adds r4, r1, #0
	ldr r0, [r4, #0x40]
	cmp r0, #0
	ble _081F7602
	subs r0, #1
	str r0, [r4, #0x40]
	b _081F761C
_081F7602:
	adds r0, r4, #0
	adds r0, #0x2c
	ldr r1, [r4, #0x3c]
	movs r2, #0
	str r2, [sp]
	movs r2, #1
	movs r3, #1
	bl AuxAnim_SetAnim
	adds r1, r4, #0
	adds r1, #0x46
	movs r0, #3
	strb r0, [r1]
_081F761C:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081f7624
FUN_081f7624: @ 0x081F7624
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
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
	beq _081F765A
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081F7662
_081F765A:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F7662:
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
	beq _081F7686
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081F768E
_081F7686:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F768E:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081F76C8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081F770E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F76D2
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F76CC
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081F76E8
	.align 2, 0
_081F76C8: .4byte 0x0000FFFF
_081F76CC:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F76E6
_081F76D2:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F76E6
	strh r1, [r4, #8]
	movs r2, #1
	b _081F76E8
_081F76E6:
	movs r2, #0
_081F76E8:
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
	bne _081F7710
	movs r0, #1
	strb r0, [r4, #7]
	b _081F7710
_081F770E:
	movs r2, #0
_081F7710:
	cmp r2, #0
	beq _081F7738
	adds r0, r6, #0
	bl AuxSprite_Remove
	adds r2, r6, #0
	adds r2, #0x47
	movs r0, #0
	ldrsb r0, [r2, r0]
	movs r1, #1
	lsls r1, r0
	ldr r0, [r7, #0x38]
	bics r0, r1
	str r0, [r7, #0x38]
	movs r0, #0xff
	strb r0, [r2]
	adds r1, r6, #0
	adds r1, #0x46
	movs r0, #0
	strb r0, [r1]
_081F7738:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081f7740
FUN_081f7740: @ 0x081F7740
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sb, r0
	mov r8, r1
	ldr r0, _081F77E8 @ =0x03000200
	ldr r4, [r0]
	cmp r4, #0
	bne _081F7764
	bl Entity081f7974_Create
	adds r4, r0, #0
	cmp r4, #0
	bne _081F7764
	b _081F789C
_081F7764:
	adds r0, r4, #0
	bl FUN_081f74a4
	adds r7, r0, #0
	cmp r7, #0
	bne _081F7772
	b _081F789C
_081F7772:
	adds r0, #0x46
	movs r6, #0
	movs r1, #1
	mov sl, r1
	mov r2, sl
	strb r2, [r0]
	mov r0, r8
	str r0, [r7, #0x40]
	adds r0, r7, #0
	adds r0, #0x44
	strh r6, [r0]
	adds r5, r7, #0
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	ldr r0, _081F77EC @ =0x0000922E
	ldr r1, _081F77F0 @ =0x0000121B
	bl GetFile
	str r0, [r5, #0x3c]
	adds r1, r4, #0
	adds r1, #0x18
	adds r0, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r4, r5, #0
	adds r4, #0x2c
	ldr r1, [r5, #0x3c]
	str r6, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl AuxAnim_SetAnim
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	mov r1, sl
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, sl
	ands r0, r2
	cmp r1, r0
	beq _081F77F4
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081F77FC
	.align 2, 0
_081F77E8: .4byte 0x03000200
_081F77EC: .4byte 0x0000922E
_081F77F0: .4byte 0x0000121B
_081F77F4:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F77FC:
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
	beq _081F7820
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081F7828
_081F7820:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F7828:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081F7860 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081F7898
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F7864
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F7858
	ldrb r0, [r4, #5]
_081F7858:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F7874
	.align 2, 0
_081F7860: .4byte 0x0000FFFF
_081F7864:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F7874
	strh r1, [r4, #8]
_081F7874:
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
	bne _081F7898
	movs r0, #1
	strb r0, [r4, #7]
_081F7898:
	movs r0, #3
	strb r0, [r5, #7]
_081F789C:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start Entity081f7974_Update
Entity081f7974_Update: @ 0x081F78AC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x3c
	ldr r0, [r4, #0x38]
	cmp r0, #0
	beq _081F7900
	movs r7, #0
	ldr r0, _081F78DC @ =0x085AE5A4
	mov r8, r0
	adds r6, r4, #0
	adds r6, #0x82
	adds r5, r1, #0
_081F78CA:
	movs r1, #1
	lsls r1, r7
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F78E0
	movs r0, #1
	b _081F78E2
	.align 2, 0
_081F78DC: .4byte 0x085AE5A4
_081F78E0:
	movs r0, #0
_081F78E2:
	cmp r0, #0
	beq _081F78F6
	ldrb r0, [r6]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r4, #0
	adds r1, r5, #0
	bl _call_via_r2
_081F78F6:
	adds r6, #0x48
	adds r5, #0x48
	adds r7, #1
	cmp r7, #0xf
	ble _081F78CA
_081F7900:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity081f7974_Destroy
Entity081f7974_Destroy: @ 0x081F790C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	adds r4, r6, #0
	adds r4, #0x3c
_081F7916:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F7926
	movs r0, #1
	b _081F7928
_081F7926:
	movs r0, #0
_081F7928:
	cmp r0, #0
	beq _081F7932
	adds r0, r4, #0
	bl AuxSprite_Remove
_081F7932:
	adds r4, #0x48
	adds r5, #1
	cmp r5, #0xf
	ble _081F7916
	movs r1, #0
	ldr r0, _081F7948 @ =0x03000200
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081F7948: .4byte 0x03000200

	thumb_func_start Entity081f7974_Init
Entity081f7974_Init: @ 0x081F794C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	str r0, [r4, #0x38]
	adds r0, r4, #0
	adds r0, #0x18
	ldr r1, _081F796C @ =0x0000F422
	bl Video_GetAuxSprite
	ldr r0, _081F7970 @ =0x03000200
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081F796C: .4byte 0x0000F422
_081F7970: .4byte 0x03000200

	thumb_func_start Entity081f7974_Create
Entity081f7974_Create: @ 0x081F7974
	push {r4, lr}
	ldr r0, _081F79A8 @ =0x03000200
	ldr r0, [r0]
	cmp r0, #0
	bne _081F79BA
	ldr r1, _081F79AC @ =0x000004BC
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081F79B8
	ldr r1, _081F79B0 @ =Entity081f7974_Update
	ldr r2, _081F79B4 @ =Entity081f7974_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081f7974_Init
	cmp r0, #0
	bge _081F79B8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081F79BA
	.align 2, 0
_081F79A8: .4byte 0x03000200
_081F79AC: .4byte 0x000004BC
_081F79B0: .4byte Entity081f7974_Update
_081F79B4: .4byte Entity081f7974_Destroy
_081F79B8:
	adds r0, r4, #0
_081F79BA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081f79c0
FUN_081f79c0: @ 0x081F79C0
	ldr r1, _081F79C8 @ =0x03000200
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081F79C8: .4byte 0x03000200
