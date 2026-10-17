	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080592fc
FUN_080592fc: @ 0x080592FC
	bx lr
	.align 2, 0

	thumb_func_start FUN_08059300
FUN_08059300: @ 0x08059300
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x1c
	adds r5, r0, #0
	mov r8, r1
	mov sb, r2
	adds r6, r3, #0
	adds r4, r5, #0
	adds r4, #0xc0
	ldr r2, _08059380 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x30
	orrs r0, r3
	ldr r1, _08059384 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _08059388 @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	ldr r1, _0805938C @ =FUN_080592fc
	adds r0, r4, #0
	adds r2, r5, #0
	bl Hitbox_SetHandler
	movs r0, #0
	str r0, [sp]
	str r6, [sp, #4]
	adds r0, r4, #0
	mov r1, r8
	mov r2, sb
	movs r3, #0
	bl Hitbox_SetAttack
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08059380: .4byte 0xFFFF0000
_08059384: .4byte 0x0000FFFF
_08059388: .4byte 0x00002001
_0805938C: .4byte FUN_080592fc

	thumb_func_start FUN_08059390
FUN_08059390: @ 0x08059390
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r4, r0, #0
	adds r3, r1, #0
	ldrb r0, [r2, #2]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0805941A
	movs r0, #3
	movs r1, #0
	strb r0, [r2, #2]
	strh r1, [r2, #6]
	movs r0, #1
	strb r0, [r2]
	ldrh r1, [r3, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r3, #6]
	adds r4, #0x42
	mov sl, r4
	ldrb r1, [r4]
	subs r1, #0x40
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r7, r2, #0
	adds r7, #0x50
	movs r0, #5
	mov sb, r0
	str r0, [sp]
	movs r0, #0xc0
	lsls r0, r0, #6
	mov r8, r0
	str r0, [sp, #4]
	movs r6, #0x20
	str r6, [sp, #8]
	movs r4, #0xa
	str r4, [sp, #0xc]
	str r4, [sp, #0x10]
	movs r5, #0xf8
	str r5, [sp, #0x14]
	adds r0, r7, #0
	movs r2, #0x20
	movs r3, #2
	bl FUN_08015c28
	mov r0, sl
	ldrb r1, [r0]
	adds r1, #0x40
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r0, sb
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r4, [sp, #0xc]
	str r4, [sp, #0x10]
	str r5, [sp, #0x14]
	adds r0, r7, #0
	movs r2, #0x20
	movs r3, #2
	bl FUN_08015c28
_0805941A:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805942c
FUN_0805942c: @ 0x0805942C
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x70
	ldr r2, _080594A4 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x80
	orrs r0, r3
	ldr r1, _080594A8 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _080594AC @ =0x00004001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	adds r1, r5, #0
	adds r1, #0x50
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _080594B0 @ =FUN_08059390
	adds r0, r4, #0
	adds r2, r5, #0
	bl Hitbox_SetHandler
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Hitbox_SetPowerAndAttributes
	adds r0, r4, #0
	bl Hitbox_Register
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080594A4: .4byte 0xFFFF0000
_080594A8: .4byte 0x0000FFFF
_080594AC: .4byte 0x00004001
_080594B0: .4byte FUN_08059390

	thumb_func_start FUN_080594b4
FUN_080594b4: @ 0x080594B4
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	adds r6, r1, #0
	adds r4, r6, #0
	adds r4, #0x18
	ldr r1, _080594D4 @ =0x000061F9
	adds r0, r4, #0
	bl Video_GetAuxSprite
	cmp r0, #0
	bne _080594D8
	movs r0, #1
	rsbs r0, r0, #0
	b _08059540
	.align 2, 0
_080594D4: .4byte 0x000061F9
_080594D8:
	movs r1, #0x89
	lsls r1, r1, #2
	adds r0, r4, #0
	bl Video_SetAuxSpritePltt
	adds r0, r6, #0
	adds r0, #0x34
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Setup
	adds r0, r6, #0
	adds r0, #0x60
	ldr r1, [r7, #0x18]
	movs r4, #0
	str r4, [sp]
	movs r2, #7
	movs r3, #0
	bl AuxAnim_SetAnim
	adds r1, r6, #0
	adds r1, #0x3b
	movs r0, #2
	strb r0, [r1]
	adds r5, r6, #0
	adds r5, #0x50
	str r4, [sp, #4]
	add r0, sp, #4
	adds r1, r5, #0
	ldr r2, _08059548 @ =0x05000002
	bl CpuSet
	ldrh r1, [r7, #0x24]
	ldrh r2, [r7, #0x26]
	ldrh r3, [r7, #0x28]
	adds r0, r6, #0
	bl FUN_08059300
	adds r0, r6, #0
	bl FUN_0805942c
	movs r0, #0x88
	lsls r0, r0, #1
	adds r4, r6, r0
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl ParticleShadow_Init
	adds r0, r4, #0
	bl ParticleShadow_Hide
_08059540:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08059548: .4byte 0x05000002

	thumb_func_start FUN_0805954c
FUN_0805954c: @ 0x0805954C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r4, #1
	lsls r4, r2
	ldr r0, [r5, #0x1c]
	ands r0, r4
	cmp r0, #0
	beq _0805957A
	adds r0, r6, #0
	adds r0, #0x34
	bl AuxSprite_Remove
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r6, r1
	bl ParticleShadow_Hide
	ldr r0, [r5, #0x1c]
	bics r0, r4
	str r0, [r5, #0x1c]
	movs r0, #0
	b _0805957E
_0805957A:
	movs r0, #1
	rsbs r0, r0, #0
_0805957E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08059584
FUN_08059584: @ 0x08059584
	push {r4, lr}
	adds r4, r1, #0
	bl FUN_0805954c
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r4, r1
	bl ParticleShadow_Remove
	adds r4, #0x70
	adds r0, r4, #0
	bl Hitbox_Unregister
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080595a4
FUN_080595a4: @ 0x080595A4
	movs r0, #0
	bx lr

	thumb_func_start FUN_080595a8
FUN_080595a8: @ 0x080595A8
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	movs r0, #0x34
	adds r0, r0, r4
	mov ip, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _080595BE
	movs r0, #0
	strb r0, [r4]
_080595BE:
	ldrb r0, [r4, #1]
	adds r0, #4
	strb r0, [r4, #1]
	adds r5, r4, #0
	adds r5, #0x50
	ldrb r6, [r4, #1]
	ldr r2, _080595E8 @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #8
	adds r3, r5, #0
	cmp r0, #0
	blt _080595EC
	asrs r1, r0, #0xc
	b _080595F2
	.align 2, 0
_080595E8: .4byte gSineTable
_080595EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080595F2:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #1
	muls r0, r1, r0
	cmp r0, #0
	blt _0805960E
	asrs r0, r0, #0xc
	b _08059614
_0805960E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08059614:
	strh r0, [r5, #4]
	adds r1, r7, #0
	adds r1, #0x34
	ldrh r0, [r7, #0x34]
	mov r5, ip
	ldrh r5, [r5, #0x1c]
	adds r0, r0, r5
	mov r2, ip
	strh r0, [r2, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r5, [r3, #2]
	adds r0, r0, r5
	strh r0, [r3, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r3, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
	adds r0, r4, #0
	adds r0, #0x70
	adds r1, r3, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldrh r0, [r4, #6]
	cmp r0, #0x3f
	bls _08059654
	movs r0, #2
	strb r0, [r4, #2]
	movs r0, #0
	strh r0, [r4, #6]
	movs r0, #1
	strb r0, [r4]
_08059654:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805965c
FUN_0805965c: @ 0x0805965C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	mov r8, r0
	adds r6, r1, #0
	adds r7, r6, #0
	adds r7, #0x34
	ldrb r0, [r6]
	cmp r0, #0
	beq _080596E2
	movs r0, #0
	strb r0, [r6]
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	str r0, [r6, #8]
	str r1, [r6, #0xc]
	ldr r0, _0805970C @ =0x00000ABC
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r6, #0x10]
	str r1, [r6, #0x14]
	adds r5, r6, #0
	adds r5, #8
	adds r4, r6, #0
	adds r4, #0x10
	movs r1, #0x10
	ldrsh r0, [r6, r1]
	movs r2, #8
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r4, r3]
	movs r3, #4
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r6, #1]
	movs r0, #0x10
	ldrsh r2, [r6, r0]
	movs r1, #8
	ldrsh r0, [r6, r1]
	subs r2, r2, r0
	movs r3, #4
	ldrsh r1, [r4, r3]
	movs r4, #4
	ldrsh r0, [r5, r4]
	subs r1, r1, r0
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	strh r0, [r6, #4]
	adds r2, r6, #0
	adds r2, #0x70
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_080596E2:
	ldrh r1, [r6, #4]
	ldrh r0, [r6, #6]
	muls r0, r1, r0
	add r3, sp, #0x14
	ldrb r4, [r6, #1]
	asrs r5, r0, #6
	ldr r2, _08059710 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	mov ip, r2
	cmp r0, #0
	blt _08059714
	asrs r1, r0, #0xc
	b _0805971A
	.align 2, 0
_0805970C: .4byte 0x00000ABC
_08059710: .4byte gSineTable
_08059714:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805971A:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	add r0, ip
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _08059732
	asrs r0, r0, #0xc
	b _08059738
_08059732:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08059738:
	strh r0, [r3, #4]
	adds r2, r7, #0
	adds r2, #0x1c
	adds r3, r6, #0
	adds r3, #8
	add r1, sp, #0x14
	adds r0, r1, #0
	ldrh r0, [r0]
	ldrh r4, [r6, #8]
	adds r0, r0, r4
	strh r0, [r7, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r4, [r3, #2]
	adds r0, r0, r4
	strh r0, [r2, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	ldrh r0, [r6, #6]
	lsls r0, r0, #1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #9
	adds r5, r2, #0
	cmp r0, #0
	blt _0805977A
	asrs r1, r0, #0xc
	b _08059780
_0805977A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08059780:
	ldrh r0, [r6, #0xa]
	adds r1, r0, r1
	strh r1, [r7, #0x1e]
	ldrh r0, [r6, #6]
	cmp r0, #0x1f
	bls _080597A8
	lsls r1, r1, #0x10
	ldr r0, _080597FC @ =0x01FF0000
	cmp r1, r0
	bgt _080597A8
	adds r4, r6, #0
	adds r4, #0xc0
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
_080597A8:
	ldrh r0, [r6, #6]
	cmp r0, #0x3f
	bls _080597EC
	ldr r0, _08059800 @ =0x000003C3
	bl PlaySound_082406e0
	movs r0, #3
	movs r3, #0
	strb r0, [r6, #2]
	strh r3, [r6, #6]
	movs r0, #1
	strb r0, [r6]
	adds r2, r6, #0
	adds r2, #0x70
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	movs r2, #0x80
	lsls r2, r2, #1
	movs r0, #2
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	mov r4, r8
	ldrh r0, [r4, #0x2a]
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	str r5, [sp, #0x10]
	movs r0, #3
	movs r1, #0
	movs r3, #2
	bl FUN_08056774
_080597EC:
	movs r0, #0
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080597FC: .4byte 0x01FF0000
_08059800: .4byte 0x000003C3

	thumb_func_start FUN_08059804
FUN_08059804: @ 0x08059804
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08059818
	movs r0, #0
	strb r0, [r1]
	adds r0, r3, #0
	bl FUN_0805954c
_08059818:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity08059a1c_Update
Entity08059a1c_Update: @ 0x08059820
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r0, #0
	mov sl, r0
	adds r4, r7, #0
	adds r4, #0x3c
	mov r8, r0
	movs r1, #1
	mov sb, r1
_0805983A:
	mov r1, sb
	mov r2, r8
	lsls r1, r2
	ldr r0, [r7, #0x1c]
	ands r0, r1
	cmp r0, #0
	bne _0805984A
	b _08059956
_0805984A:
	ldr r1, _08059890 @ =0x085AB9DC
	ldrb r0, [r4, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	bl _call_via_r3
	adds r6, r4, #0
	adds r6, #0x34
	adds r3, r4, #0
	adds r3, #0x60
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r4, #0x60]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r3, #4]
	mov r2, sb
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	mov r1, sb
	ands r0, r1
	cmp r2, r0
	beq _08059894
	ldr r0, [r4, #0x34]
	movs r1, #4
	orrs r0, r1
	b _0805989C
	.align 2, 0
_08059890: .4byte 0x085AB9DC
_08059894:
	ldr r0, [r4, #0x34]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0805989C:
	str r0, [r4, #0x34]
	ldrb r0, [r3, #4]
	movs r1, #2
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	movs r2, #2
	ands r0, r2
	cmp r1, r0
	beq _080598C0
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _080598C8
_080598C0:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080598C8:
	str r0, [r6]
	ldrh r0, [r3, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0xe]
	ldr r5, _08059900 @ =0x0000FFFF
	adds r2, r5, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r5, [r3, #7]
	cmp r0, r5
	blo _08059938
	strh r1, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08059904
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _080598F8
	ldrb r0, [r3, #5]
_080598F8:
	subs r0, #1
	strh r0, [r3, #8]
	b _08059914
	.align 2, 0
_08059900: .4byte 0x0000FFFF
_08059904:
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _08059914
	strh r1, [r3, #8]
_08059914:
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r3, #6]
	ldrb r1, [r3, #6]
	ldrh r0, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r3, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08059938
	mov r5, sb
	strb r5, [r3, #7]
_08059938:
	adds r0, r4, #0
	adds r0, #0x70
	adds r1, r4, #0
	adds r1, #0x50
	movs r2, #0
	bl Hitbox_SetPos
	ldrb r0, [r4, #2]
	cmp r0, #1
	bne _08059950
	movs r0, #1
	add sl, r0
_08059950:
	ldrh r0, [r4, #6]
	adds r0, #1
	strh r0, [r4, #6]
_08059956:
	movs r1, #1
	add r8, r1
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r4, r4, r2
	mov r5, r8
	cmp r5, #7
	bgt _08059968
	b _0805983A
_08059968:
	mov r0, sl
	str r0, [r7, #0x2c]
	ldr r0, [r7, #0x20]
	adds r0, #1
	str r0, [r7, #0x20]
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity08059a1c_Destroy
Entity08059a1c_Destroy: @ 0x08059984
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x3c
	movs r4, #0
_0805998E:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08059584
	adds r4, #1
	movs r0, #0xa8
	lsls r0, r0, #1
	adds r5, r5, r0
	cmp r4, #7
	ble _0805998E
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start Entity08059a1c_Init
Entity08059a1c_Init: @ 0x080599AC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r6, r3, #0
	ldr r0, _08059A0C @ =0x0000922E
	ldr r1, _08059A10 @ =0x000031F4
	bl GetFile
	str r0, [r7, #0x18]
	strh r4, [r7, #0x24]
	strh r5, [r7, #0x26]
	strh r6, [r7, #0x28]
	mov r0, sp
	ldrh r0, [r0, #0x14]
	strh r0, [r7, #0x2a]
	adds r5, r7, #0
	adds r5, #0x3c
	movs r4, #0
_080599D2:
	adds r0, r7, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080594b4
	adds r4, #1
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r5, r5, r1
	cmp r4, #7
	ble _080599D2
	movs r1, #0xd0
	lsls r1, r1, #3
	strh r1, [r7, #0x34]
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r7, #0x36]
	movs r1, #0xf0
	lsls r1, r1, #3
	strh r1, [r7, #0x38]
	ldr r1, _08059A14 @ =0x03002BE0
	ldr r2, [r1]
	ldr r3, _08059A18 @ =0x00000ABC
	adds r1, r7, r3
	str r2, [r1]
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08059A0C: .4byte 0x0000922E
_08059A10: .4byte 0x000031F4
_08059A14: .4byte 0x03002BE0
_08059A18: .4byte 0x00000ABC

	thumb_func_start Entity08059a1c_Create
Entity08059a1c_Create: @ 0x08059A1C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	movs r1, #0xac
	lsls r1, r1, #4
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08059A68
	ldr r1, _08059A60 @ =Entity08059a1c_Update
	ldr r2, _08059A64 @ =Entity08059a1c_Destroy
	bl SetEntityRoutine
	str r5, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl Entity08059a1c_Init
	cmp r0, #0
	bge _08059A68
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08059A6A
	.align 2, 0
_08059A60: .4byte Entity08059a1c_Update
_08059A64: .4byte Entity08059a1c_Destroy
_08059A68:
	adds r0, r4, #0
_08059A6A:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08059a78
FUN_08059a78: @ 0x08059A78
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	cmp r0, #0
	bne _08059A8C
	movs r0, #1
	rsbs r0, r0, #0
	b _08059B6C
_08059A8C:
	adds r6, r0, #0
	movs r0, #0x3c
	adds r0, r0, r6
	mov ip, r0
	movs r7, #0
	movs r3, #1
	mov r8, r3
	movs r5, #0x34
	adds r5, r5, r6
	mov sl, r5
_08059AA0:
	mov r0, r8
	lsls r0, r7
	ldr r3, [r6, #0x1c]
	ands r3, r0
	cmp r3, #0
	bne _08059B5E
	mov r4, ip
	adds r4, #0x34
	mov r5, r8
	mov r0, ip
	strb r5, [r0, #2]
	strh r3, [r0, #6]
	strb r5, [r0]
	strb r1, [r0, #1]
	strb r2, [r0, #3]
	ldrh r1, [r6, #0x24]
	adds r0, #0xfc
	strh r1, [r0]
	mov r3, ip
	adds r3, #0x50
	mov r0, ip
	ldrb r5, [r0, #1]
	movs r1, #0x80
	lsls r1, r1, #1
	mov sb, r1
	ldr r2, _08059AF0 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #8
	cmp r0, #0
	blt _08059AF4
	asrs r1, r0, #0xc
	b _08059AFA
	.align 2, 0
_08059AF0: .4byte gSineTable
_08059AF4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08059AFA:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r5, sb
	muls r5, r0, r5
	adds r0, r5, #0
	cmp r0, #0
	blt _08059B16
	asrs r0, r0, #0xc
	b _08059B1C
_08059B16:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08059B1C:
	strh r0, [r3, #4]
	adds r1, r4, #0
	adds r1, #0x1c
	ldrh r0, [r6, #0x34]
	ldrh r2, [r4, #0x1c]
	adds r0, r0, r2
	strh r0, [r4, #0x1c]
	mov r3, sl
	ldrh r0, [r3, #2]
	ldrh r5, [r1, #2]
	adds r0, r0, r5
	strh r0, [r1, #2]
	ldrh r0, [r3, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	movs r0, #0x88
	lsls r0, r0, #1
	add r0, ip
	bl ParticleShadow_Show
	movs r0, #0x29
	strh r0, [r4, #0x10]
	adds r0, r4, #0
	movs r1, #0
	bl Video_AddAuxSpriteIntoDrawList
	mov r1, r8
	lsls r1, r7
	ldr r0, [r6, #0x1c]
	orrs r0, r1
	str r0, [r6, #0x1c]
	b _08059B6A
_08059B5E:
	adds r7, #1
	movs r3, #0xa8
	lsls r3, r3, #1
	add ip, r3
	cmp r7, #7
	ble _08059AA0
_08059B6A:
	movs r0, #0
_08059B6C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
