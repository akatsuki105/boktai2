	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080166ac
FUN_080166ac: @ 0x080166AC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r4, r0, #0
	str r1, [sp, #4]
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	ldr r0, _0801672C @ =0x03000064
	ldr r0, [r0]
	cmp r0, #0
	bne _080166D6
	movs r0, #0
	movs r1, #0
	bl Entity08016ba4_Create
	cmp r0, #0
	bne _080166D6
	b _08016862
_080166D6:
	movs r2, #0
	ldr r3, _0801672C @ =0x03000064
	movs r1, #0x24
_080166DC:
	ldr r0, [r3]
	adds r5, r0, r1
	ldrb r0, [r5]
	cmp r0, #0
	beq _080166E8
	b _08016854
_080166E8:
	movs r0, #1
	strb r0, [r5]
	strb r4, [r5, #1]
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bls _080166FA
	movs r0, #8
	strb r0, [r5, #1]
_080166FA:
	movs r0, #0
	mov sl, r0
	ldrb r1, [r5, #1]
	cmp sl, r1
	blt _08016706
	b _08016846
_08016706:
	ldr r6, _08016730 @ =0x030046B8
	ldr r2, _08016734 @ =0x000003FF
	mov sb, r2
	movs r3, #0x38
	adds r3, r3, r5
	mov r8, r3
	adds r7, r5, #0
	adds r7, #0x10
	adds r4, r5, #4
_08016718:
	movs r0, #1
	strb r0, [r4]
	ldr r0, [sp, #0xc]
	cmp r0, #0
	bne _08016738
	mov r1, sp
	ldrb r1, [r1, #8]
	strb r1, [r4, #1]
	b _08016756
	.align 2, 0
_0801672C: .4byte 0x03000064
_08016730: .4byte 0x030046B8
_08016734: .4byte 0x000003FF
_08016738:
	ldr r0, [r6]
	adds r0, #1
	mov r2, sb
	ands r0, r2
	str r0, [r6]
	lsls r0, r0, #1
	ldr r3, _08016764 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [sp, #0xc]
	bl Mod
	ldr r1, [sp, #8]
	adds r0, r1, r0
	strb r0, [r4, #1]
_08016756:
	ldr r2, [sp, #0x34]
	cmp r2, #0
	bne _08016768
	mov r3, sp
	ldrh r3, [r3, #0x30]
	strh r3, [r4, #2]
	b _08016786
	.align 2, 0
_08016764: .4byte 0x0203B400
_08016768:
	ldr r0, [r6]
	adds r0, #1
	mov r1, sb
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _08016790 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r1, [sp, #0x34]
	bl Mod
	ldr r3, [sp, #0x30]
	adds r0, r3, r0
	strh r0, [r4, #2]
_08016786:
	ldr r0, [sp, #0x3c]
	cmp r0, #0
	bne _08016794
	ldr r2, [sp, #0x38]
	b _080167B0
	.align 2, 0
_08016790: .4byte 0x0203B400
_08016794:
	ldr r0, [r6]
	adds r0, #1
	mov r1, sb
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _080167DC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r1, [sp, #0x3c]
	bl Mod
	ldr r3, [sp, #0x38]
	adds r2, r3, r0
_080167B0:
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r3, _080167E0 @ =0x085B0A08
	adds r0, r0, r3
	ldrh r0, [r0]
	strh r0, [r4, #4]
	ands r2, r1
	lsls r0, r2, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	strh r0, [r4, #8]
	ldr r0, [sp, #0x44]
	cmp r0, #0
	bne _080167E4
	add r1, sp, #0x40
	ldrh r1, [r1]
	strh r1, [r4, #6]
	b _08016802
	.align 2, 0
_080167DC: .4byte 0x0203B400
_080167E0: .4byte 0x085B0A08
_080167E4:
	ldr r0, [r6]
	adds r0, #1
	mov r2, sb
	ands r0, r2
	str r0, [r6]
	lsls r0, r0, #1
	ldr r3, _0801684C @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [sp, #0x44]
	bl Mod
	ldr r1, [sp, #0x40]
	adds r0, r1, r0
	strh r0, [r4, #6]
_08016802:
	ldr r2, [sp, #4]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x24]
	str r1, [r4, #0x28]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_0822da50
	ldr r0, [r4, #0xc]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0xc]
	ldr r0, _08016850 @ =0x03000064
	ldr r0, [r0]
	ldr r1, [r0, #0x20]
	movs r0, #0
	str r0, [sp]
	mov r0, r8
	movs r2, #3
	movs r3, #0
	bl FUN_08236fac
	movs r3, #0x44
	add r8, r3
	adds r7, #0x44
	adds r4, #0x44
	movs r0, #1
	add sl, r0
	ldrb r1, [r5, #1]
	cmp sl, r1
	bge _08016846
	b _08016718
_08016846:
	movs r0, #0
	b _08016866
	.align 2, 0
_0801684C: .4byte 0x0203B400
_08016850: .4byte 0x03000064
_08016854:
	movs r0, #0x89
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r2, #1
	cmp r2, #5
	bgt _08016862
	b _080166DC
_08016862:
	movs r0, #1
	rsbs r0, r0, #0
_08016866:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08016878
FUN_08016878: @ 0x08016878
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	movs r0, #0
	str r0, [sp]
	mov sl, r0
	ldrb r1, [r7, #1]
	cmp sl, r1
	blt _08016894
	b _08016A3E
_08016894:
	adds r2, r7, #5
	mov sb, r2
	movs r3, #0x38
	adds r3, r3, r7
	mov r8, r3
	adds r0, r7, #6
	str r0, [sp, #4]
	adds r4, r7, #0
	adds r4, #8
_080168A6:
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, #0
	bne _080168B0
	b _08016A1C
_080168B0:
	ldr r2, [sp]
	adds r2, #1
	str r2, [sp]
	movs r3, #0
	ldrsh r1, [r4, r3]
	ldr r2, [sp, #4]
	movs r3, #0
	ldrsh r0, [r2, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _080168CA
	asrs r1, r0, #0xc
	b _080168D0
_080168CA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080168D0:
	ldrh r0, [r4, #0x20]
	adds r0, r0, r1
	strh r0, [r4, #0x20]
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #0x22]
	adds r0, r0, r1
	strh r0, [r4, #0x22]
	movs r2, #4
	ldrsh r1, [r4, r2]
	ldr r3, [sp, #4]
	movs r2, #0
	ldrsh r0, [r3, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080168F2
	asrs r1, r0, #0xc
	b _080168F8
_080168F2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080168F8:
	ldrh r0, [r4, #0x24]
	adds r0, r0, r1
	strh r0, [r4, #0x24]
	ldrh r0, [r4, #2]
	subs r0, #2
	strh r0, [r4, #2]
	mov r0, r8
	movs r1, #0x10
	bl FUN_08237098
	ldr r0, _08016950 @ =0x03000064
	ldr r0, [r0]
	ldr r3, [r0, #0x1c]
	mov r5, r8
	ldrh r0, [r4, #0x38]
	lsls r0, r0, #1
	ldr r1, [r4, #0x30]
	adds r6, r1, r0
	ldrh r2, [r6]
	lsrs r2, r2, #6
	ldrb r1, [r4, #0x12]
	lsrs r1, r1, #3
	ldrb r0, [r4, #0x13]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r4, #0x10]
	ldrb r0, [r5, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r6]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r3, #1
	ands r0, r3
	cmp r2, r0
	beq _08016954
	ldr r0, [r4, #8]
	movs r1, #4
	orrs r0, r1
	b _0801695C
	.align 2, 0
_08016950: .4byte 0x03000064
_08016954:
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0801695C:
	str r0, [r4, #8]
	ldrb r0, [r5, #4]
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
	beq _08016980
	ldr r0, [r4, #8]
	movs r1, #8
	orrs r0, r1
	b _08016988
_08016980:
	ldr r0, [r4, #8]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08016988:
	str r0, [r4, #8]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r5, #0xe]
	ldr r3, _080169C0 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r5, #7]
	cmp r0, r3
	blo _080169EA
	strh r1, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080169C4
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _080169B8
	ldrb r0, [r5, #5]
_080169B8:
	subs r0, #1
	strh r0, [r5, #8]
	b _080169D4
	.align 2, 0
_080169C0: .4byte 0x0000FFFF
_080169C4:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _080169D4
	strh r1, [r5, #8]
_080169D4:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r5, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r5, #7]
_080169EA:
	mov r3, sb
	ldrb r0, [r3]
	adds r1, r0, #0
	adds r2, r0, #0
	cmp r1, #8
	bls _080169FE
	ldrh r0, [r4, #0x38]
	cmp r0, #5
	bne _08016A06
	b _08016A02
_080169FE:
	cmp r1, #8
	bne _08016A06
_08016A02:
	movs r0, #0
	strh r0, [r4, #0x38]
_08016A06:
	subs r0, r2, #1
	mov r1, sb
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _08016A24
	ldr r0, [r4, #8]
	movs r2, #1
	orrs r0, r2
	b _08016A22
_08016A1C:
	ldr r0, [r4, #8]
	movs r3, #1
	orrs r0, r3
_08016A22:
	str r0, [r4, #8]
_08016A24:
	movs r0, #0x44
	add sb, r0
	add r8, r0
	ldr r1, [sp, #4]
	adds r1, #0x44
	str r1, [sp, #4]
	adds r4, #0x44
	movs r2, #1
	add sl, r2
	ldrb r3, [r7, #1]
	cmp sl, r3
	bge _08016A3E
	b _080168A6
_08016A3E:
	ldr r0, [sp]
	cmp r0, #0
	bne _08016A6A
	strb r0, [r7]
	movs r2, #0
	mov sl, r2
	ldrb r3, [r7, #1]
	cmp sl, r3
	bge _08016A66
	adds r4, r7, #0
	adds r4, #0x10
_08016A54:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x44
	movs r0, #1
	add sl, r0
	ldrb r1, [r7, #1]
	cmp sl, r1
	blt _08016A54
_08016A66:
	movs r0, #0
	strb r0, [r7, #1]
_08016A6A:
	movs r0, #0
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity08016ba4_Update
Entity08016ba4_Update: @ 0x08016A7C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r7, _08016AB0 @ =0x03000064
	movs r5, #0x24
	movs r4, #5
_08016A86:
	ldr r0, [r7]
	adds r1, r0, r5
	ldrb r0, [r1]
	cmp r0, #0
	beq _08016A96
	adds r0, r1, #0
	bl FUN_08016878
_08016A96:
	movs r0, #0x89
	lsls r0, r0, #2
	adds r5, r5, r0
	subs r4, #1
	cmp r4, #0
	bge _08016A86
	ldr r0, [r6, #0x18]
	adds r0, #1
	str r0, [r6, #0x18]
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08016AB0: .4byte 0x03000064

	thumb_func_start Entity08016ba4_Destroy
Entity08016ba4_Destroy: @ 0x08016AB4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r1, #0
_08016ABE:
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, #0x24
	mov r2, r8
	adds r5, r2, r0
	ldrb r0, [r5]
	adds r7, r1, #1
	cmp r0, #0
	beq _08016AF2
	movs r6, #0
	ldrb r0, [r5, #1]
	cmp r6, r0
	bge _08016AF2
	adds r4, r5, #0
	adds r4, #0x10
_08016AE2:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x44
	adds r6, #1
	ldrb r2, [r5, #1]
	cmp r6, r2
	blt _08016AE2
_08016AF2:
	adds r1, r7, #0
	cmp r1, #5
	ble _08016ABE
	movs r1, #0
	ldr r0, _08016B0C @ =0x03000064
	str r1, [r0]
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08016B0C: .4byte 0x03000064

	thumb_func_start Entity08016ba4_Init
Entity08016ba4_Init: @ 0x08016B10
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, _08016B94 @ =0x03000064
	str r7, [r0]
	ldr r0, _08016B98 @ =0x00001C1A
	bl GetParticleGroup
	str r0, [r7, #0x1c]
	ldr r0, _08016B9C @ =0x0000922E
	ldr r1, _08016BA0 @ =0x0000D1B8
	bl GetFile
	str r0, [r7, #0x20]
	movs r1, #0
	mov sb, r1
_08016B36:
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, #0x24
	adds r0, r7, r0
	mov r2, sb
	strb r2, [r0]
	adds r1, #1
	mov r8, r1
	adds r5, r0, #0
	adds r5, #0x38
	adds r4, r0, #0
	adds r4, #0x10
	movs r6, #7
_08016B56:
	ldr r1, [r7, #0x1c]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0822da70
	ldr r1, [r7, #0x20]
	mov r0, sb
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #3
	movs r3, #0
	bl FUN_08236fac
	adds r5, #0x44
	adds r4, #0x44
	subs r6, #1
	cmp r6, #0
	bge _08016B56
	mov r1, r8
	cmp r1, #5
	ble _08016B36
	movs r0, #0
	str r0, [r7, #0x18]
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08016B94: .4byte 0x03000064
_08016B98: .4byte 0x00001C1A
_08016B9C: .4byte 0x0000922E
_08016BA0: .4byte 0x0000D1B8

	thumb_func_start Entity08016ba4_Create
Entity08016ba4_Create: @ 0x08016BA4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08016BDC @ =0x03000064
	ldr r0, [r0]
	cmp r0, #0
	bne _08016BEE
	ldr r1, _08016BE0 @ =0x00000CFC
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08016BEC
	ldr r1, _08016BE4 @ =Entity08016ba4_Update
	ldr r2, _08016BE8 @ =Entity08016ba4_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity08016ba4_Init
	cmp r0, #0
	bge _08016BEC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08016BEE
	.align 2, 0
_08016BDC: .4byte 0x03000064
_08016BE0: .4byte 0x00000CFC
_08016BE4: .4byte Entity08016ba4_Update
_08016BE8: .4byte Entity08016ba4_Destroy
_08016BEC:
	adds r0, r4, #0
_08016BEE:
	pop {r4, r5}
	pop {r1}
	bx r1
