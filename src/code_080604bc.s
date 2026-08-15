	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080604bc
FUN_080604bc: @ 0x080604BC
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r3, #0x24
	movs r2, #0
	movs r5, #1
	ldr r4, [r0, #0x1c]
_080604C8:
	adds r0, r5, #0
	lsls r0, r2
	ands r0, r4
	cmp r0, #0
	bne _080604D8
	str r2, [r1]
	adds r0, r3, #0
	b _080604E4
_080604D8:
	adds r2, #1
	adds r3, #0x38
	cmp r2, #0xf
	ble _080604C8
	movs r0, #0
	str r0, [r1]
_080604E4:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080604ec
FUN_080604ec: @ 0x080604EC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	mov r8, r1
	adds r4, r2, #0
	adds r7, r3, #0
	bl FUN_08060470
	mov sb, r0
	mov r1, sp
	bl FUN_080604bc
	adds r3, r0, #0
	cmp r3, #0
	bne _08060518
	movs r0, #1
	rsbs r0, r0, #0
	b _08060622
_08060518:
	adds r5, r3, #0
	adds r5, #8
	movs r0, #1
	movs r1, #0
	strb r0, [r3]
	strb r0, [r3, #1]
	strh r1, [r3, #2]
	strh r4, [r3, #4]
	ldrh r0, [r3, #4]
	adds r4, r3, #0
	adds r4, #0x20
	mov r1, r8
	muls r1, r0, r1
	mov ip, r1
	ldr r2, _08060558 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	mov sl, r2
	cmp r0, #0
	blt _0806055C
	asrs r1, r0, #0xc
	b _08060562
	.align 2, 0
_08060558: .4byte 0x085B0A08
_0806055C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08060562:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r0, r6
	lsls r0, r0, #1
	add r0, sl
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _08060582
	asrs r0, r0, #0xc
	b _08060588
_08060582:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08060588:
	strh r0, [r4, #4]
	adds r1, r5, #0
	adds r1, #0x18
	ldrh r0, [r7]
	ldrh r2, [r5, #0x18]
	adds r0, r0, r2
	strh r0, [r5, #0x18]
	ldrh r0, [r7, #2]
	ldrh r2, [r1, #2]
	adds r0, r0, r2
	strh r0, [r1, #2]
	ldrh r0, [r7, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	ldrh r0, [r3, #4]
	subs r0, #3
	strh r0, [r3, #4]
	adds r2, r3, #0
	adds r2, #0x30
	adds r3, r6, #0
	adds r3, #0x80
	adds r0, r6, #0
	adds r0, #0xc0
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _080605D2
	asrs r1, r0, #0xc
	b _080605D8
_080605D2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080605D8:
	movs r0, #0
	strh r1, [r2]
	strh r0, [r2, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _080605F8
	asrs r0, r0, #0xc
	b _080605FE
_080605F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080605FE:
	strh r0, [r2, #4]
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0822da50
	ldr r0, [sp]
	movs r1, #1
	lsls r1, r0
	mov r2, sb
	ldr r0, [r2, #0x1c]
	orrs r0, r1
	str r0, [r2, #0x1c]
	movs r0, #0
_08060622:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08060634
FUN_08060634: @ 0x08060634
	ldr r1, _0806063C @ =0x03000138
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_0806063C: .4byte 0x03000138

	thumb_func_start FUN_08060640
FUN_08060640: @ 0x08060640
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
_08060646:
	movs r0, #0x58
	muls r0, r5, r0
	adds r1, r6, r0
	ldrb r0, [r1, #0x18]
	cmp r0, #0
	beq _080606E8
	adds r2, r1, #0
	adds r2, #0x18
	adds r3, r2, #0
	adds r3, #0x2c
	ldrh r0, [r2, #2]
	ldrh r1, [r2, #4]
	cmp r0, r1
	blo _080606A8
	movs r0, #8
	ldrsh r1, [r2, r0]
	ldrh r0, [r2, #6]
	muls r1, r0, r1
	adds r4, r0, #0
	cmp r1, #0
	blt _08060674
	asrs r0, r1, #8
	b _0806067A
_08060674:
	rsbs r0, r1, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0806067A:
	strh r0, [r2, #8]
	movs r1, #0xa
	ldrsh r0, [r2, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0806068A
	asrs r0, r0, #8
	b _08060690
_0806068A:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08060690:
	strh r0, [r2, #0xa]
	movs r1, #0xc
	ldrsh r0, [r2, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _080606A0
	asrs r0, r0, #8
	b _080606A6
_080606A0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080606A6:
	strh r0, [r2, #0xc]
_080606A8:
	ldrh r0, [r2, #8]
	ldrh r1, [r3, #0x1c]
	adds r0, r0, r1
	movs r4, #0
	strh r0, [r3, #0x1c]
	ldrh r0, [r2, #0xa]
	ldrh r1, [r3, #0x1e]
	adds r0, r0, r1
	strh r0, [r3, #0x1e]
	ldr r0, [r3]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080606CC
	ldrh r0, [r2, #0xc]
	ldrh r1, [r3, #0x20]
	adds r0, r0, r1
	strh r0, [r3, #0x20]
_080606CC:
	ldrh r0, [r2, #2]
	lsrs r0, r0, #2
	strh r0, [r3, #0x10]
	ldrh r0, [r2, #2]
	adds r0, #1
	strh r0, [r2, #2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x18
	bls _080606E8
	strb r4, [r2]
	adds r0, r3, #0
	bl FUN_0822a4e0
_080606E8:
	adds r5, #1
	cmp r5, #0xf
	ble _08060646
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080606f8
FUN_080606f8: @ 0x080606F8
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
_080606FE:
	movs r0, #0x58
	muls r0, r4, r0
	adds r0, #0x18
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08060714
	adds r0, r1, #0
	adds r0, #0x2c
	bl FUN_0822a4e0
_08060714:
	adds r4, #1
	cmp r4, #0xf
	ble _080606FE
	ldr r1, _08060728 @ =0x03000138
	movs r0, #0
	str r0, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08060728: .4byte 0x03000138

	thumb_func_start FUN_0806072c
FUN_0806072c: @ 0x0806072C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	mov r8, r0
	ldr r0, _0806076C @ =0x03000138
	mov r1, r8
	str r1, [r0]
	ldr r0, _08060770 @ =0xFFFF0000
	movs r5, #0
	ands r6, r0
	movs r3, #0
_08060744:
	movs r0, #0x58
	muls r0, r3, r0
	adds r0, #0x18
	mov r1, r8
	adds r4, r1, r0
	movs r0, #0
	strb r0, [r4]
	adds r7, r4, #0
	adds r7, #0x10
	adds r0, r7, #0
	ldr r1, _08060774 @ =0x00008639
	str r3, [sp]
	bl FUN_0822b16c
	ldr r3, [sp]
	cmp r0, #0
	bne _08060778
	movs r0, #1
	rsbs r0, r0, #0
	b _0806079C
	.align 2, 0
_0806076C: .4byte 0x03000138
_08060770: .4byte 0xFFFF0000
_08060774: .4byte 0x00008639
_08060778:
	adds r0, r4, #0
	adds r0, #0x2c
	adds r1, r7, #0
	movs r2, #0
	str r3, [sp]
	bl FUN_0822a4b0
	adds r1, r4, #0
	adds r1, #0x33
	movs r0, #1
	strb r0, [r1]
	str r5, [r4, #0x48]
	str r6, [r4, #0x4c]
	ldr r3, [sp]
	adds r3, #1
	cmp r3, #0xf
	ble _08060744
	movs r0, #0
_0806079C:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080607a8
FUN_080607a8: @ 0x080607A8
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xb3
	lsls r1, r1, #3
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080607E4
	ldr r1, _080607DC @ =FUN_08060640
	ldr r2, _080607E0 @ =FUN_080606f8
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0806072c
	cmp r0, #0
	bge _080607E4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080607E6
	.align 2, 0
_080607DC: .4byte FUN_08060640
_080607E0: .4byte FUN_080606f8
_080607E4:
	adds r0, r4, #0
_080607E6:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080607ec
FUN_080607ec: @ 0x080607EC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	adds r6, r1, #0
	mov sb, r2
	adds r7, r3, #0
	ldr r0, _08060840 @ =0x03000138
	ldr r0, [r0]
	cmp r0, #0
	bne _08060810
	movs r0, #0
	movs r1, #0
	bl FUN_080607a8
	cmp r0, #0
	beq _080608D0
_08060810:
	movs r3, #0
	ldr r5, _08060840 @ =0x03000138
_08060814:
	movs r0, #0x58
	muls r0, r3, r0
	adds r0, #0x18
	ldr r1, [r5]
	adds r2, r1, r0
	adds r4, r2, #0
	adds r4, #0x2c
	ldrb r0, [r2]
	cmp r0, #0
	bne _080608CA
	movs r0, #1
	strb r0, [r2]
	movs r0, #4
	ands r0, r6
	cmp r0, #0
	beq _08060844
	movs r0, #0xc0
	lsls r0, r0, #8
	ands r0, r6
	asrs r5, r0, #0xc
	b _08060846
	.align 2, 0
_08060840: .4byte 0x03000138
_08060844:
	movs r5, #1
_08060846:
	ldr r0, _08060890 @ =0xFFFF3FFF
	ands r6, r0
	movs r0, #0
	strb r6, [r2, #1]
	strh r0, [r2, #2]
	mov r0, sp
	ldrh r0, [r0, #0x1c]
	strh r0, [r2, #4]
	mov r1, sp
	ldrh r1, [r1, #0x20]
	strh r1, [r2, #6]
	ldr r0, [r7]
	ldr r1, [r7, #4]
	str r0, [r2, #8]
	str r1, [r2, #0xc]
	adds r0, r2, #0
	adds r0, #0x10
	ldr r1, _08060894 @ =0x00000113
	add r1, r8
	bl FUN_0822b20c
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	strb r5, [r4, #7]
	movs r0, #1
	ands r0, r6
	cmp r0, #0
	beq _08060898
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	b _0806089E
	.align 2, 0
_08060890: .4byte 0xFFFF3FFF
_08060894: .4byte 0x00000113
_08060898:
	ldr r0, [r4]
	ldr r1, _080608B0 @ =0xFFFFFDFF
	ands r0, r1
_0806089E:
	str r0, [r4]
	movs r0, #2
	ands r0, r6
	cmp r0, #0
	beq _080608B4
	ldr r0, [r4]
	movs r1, #0x10
	orrs r0, r1
	b _080608BC
	.align 2, 0
_080608B0: .4byte 0xFFFFFDFF
_080608B4:
	ldr r0, [r4]
	movs r1, #0x11
	rsbs r1, r1, #0
	ands r0, r1
_080608BC:
	str r0, [r4]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0822a340
	movs r0, #0
	b _080608D4
_080608CA:
	adds r3, #1
	cmp r3, #0xf
	ble _08060814
_080608D0:
	movs r0, #1
	rsbs r0, r0, #0
_080608D4:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080608e0
FUN_080608e0: @ 0x080608E0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	movs r0, #0x74
	movs r1, #0
	bl Script_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08060940
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08060938 @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0806093C @ =0x0000FFFF
	ldr r1, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	b _0806094A
	.align 2, 0
_08060938: .4byte 0xFFFF0000
_0806093C: .4byte 0x0000FFFF
_08060940:
	ldr r1, _0806098C @ =0xFFFF0000
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
_0806094A:
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _08060994
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0806098C @ =0xFFFF0000
	ldr r1, [sp, #0x10]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x10]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08060990 @ =0x0000FFFF
	ldr r1, [sp, #0x10]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x10]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r2, sp, #0x10
	ldr r1, [r2, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r2, #4]
	adds r5, r2, #0
	b _080609A2
	.align 2, 0
_0806098C: .4byte 0xFFFF0000
_08060990: .4byte 0x0000FFFF
_08060994:
	ldr r2, _080609B8 @ =0xFFFF0000
	str r0, [sp, #0x10]
	add r1, sp, #0x10
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r5, r1, #0
_080609A2:
	movs r0, #0x64
	bl prepare_08231510
	cmp r0, #0
	beq _080609BC
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	b _080609C2
	.align 2, 0
_080609B8: .4byte 0xFFFF0000
_080609BC:
	movs r4, #0x18
	movs r0, #0x80
	lsls r0, r0, #1
_080609C2:
	str r4, [sp]
	str r0, [sp, #4]
	adds r0, r7, #0
	adds r1, r6, #0
	add r2, sp, #8
	adds r3, r5, #0
	bl FUN_080607ec
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

