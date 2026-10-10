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
	ldr r2, _080595E8 @ =0x085B0A08
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
_080595E8: .4byte 0x085B0A08
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
	ldr r2, _08059710 @ =0x085B0A08
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
_08059710: .4byte 0x085B0A08
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

	thumb_func_start FUN_08059820
FUN_08059820: @ 0x08059820
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

	thumb_func_start FUN_08059984
FUN_08059984: @ 0x08059984
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

	thumb_func_start FUN_080599ac
FUN_080599ac: @ 0x080599AC
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

	thumb_func_start FUN_08059a1c
FUN_08059a1c: @ 0x08059A1C
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
	ldr r1, _08059A60 @ =FUN_08059820
	ldr r2, _08059A64 @ =FUN_08059984
	bl SetEntityRoutine
	str r5, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl FUN_080599ac
	cmp r0, #0
	bge _08059A68
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08059A6A
	.align 2, 0
_08059A60: .4byte FUN_08059820
_08059A64: .4byte FUN_08059984
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
	ldr r2, _08059AF0 @ =0x085B0A08
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
_08059AF0: .4byte 0x085B0A08
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

	thumb_func_start FUN_08059b7c
FUN_08059b7c: @ 0x08059B7C
	push {r4, r5, r6, lr}
	adds r4, r1, #0
	movs r2, #0
	movs r6, #1
	ldr r1, [r0, #0x18]
	adds r3, r0, #0
	adds r3, #0x20
	movs r5, #0x82
	lsls r5, r5, #1
_08059B8E:
	adds r0, r6, #0
	lsls r0, r2
	ands r0, r1
	cmp r0, #0
	bne _08059B9E
	str r2, [r4]
	adds r0, r3, #0
	b _08059BA8
_08059B9E:
	adds r3, r3, r5
	adds r2, #1
	cmp r2, #7
	ble _08059B8E
	movs r0, #0
_08059BA8:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08059bb0
FUN_08059bb0: @ 0x08059BB0
	push {lr}
	movs r0, #5
	movs r1, #0
	strb r0, [r2, #2]
	movs r0, #1
	strb r0, [r2, #1]
	strh r1, [r2, #8]
	movs r0, #0xb8
	lsls r0, r0, #1
	bl PlaySound_082406e0
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08059bcc
FUN_08059bcc: @ 0x08059BCC
	bx lr
	.align 2, 0

	thumb_func_start FUN_08059bd0
FUN_08059bd0: @ 0x08059BD0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	str r0, [sp, #0x20]
	mov sl, r1
	movs r1, #0
	movs r6, #0
	movs r0, #1
	mov r2, sl
	strb r0, [r2, #2]
	strb r0, [r2, #1]
	strh r6, [r2, #8]
	strb r1, [r2, #0xd]
	strb r1, [r2, #0xc]
	mov r4, sl
	adds r4, #0xbc
	mov r5, sl
	adds r5, #0xe8
	ldr r1, _08059CFC @ =0x00005292
	adds r0, r5, #0
	bl Video_GetAuxSprite
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #3
	bl AuxSprite_Add
	movs r0, #3
	strh r0, [r4, #0x10]
	movs r0, #2
	strb r0, [r4, #7]
	movs r0, #0xd8
	add r0, sl
	mov r8, r0
	str r6, [sp, #0xc]
	add r0, sp, #0xc
	mov r1, r8
	ldr r2, _08059D00 @ =0x05000002
	bl CpuSet
	mov r7, sl
	adds r7, #0x6c
	ldr r2, _08059D04 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r3, #0x40
	orrs r0, r3
	ldr r1, _08059D08 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x10]
	add r5, sp, #0x10
	ldr r0, [r5, #4]
	ands r0, r2
	orrs r0, r3
	str r0, [r5, #4]
	movs r0, #0xf0
	lsls r0, r0, #0xf
	str r0, [sp, #0x18]
	add r4, sp, #0x18
	ldr r0, [r4, #4]
	ands r0, r2
	str r0, [r4, #4]
	ldr r2, _08059D0C @ =0x00004005
	movs r0, #0x10
	mov sb, r0
	str r0, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _08059D10 @ =FUN_08059bb0
	adds r0, r7, #0
	mov r2, sl
	bl Hitbox_SetHandler
	ldr r2, [sp, #0x20]
	ldrh r1, [r2, #0x1e]
	adds r0, r7, #0
	movs r2, #0
	movs r3, #0
	bl Hitbox_SetPowerAndAttributes
	adds r0, r7, #0
	bl Hitbox_Register
	subs r7, #0x50
	movs r1, #0x20
	strh r1, [r5]
	movs r0, #0xf0
	strh r0, [r5, #2]
	strh r1, [r5, #4]
	strh r6, [r4]
	movs r0, #0x78
	strh r0, [r4, #2]
	strh r6, [r4, #4]
	ldr r2, _08059D14 @ =0x00002001
	mov r0, sb
	str r0, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _08059D18 @ =FUN_08059bcc
	adds r0, r7, #0
	mov r2, sl
	bl Hitbox_SetHandler
	ldr r2, [sp, #0x20]
	ldrh r1, [r2, #0x1c]
	movs r0, #0x80
	lsls r0, r0, #0xa
	str r0, [sp]
	movs r0, #5
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r2, #0x1e
	movs r3, #0
	bl Hitbox_SetAttack
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08059CFC: .4byte 0x00005292
_08059D00: .4byte 0x05000002
_08059D04: .4byte 0xFFFF0000
_08059D08: .4byte 0x0000FFFF
_08059D0C: .4byte 0x00004005
_08059D10: .4byte FUN_08059bb0
_08059D14: .4byte 0x00002001
_08059D18: .4byte FUN_08059bcc

	thumb_func_start FUN_08059d1c
FUN_08059d1c: @ 0x08059D1C
	push {r4, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	adds r0, #0x6c
	bl Hitbox_Unregister
	adds r4, #0xbc
	adds r0, r4, #0
	bl AuxSprite_Remove
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08059d38
FUN_08059d38: @ 0x08059D38
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	adds r5, #0xbc
	ldr r3, [r5]
	movs r4, #1
	orrs r3, r4
	str r3, [r5]
	adds r1, #0x6c
	ldrh r5, [r1, #6]
	movs r3, #4
	orrs r3, r5
	strh r3, [r1, #6]
	lsls r4, r2
	ldr r1, [r6, #0x18]
	bics r1, r4
	str r1, [r6, #0x18]
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08059d60
FUN_08059d60: @ 0x08059D60
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _08059D6E
	movs r0, #0
	strb r0, [r4, #1]
_08059D6E:
	ldrh r0, [r4, #8]
	ldrh r1, [r4, #0xa]
	cmp r0, r1
	blo _08059D86
	movs r0, #1
	movs r1, #0
	strb r0, [r4, #2]
	strb r0, [r4, #1]
	strh r1, [r4, #8]
	ldr r0, _08059D94 @ =0x0000016D
	bl PlaySound_082406e0
_08059D86:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08059D94: .4byte 0x0000016D

	thumb_func_start FUN_08059d98
FUN_08059d98: @ 0x08059D98
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r1, #0
	movs r0, #0xbc
	adds r0, r0, r4
	mov ip, r0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _08059DCC
	movs r0, #0
	strb r0, [r4, #1]
	mov r1, ip
	ldr r0, [r1]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
	str r0, [r2]
	movs r2, #1
	mov r3, ip
	strb r2, [r3, #9]
	ldr r0, [r3, #0x1c]
	ldr r1, [r3, #0x20]
	str r0, [r4, #0x10]
	str r1, [r4, #0x14]
	strb r2, [r4, #4]
_08059DCC:
	ldrh r1, [r4, #8]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	bne _08059DDE
	ldrb r0, [r4, #0xd]
	adds r0, #0x20
	strb r0, [r4, #0xd]
_08059DDE:
	ldrh r1, [r4, #8]
	lsls r2, r1, #3
	adds r0, r1, #0
	ands r0, r3
	lsls r0, r0, #7
	adds r3, r2, r0
	movs r0, #0x20
	subs r0, r0, r1
	mov r5, sp
	lsls r6, r0, #3
	ldr r2, _08059E10 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08059E14
	asrs r1, r0, #0xc
	b _08059E1A
	.align 2, 0
_08059E10: .4byte 0x085B0A08
_08059E14:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08059E1A:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _08059E36
	asrs r0, r0, #0xc
	b _08059E3C
_08059E36:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08059E3C:
	strh r0, [r5, #4]
	mov r3, ip
	adds r3, #0x1c
	mov r2, sp
	mov r1, sp
	ldrh r0, [r4, #0x10]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, ip
	strh r0, [r1, #0x1c]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #0x12]
	adds r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4, #0x14]
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r3, #4]
	ldrh r0, [r4, #8]
	cmp r0, #0
	beq _08059E6E
	lsls r0, r0, #1
	mov r2, ip
	strb r0, [r2, #9]
	b _08059E74
_08059E6E:
	movs r0, #1
	mov r3, ip
	strb r0, [r3, #9]
_08059E74:
	ldrh r0, [r4, #8]
	cmp r0, #0x1f
	bls _08059E8C
	movs r1, #0
	movs r0, #0x40
	mov r2, ip
	strb r0, [r2, #9]
	movs r0, #2
	strb r0, [r4, #2]
	movs r0, #1
	strb r0, [r4, #1]
	strh r1, [r4, #8]
_08059E8C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08059e9c
FUN_08059e9c: @ 0x08059E9C
	push {r4, r5, lr}
	adds r4, r1, #0
	adds r3, r4, #0
	adds r3, #0xbc
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _08059EC0
	movs r0, #0
	strb r0, [r4, #1]
	ldrb r0, [r4, #0xc]
	strb r0, [r4, #0xd]
	adds r2, r4, #0
	adds r2, #0x6c
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_08059EC0:
	ldrh r1, [r4, #8]
	cmp r1, #0x1f
	bhi _08059EFA
	movs r0, #7
	ands r0, r1
	cmp r0, #3
	bhi _08059ED2
	movs r0, #1
	b _08059ED4
_08059ED2:
	movs r0, #0
_08059ED4:
	strb r0, [r4, #4]
	ldrb r0, [r4]
	cmp r0, #1
	bhi _08059EFA
	ldr r2, [r4, #0x18]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r5, #0x1c
	ldrsh r1, [r3, r5]
	subs r0, r0, r1
	movs r5, #4
	ldrsh r1, [r2, r5]
	movs r5, #0x20
	ldrsh r2, [r3, r5]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r4, #0xc]
	strb r0, [r4, #0xd]
_08059EFA:
	ldrh r0, [r4, #8]
	cmp r0, #0x3f
	bls _08059F0E
	movs r0, #0
	strb r0, [r4, #4]
	movs r1, #3
	strb r1, [r4, #2]
	movs r1, #1
	strb r1, [r4, #1]
	strh r0, [r4, #8]
_08059F0E:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08059f1c
FUN_08059f1c: @ 0x08059F1C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r1, #0
	movs r0, #0xbc
	adds r0, r0, r7
	mov r8, r0
	ldrb r0, [r7, #1]
	cmp r0, #0
	beq _08059F52
	movs r0, #0
	strb r0, [r7, #1]
	ldrb r0, [r7, #0xc]
	strb r0, [r7, #0xd]
	movs r0, #0x28
	strh r0, [r7, #0xe]
	adds r2, r7, #0
	adds r2, #0x6c
	subs r0, #0x2d
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
	movs r0, #0xb5
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08059F52:
	mov r3, sp
	ldrb r4, [r7, #0xc]
	ldrh r5, [r7, #0xe]
	ldr r2, _08059F74 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08059F78
	asrs r1, r0, #0xc
	b _08059F7E
	.align 2, 0
_08059F74: .4byte 0x085B0A08
_08059F78:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08059F7E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _08059F96
	asrs r0, r0, #0xc
	b _08059F9C
_08059F96:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08059F9C:
	strh r0, [r3, #4]
	mov r5, r8
	adds r5, #0x1c
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	mov r3, r8
	ldrh r3, [r3, #0x1c]
	adds r0, r0, r3
	mov r2, r8
	strh r0, [r2, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r3, [r5, #2]
	adds r0, r0, r3
	strh r0, [r5, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r5, #4]
	adds r0, r0, r1
	strh r0, [r5, #4]
	adds r4, r7, #0
	adds r4, #0x1c
	adds r6, r7, #0
	adds r6, #0xd8
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	adds r0, r7, #0
	adds r0, #0x6c
	adds r1, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	mov r2, r8
	movs r3, #0x1e
	ldrsh r6, [r2, r3]
	adds r4, r5, #0
	ldrh r0, [r2, #0x1c]
	lsls r0, r0, #0x10
	asrs r5, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r5, #0
	blt _0805A012
	cmp r1, #0
	blt _0805A012
	ldr r0, _0805A018 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _0805A012
	ldr r0, _0805A01C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0805A020
_0805A012:
	movs r5, #0
	b _0805A02E
	.align 2, 0
_0805A018: .4byte 0x030046A8
_0805A01C: .4byte 0x030046AC
_0805A020:
	ldr r0, _0805A040 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r5
_0805A02E:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0805A044
	adds r0, #4
	b _0805A050
	.align 2, 0
_0805A040: .4byte 0x030046A4
_0805A044:
	ldr r0, _0805A064 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0805A050:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0805A068
	cmp r2, #2
	beq _0805A06C
	b _0805A070
	.align 2, 0
_0805A064: .4byte 0x030046A4
_0805A068:
	ldrb r0, [r4, #4]
	b _0805A06E
_0805A06C:
	ldrb r0, [r4]
_0805A06E:
	subs r1, r1, r0
_0805A070:
	cmp r6, r1
	bhi _0805A078
	movs r0, #5
	b _0805A080
_0805A078:
	ldrh r0, [r7, #8]
	cmp r0, #0x7f
	bls _0805A08C
	movs r0, #4
_0805A080:
	movs r1, #0
	strb r0, [r7, #2]
	movs r0, #1
	strb r0, [r7, #1]
	strh r1, [r7, #8]
	b _0805A090
_0805A08C:
	adds r0, #1
	strh r0, [r7, #8]
_0805A090:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805a09c
FUN_0805a09c: @ 0x0805A09C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0805A0BE
	movs r0, #0
	strb r0, [r4, #1]
	adds r3, r4, #0
	adds r3, #0x6c
	ldrh r1, [r3, #6]
	movs r0, #4
	movs r2, #0
	orrs r0, r1
	strh r0, [r3, #6]
	strb r2, [r4, #4]
_0805A0BE:
	ldrh r0, [r4, #8]
	cmp r0, #0x1f
	bls _0805A0D0
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl FUN_08059d38
	b _0805A0D4
_0805A0D0:
	adds r0, #1
	strh r0, [r4, #8]
_0805A0D4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805a0dc
FUN_0805a0dc: @ 0x0805A0DC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	mov r8, r0
	adds r4, r1, #0
	mov sb, r2
	movs r0, #0xbc
	adds r0, r0, r4
	mov ip, r0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0805A120
	movs r0, #0
	strb r0, [r4, #1]
	movs r3, #0
	movs r0, #0xa
	strh r0, [r4, #0xe]
	ldrb r0, [r4, #0xc]
	adds r0, #0x80
	strb r0, [r4, #0xc]
	mov r2, ip
	ldr r0, [r2, #0x1c]
	ldr r1, [r2, #0x20]
	str r0, [r4, #0x10]
	str r1, [r4, #0x14]
	adds r2, r4, #0
	adds r2, #0x6c
	ldrh r0, [r2, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2, #6]
	strb r3, [r4, #4]
_0805A120:
	mov r3, sp
	ldrb r5, [r4, #0xc]
	ldrh r6, [r4, #0xe]
	ldr r2, _0805A144 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	adds r7, r2, #0
	cmp r0, #0
	blt _0805A148
	asrs r1, r0, #0xc
	b _0805A14E
	.align 2, 0
_0805A144: .4byte 0x085B0A08
_0805A148:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805A14E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r7
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805A166
	asrs r0, r0, #0xc
	b _0805A16C
_0805A166:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805A16C:
	strh r0, [r3, #4]
	mov r1, ip
	adds r1, #0x1c
	mov r2, sp
	mov r0, sp
	ldrh r0, [r0]
	mov r3, ip
	ldrh r3, [r3, #0x1c]
	adds r0, r0, r3
	mov r5, ip
	strh r0, [r5, #0x1c]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r5, [r1, #4]
	adds r0, r0, r5
	strh r0, [r1, #4]
	ldrh r0, [r4, #8]
	lsls r0, r0, #2
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #8
	cmp r0, #0
	blt _0805A1AC
	asrs r2, r0, #0xc
	b _0805A1B2
_0805A1AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0805A1B2:
	ldrh r0, [r4, #0x12]
	adds r0, r0, r2
	mov r2, ip
	strh r0, [r2, #0x1e]
	ldrb r0, [r4, #0xd]
	adds r0, #0x10
	strb r0, [r4, #0xd]
	ldrh r1, [r4, #8]
	cmp r1, #0xf
	bhi _0805A1E6
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0805A1D8
	mov r3, ip
	ldr r0, [r3]
	orrs r0, r2
	b _0805A206
_0805A1D8:
	mov r5, ip
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	b _0805A208
_0805A1E6:
	movs r0, #3
	ands r0, r1
	cmp r0, #1
	bhi _0805A1FC
	mov r1, ip
	ldr r0, [r1]
	movs r1, #1
	orrs r0, r1
	mov r2, ip
	str r0, [r2]
	b _0805A208
_0805A1FC:
	mov r3, ip
	ldr r0, [r3]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
_0805A206:
	str r0, [r3]
_0805A208:
	ldrh r0, [r4, #8]
	cmp r0, #0x1f
	bls _0805A21A
	mov r0, r8
	adds r1, r4, #0
	mov r2, sb
	bl FUN_08059d38
	b _0805A21E
_0805A21A:
	adds r0, #1
	strh r0, [r4, #8]
_0805A21E:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805a22c
FUN_0805a22c: @ 0x0805A22C
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r7, #0
	adds r4, #0x20
	movs r6, #0
_0805A236:
	movs r0, #1
	lsls r0, r6
	ldr r1, [r7, #0x18]
	ands r1, r0
	adds r5, r4, #0
	adds r5, #0xe8
	cmp r1, #0
	beq _0805A2AC
	ldr r1, _0805A280 @ =0x085AB9EC
	ldrb r0, [r4, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl _call_via_r3
	adds r1, r4, #0
	adds r1, #0xbc
	ldrb r0, [r4, #0xd]
	adds r0, #0x60
	rsbs r0, r0, #0
	strb r0, [r1, #6]
	ldrb r1, [r4, #4]
	ldrb r0, [r4, #3]
	cmp r0, r1
	beq _0805A2AC
	strb r1, [r4, #3]
	ldrb r0, [r4, #3]
	cmp r0, #1
	beq _0805A298
	cmp r0, #1
	bgt _0805A284
	cmp r0, #0
	beq _0805A28A
	b _0805A2AC
	.align 2, 0
_0805A280: .4byte 0x085AB9EC
_0805A284:
	cmp r0, #2
	beq _0805A2A4
	b _0805A2AC
_0805A28A:
	adds r0, r5, #0
	ldr r1, _0805A294 @ =0x0000012D
	bl Video_SetAuxSpritePltt
	b _0805A2AC
	.align 2, 0
_0805A294: .4byte 0x0000012D
_0805A298:
	adds r0, r5, #0
	movs r1, #0x98
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	b _0805A2AC
_0805A2A4:
	adds r0, r5, #0
	ldr r1, _0805A2C0 @ =0x00000131
	bl Video_SetAuxSpritePltt
_0805A2AC:
	adds r6, #1
	movs r0, #0x82
	lsls r0, r0, #1
	adds r4, r4, r0
	cmp r6, #7
	ble _0805A236
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805A2C0: .4byte 0x00000131

	thumb_func_start FUN_0805a2c4
FUN_0805a2c4: @ 0x0805A2C4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x20
	movs r4, #0
_0805A2CE:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08059d1c
	adds r4, #1
	movs r0, #0x82
	lsls r0, r0, #1
	adds r5, r5, r0
	cmp r4, #7
	ble _0805A2CE
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805a2ec
FUN_0805a2ec: @ 0x0805A2EC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	strh r1, [r6, #0x1c]
	movs r0, #0xa
	strh r0, [r6, #0x1e]
	adds r5, r6, #0
	adds r5, #0x20
	movs r4, #0
_0805A2FC:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08059bd0
	adds r4, #1
	movs r0, #0x82
	lsls r0, r0, #1
	adds r5, r5, r0
	cmp r4, #7
	ble _0805A2FC
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805a31c
FUN_0805a31c: @ 0x0805A31C
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0x84
	lsls r1, r1, #4
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805A358
	ldr r1, _0805A350 @ =FUN_0805a22c
	ldr r2, _0805A354 @ =FUN_0805a2c4
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0805a2ec
	cmp r0, #0
	bge _0805A358
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805A35A
	.align 2, 0
_0805A350: .4byte FUN_0805a22c
_0805A354: .4byte FUN_0805a2c4
_0805A358:
	adds r0, r4, #0
_0805A35A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805a360
FUN_0805a360: @ 0x0805A360
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	mov sb, r0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r4, r3, #0
	mov r1, sp
	bl FUN_08059b7c
	adds r7, r0, #0
	cmp r7, #0
	bne _0805A384
	movs r0, #1
	rsbs r0, r0, #0
	b _0805A42E
_0805A384:
	str r4, [r7, #0x18]
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r2, #0
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r4, r3]
	movs r3, #4
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r3, r0, #0
	adds r2, r7, #0
	adds r2, #0xbc
	movs r1, #0
	strb r6, [r7]
	ldrb r0, [r7]
	cmp r0, #1
	beq _0805A3BE
	cmp r0, #1
	bgt _0805A3B8
	cmp r0, #0
	beq _0805A3C2
	b _0805A3CA
_0805A3B8:
	cmp r0, #2
	beq _0805A3C2
	b _0805A3CA
_0805A3BE:
	strb r1, [r7, #2]
	b _0805A3C6
_0805A3C2:
	strb r1, [r7, #2]
	movs r0, #1
_0805A3C6:
	strb r0, [r7, #1]
	strh r1, [r7, #8]
_0805A3CA:
	strb r3, [r7, #0xc]
	strb r3, [r7, #0xd]
	movs r0, #0
	mov r8, r0
	ldr r0, [sp, #0x20]
	strh r0, [r7, #0xe]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldrb r0, [r7, #0xd]
	adds r0, #0x60
	rsbs r0, r0, #0
	strb r0, [r2, #6]
	ldr r0, [r2]
	movs r5, #1
	orrs r0, r5
	str r0, [r2]
	strb r5, [r2, #9]
	adds r0, r7, #0
	adds r0, #0x1c
	adds r6, r7, #0
	adds r6, #0xd8
	adds r1, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r4, r7, #0
	adds r4, #0x6c
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldrh r0, [r4, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r4, #6]
	mov r1, r8
	strb r1, [r7, #3]
	strb r1, [r7, #4]
	ldr r0, [sp, #0x24]
	strh r0, [r7, #0xa]
	ldr r0, [sp]
	lsls r5, r0
	mov r2, sb
	ldr r0, [r2, #0x18]
	orrs r0, r5
	str r0, [r2, #0x18]
	movs r0, #0
_0805A42E:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805a43c
FUN_0805a43c: @ 0x0805A43C
	push {r4, r5, r6, lr}
	adds r4, r1, #0
	movs r2, #0
	movs r6, #1
	ldr r1, [r0, #0x18]
	adds r3, r0, #0
	adds r3, #0x24
	movs r5, #0xe2
	lsls r5, r5, #1
_0805A44E:
	adds r0, r6, #0
	lsls r0, r2
	ands r0, r1
	cmp r0, #0
	bne _0805A45E
	str r2, [r4]
	adds r0, r3, #0
	b _0805A468
_0805A45E:
	adds r3, r3, r5
	adds r2, #1
	cmp r2, #7
	ble _0805A44E
	movs r0, #0
_0805A468:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805a470
FUN_0805a470: @ 0x0805A470
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r2, #0
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r5, #6]
	ands r0, r1
	cmp r0, #0
	beq _0805A48E
	adds r0, r5, #0
	adds r0, #0x42
	ldrb r0, [r0]
	b _0805A4A6
_0805A48E:
	movs r1, #0x24
	ldrsh r0, [r6, r1]
	movs r2, #0x24
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	movs r3, #0x28
	ldrsh r1, [r6, r3]
	movs r3, #0x28
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl ArcTan2_8
_0805A4A6:
	strb r0, [r4, #0xa]
	adds r0, r5, #0
	adds r1, r6, #0
	bl Hitbox_ApplyDamage
	ldr r3, _0805A508 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r2, #0x10
	orrs r0, r2
	ldr r1, _0805A50C @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0xc]
	ldrh r1, [r6, #0x3e]
	adds r3, r4, #0
	adds r3, #0x14
	add r0, sp, #8
	str r0, [sp]
	movs r7, #1
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r2, #0
	bl FUN_0805fe7c
	ldrh r0, [r5, #0x3e]
	adds r0, #2
	movs r2, #0
	strh r0, [r5, #0x3e]
	ldrh r0, [r4, #0x12]
	ldrh r1, [r6, #0x3e]
	subs r0, r0, r1
	strh r0, [r4, #0x12]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _0805A514
	strh r2, [r4, #0x12]
	movs r0, #6
	strb r0, [r4, #1]
	strb r7, [r4]
	strh r2, [r4, #6]
	ldr r0, _0805A510 @ =0x00000339
	bl PlaySound_082406e0
	b _0805A524
	.align 2, 0
_0805A508: .4byte 0xFFFF0000
_0805A50C: .4byte 0x0000FFFF
_0805A510: .4byte 0x00000339
_0805A514:
	movs r0, #5
	strb r0, [r4, #1]
	strb r7, [r4]
	strh r2, [r4, #6]
	movs r0, #0xcd
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0805A524:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805a52c
FUN_0805a52c: @ 0x0805A52C
	movs r0, #4
	movs r1, #0
	strb r0, [r2, #1]
	movs r0, #1
	strb r0, [r2]
	strh r1, [r2, #6]
	bx lr
	.align 2, 0

	thumb_func_start FUN_0805a53c
FUN_0805a53c: @ 0x0805A53C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	str r0, [sp, #0x20]
	adds r7, r1, #0
	movs r1, #0
	movs r2, #0
	strb r1, [r7, #1]
	movs r0, #1
	strb r0, [r7]
	strh r2, [r7, #6]
	strb r1, [r7, #0xa]
	strb r1, [r7, #0xb]
	movs r0, #0xd4
	lsls r0, r0, #1
	adds r4, r7, r0
	ldr r1, _0805A5A8 @ =0x00003668
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r4, #0
	movs r1, #0xc8
	bl Video_SetAuxSpritePltt
	adds r4, r7, #0
	adds r4, #0xf8
	movs r5, #0
	add r1, sp, #0x10
	mov sb, r1
	add r2, sp, #0x18
	mov sl, r2
_0805A580:
	adds r0, r4, #0
	movs r2, #0xd4
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r2, #1
	bl AuxSprite_Add
	cmp r5, #0
	bne _0805A5AC
	ldr r0, [sp, #0x20]
	ldr r1, [r0, #0x20]
	str r5, [sp]
	adds r0, r7, #0
	adds r0, #0xe8
	movs r2, #1
	movs r3, #0
	bl AuxAnim_SetAnim
	movs r0, #1
	b _0805A5B2
	.align 2, 0
_0805A5A8: .4byte 0x00003668
_0805A5AC:
	adds r0, r5, #3
	strh r0, [r4, #0x10]
	movs r0, #2
_0805A5B2:
	strb r0, [r4, #7]
	adds r1, r4, #0
	adds r1, #0x1c
	movs r2, #0
	mov r8, r2
	str r2, [sp, #0xc]
	add r0, sp, #0xc
	ldr r2, _0805A6A8 @ =0x05000002
	bl CpuSet
	adds r5, #1
	adds r4, #0x2c
	cmp r5, #3
	ble _0805A580
	adds r6, r7, #0
	adds r6, #0x98
	ldr r2, _0805A6AC @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r4, #0x20
	orrs r0, r4
	ldr r1, _0805A6B0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x10]
	mov r1, sb
	ldr r0, [r1, #4]
	ands r0, r2
	orrs r0, r4
	str r0, [r1, #4]
	mov r0, r8
	str r0, [sp, #0x18]
	mov r1, sl
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _0805A6B4 @ =0x00005005
	movs r5, #0x10
	str r5, [sp]
	mov r0, sb
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	adds r1, r7, #0
	adds r1, #0x14
	str r1, [sp, #0x24]
	adds r0, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _0805A6B8 @ =FUN_0805a470
	adds r0, r6, #0
	adds r2, r7, #0
	bl Hitbox_SetHandler
	ldr r2, [sp, #0x20]
	ldrh r1, [r2, #0x1e]
	ldr r2, _0805A6BC @ =0x00000202
	adds r0, r6, #0
	movs r3, #1
	bl Hitbox_SetPowerAndAttributes
	adds r0, r6, #0
	bl Hitbox_Register
	subs r6, #0x50
	add r0, sp, #0x10
	strh r4, [r0]
	movs r0, #0x64
	mov r1, sb
	strh r0, [r1, #2]
	strh r4, [r1, #4]
	add r0, sp, #0x18
	mov r2, r8
	strh r2, [r0]
	mov r0, sl
	strh r2, [r0, #2]
	strh r2, [r0, #4]
	ldr r2, _0805A6C0 @ =0x00002001
	str r5, [sp]
	str r1, [sp, #4]
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r6, #0
	ldr r1, [sp, #0x24]
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _0805A6C4 @ =FUN_0805a52c
	adds r0, r6, #0
	adds r2, r7, #0
	bl Hitbox_SetHandler
	ldr r2, [sp, #0x20]
	ldrh r1, [r2, #0x1c]
	movs r0, #2
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	adds r0, r6, #0
	movs r2, #0x1e
	movs r3, #0
	bl Hitbox_SetAttack
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805A6A8: .4byte 0x05000002
_0805A6AC: .4byte 0xFFFF0000
_0805A6B0: .4byte 0x0000FFFF
_0805A6B4: .4byte 0x00005005
_0805A6B8: .4byte FUN_0805a470
_0805A6BC: .4byte 0x00000202
_0805A6C0: .4byte 0x00002001
_0805A6C4: .4byte FUN_0805a52c

	thumb_func_start FUN_0805a6c8
FUN_0805a6c8: @ 0x0805A6C8
	push {r4, r5, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	adds r0, #0x98
	bl Hitbox_Unregister
	adds r4, #0xf8
	movs r5, #3
_0805A6D8:
	adds r0, r4, #0
	bl AuxSprite_Remove
	subs r5, #1
	adds r4, #0x2c
	cmp r5, #0
	bge _0805A6D8
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805a6ec
FUN_0805a6ec: @ 0x0805A6EC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r7, r2, #0
	adds r2, r4, #0
	adds r2, #0xf8
	movs r5, #1
	movs r3, #3
_0805A6FC:
	ldr r1, [r2]
	orrs r1, r5
	str r1, [r2]
	subs r3, #1
	adds r2, #0x2c
	cmp r3, #0
	bge _0805A6FC
	adds r3, r4, #0
	adds r3, #0x98
	ldrh r2, [r3, #6]
	movs r1, #4
	orrs r1, r2
	strh r1, [r3, #6]
	movs r2, #1
	lsls r2, r7
	ldr r1, [r6, #0x18]
	bics r1, r2
	str r1, [r6, #0x18]
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805a728
FUN_0805a728: @ 0x0805A728
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0xf8
	movs r0, #0x8a
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r0, [r6, #0x14]
	ldr r1, [r6, #0x18]
	str r0, [r2]
	str r1, [r2, #4]
	adds r4, r6, #0
	adds r4, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0805A76E
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0805A776
_0805A76E:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0805A776:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0805A79A
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0805A7A2
_0805A79A:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0805A7A2:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0805A7DC @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0805A822
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0805A7E6
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0805A7E0
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _0805A7FC
	.align 2, 0
_0805A7DC: .4byte 0x0000FFFF
_0805A7E0:
	subs r0, #1
	strh r0, [r4, #8]
	b _0805A7FA
_0805A7E6:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0805A7FA
	strh r1, [r4, #8]
	movs r2, #1
	b _0805A7FC
_0805A7FA:
	movs r2, #0
_0805A7FC:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
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
	bne _0805A824
	movs r0, #1
	strb r0, [r4, #7]
	b _0805A824
_0805A822:
	movs r2, #0
_0805A824:
	strb r2, [r6, #4]
	ldr r0, _0805A83C @ =0x085B0A08
	ldrb r1, [r6, #5]
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #6
	cmp r0, #0
	blt _0805A840
	asrs r1, r0, #0xc
	b _0805A846
	.align 2, 0
_0805A83C: .4byte 0x085B0A08
_0805A840:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805A846:
	ldrh r0, [r5, #0x1e]
	adds r0, r0, r1
	strh r0, [r5, #0x1e]
	adds r5, #0x2c
	ldrb r0, [r6, #0xc]
	subs r2, r0, #1
	cmp r2, #0
	bge _0805A858
	movs r2, #3
_0805A858:
	movs r3, #2
_0805A85A:
	lsls r0, r2, #3
	adds r0, r0, r6
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	subs r2, #1
	cmp r2, #0
	bge _0805A86E
	movs r2, #3
_0805A86E:
	subs r3, #1
	adds r5, #0x2c
	cmp r3, #0
	bge _0805A85A
	ldrb r0, [r6, #5]
	adds r0, #4
	strb r0, [r6, #5]
	ldrh r0, [r6, #6]
	movs r3, #3
	ands r3, r0
	cmp r3, #0
	bne _0805A8AA
	ldrb r2, [r6, #0xc]
	lsls r2, r2, #3
	adds r2, r2, r6
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldrb r0, [r6, #0xc]
	adds r0, #1
	strb r0, [r6, #0xc]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _0805A8AA
	strb r3, [r6, #0xc]
_0805A8AA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805a8b0
FUN_0805a8b0: @ 0x0805A8B0
	push {lr}
	movs r2, #0x92
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r3, #2
	rsbs r3, r3, #0
	movs r2, #2
_0805A8BE:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	subs r2, #1
	adds r1, #0x2c
	cmp r2, #0
	bge _0805A8BE
	pop {r0}
	bx r0

	thumb_func_start FUN_0805a8d0
FUN_0805a8d0: @ 0x0805A8D0
	push {lr}
	movs r2, #0x92
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r3, #1
	movs r2, #2
_0805A8DC:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	subs r2, #1
	adds r1, #0x2c
	cmp r2, #0
	bge _0805A8DC
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805a8f0
FUN_0805a8f0: @ 0x0805A8F0
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, [r4, #0x44]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #0x14
	ldrsh r1, [r4, r3]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r3, #0x18
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r4, #0xb]
	ldrb r1, [r4, #0xa]
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	asrs r2, r0, #0x18
	movs r0, #2
	rsbs r0, r0, #0
	cmp r2, r0
	bge _0805A926
	movs r1, #0xfe
	b _0805A92C
_0805A926:
	cmp r2, #2
	ble _0805A92C
	movs r1, #2
_0805A92C:
	ldrb r0, [r4, #0xa]
	adds r0, r0, r1
	strb r0, [r4, #0xa]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805a938
FUN_0805a938: @ 0x0805A938
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805A95A
	movs r2, #0
	strb r2, [r4]
	adds r0, r4, #0
	adds r0, #0xe8
	ldr r1, [r5, #0x20]
	str r2, [sp]
	movs r2, #1
	movs r3, #0
	bl AuxAnim_SetAnim
_0805A95A:
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _0805A978
	movs r0, #1
	movs r2, #0
	strb r0, [r4, #1]
	strb r0, [r4]
	strh r2, [r4, #6]
	adds r0, r4, #0
	adds r0, #0xe8
	ldr r1, [r5, #0x20]
	str r2, [sp]
	movs r3, #0
	bl AuxAnim_SetAnim
_0805A978:
	ldrh r0, [r4, #6]
	adds r0, #1
	strh r0, [r4, #6]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805a988
FUN_0805a988: @ 0x0805A988
	push {r4, r5, lr}
	sub sp, #4
	adds r3, r0, #0
	adds r5, r1, #0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0805A9C8
	movs r2, #0
	strb r2, [r5]
	adds r4, r5, #0
	adds r4, #0x98
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r4, #6]
	ands r0, r1
	strh r0, [r4, #6]
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, [r3, #0x20]
	str r2, [sp]
	movs r3, #0
	bl AuxAnim_SetAnim
	adds r0, r5, #0
	bl FUN_0805a8b0
	adds r1, r5, #0
	adds r1, #0x14
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
_0805A9C8:
	ldrh r0, [r5, #6]
	cmp r0, #0x1f
	bls _0805A9DA
	movs r0, #2
	movs r1, #0
	strb r0, [r5, #1]
	movs r0, #1
	strb r0, [r5]
	strh r1, [r5, #6]
_0805A9DA:
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805a9e8
FUN_0805a9e8: @ 0x0805A9E8
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r1, #0
	ldrb r0, [r6]
	cmp r0, #0
	beq _0805AA42
	movs r0, #0
	strb r0, [r6]
	movs r0, #0xa
	strh r0, [r6, #0x10]
	adds r2, r6, #0
	adds r2, #0x98
	subs r0, #0xf
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
	ldr r2, [r6, #0x44]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #0x14
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r3, #0x18
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	ldr r3, _0805AA6C @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r2, _0805AA70 @ =0x000003FF
	ands r1, r2
	str r1, [r3]
	lsls r1, r1, #1
	ldr r2, _0805AA74 @ =0x0203B400
	adds r1, r1, r2
	ldrh r1, [r1]
	movs r2, #0x3f
	ands r1, r2
	subs r1, #0x80
	adds r0, r0, r1
	subs r0, #0x20
	strb r0, [r6, #0xa]
_0805AA42:
	adds r0, r6, #0
	bl FUN_0805a8f0
	mov r3, sp
	ldrb r4, [r6, #0xa]
	ldrh r5, [r6, #0x10]
	ldr r2, _0805AA78 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0805AA7C
	asrs r1, r0, #0xc
	b _0805AA82
	.align 2, 0
_0805AA6C: .4byte 0x030046B8
_0805AA70: .4byte 0x000003FF
_0805AA74: .4byte 0x0203B400
_0805AA78: .4byte 0x085B0A08
_0805AA7C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805AA82:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _0805AA9C @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0805AAA0
	asrs r0, r0, #0xc
	b _0805AAA6
	.align 2, 0
_0805AA9C: .4byte 0x085B0A08
_0805AAA0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805AAA6:
	strh r0, [r3, #4]
	adds r4, r6, #0
	adds r4, #0x14
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r6, #0x14]
	adds r0, r0, r3
	strh r0, [r6, #0x14]
	ldrh r0, [r1, #2]
	ldrh r2, [r4, #2]
	adds r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r4, #4]
	adds r0, r0, r3
	strh r0, [r4, #4]
	adds r5, r6, #0
	adds r5, #0x48
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r6, #0
	adds r0, #0x98
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r5, #0
	bl Hitbox_Register
	ldrh r0, [r6, #8]
	adds r0, #1
	strh r0, [r6, #8]
	lsls r0, r0, #0x10
	ldr r1, _0805AB04 @ =0x02570000
	cmp r0, r1
	bls _0805AB08
	movs r0, #3
	strb r0, [r6, #1]
	movs r0, #1
	strb r0, [r6]
	movs r0, #0
	b _0805AB0C
	.align 2, 0
_0805AB04: .4byte 0x02570000
_0805AB08:
	ldrh r0, [r6, #6]
	adds r0, #1
_0805AB0C:
	strh r0, [r6, #6]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805ab18
FUN_0805ab18: @ 0x0805AB18
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r5, r1, #0
	adds r7, r2, #0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0805AB4E
	movs r4, #0
	strb r4, [r5]
	adds r2, r5, #0
	adds r2, #0x98
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	adds r0, r5, #0
	bl FUN_0805a8d0
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, [r6, #0x20]
	str r4, [sp]
	movs r2, #4
	movs r3, #0
	bl AuxAnim_SetAnim
_0805AB4E:
	ldrb r0, [r5, #4]
	cmp r0, #0
	beq _0805AB60
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r7, #0
	bl FUN_0805a6ec
	b _0805AB66
_0805AB60:
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_0805AB66:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805ab70
FUN_0805ab70: @ 0x0805AB70
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	str r0, [sp, #0x20]
	adds r7, r1, #0
	str r2, [sp, #0x24]
	ldrb r0, [r7]
	cmp r0, #0
	bne _0805AB8A
	b _0805ACCA
_0805AB8A:
	movs r4, #0
	strb r4, [r7]
	adds r2, r7, #0
	adds r2, #0x98
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	adds r0, r7, #0
	bl FUN_0805a8d0
	adds r0, r7, #0
	adds r0, #0xe8
	ldr r2, [sp, #0x20]
	ldr r1, [r2, #0x20]
	str r4, [sp]
	movs r2, #4
	movs r3, #0
	bl AuxAnim_SetAnim
	ldr r3, _0805ACF0 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r3
	movs r2, #0x40
	orrs r0, r2
	ldr r1, _0805ACF4 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0x14]
	ldr r5, _0805ACF8 @ =0x030046B8
	ldr r2, [r5]
	adds r2, #1
	ldr r4, _0805ACFC @ =0x000003FF
	ands r2, r4
	lsls r0, r2, #1
	ldr r3, _0805AD00 @ =0x0203B400
	adds r0, r0, r3
	ldrh r1, [r0]
	movs r6, #1
	ands r1, r6
	adds r1, #1
	adds r2, #1
	ands r2, r4
	str r2, [r5]
	lsls r0, r2, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	ldrb r3, [r7, #0xa]
	movs r6, #0xf
	ands r0, r6
	subs r3, r3, r0
	adds r3, #3
	adds r2, #1
	ands r2, r4
	str r2, [r5]
	lsls r2, r2, #1
	ldr r0, _0805AD00 @ =0x0203B400
	adds r2, r2, r0
	ldrh r0, [r2]
	movs r2, #7
	mov sl, r2
	ands r0, r2
	ldrh r6, [r7, #0x10]
	adds r0, r0, r6
	adds r6, r7, #0
	adds r6, #0x14
	str r0, [sp]
	movs r0, #1
	mov r8, r0
	str r0, [sp, #4]
	movs r2, #2
	mov sb, r2
	str r2, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r6, #0
	add r2, sp, #0x10
	bl FUN_080ddcc8
	ldr r0, [r5]
	adds r0, #1
	ands r0, r4
	lsls r1, r0, #1
	ldr r3, _0805AD00 @ =0x0203B400
	adds r1, r1, r3
	ldrh r1, [r1]
	movs r2, #1
	ands r1, r2
	adds r1, #1
	adds r0, #1
	ands r0, r4
	str r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	mov r3, sl
	ands r0, r3
	ldrh r2, [r7, #0x10]
	adds r0, r0, r2
	ldrb r3, [r7, #0xa]
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	mov r2, sb
	str r2, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r6, #0
	add r2, sp, #0x10
	bl FUN_080ddcc8
	ldr r0, [r5]
	adds r0, #1
	ands r0, r4
	lsls r1, r0, #1
	ldr r3, _0805AD00 @ =0x0203B400
	adds r1, r1, r3
	ldrh r1, [r1]
	movs r2, #1
	ands r1, r2
	adds r1, #1
	adds r0, #1
	ands r0, r4
	str r0, [r5]
	lsls r2, r0, #1
	adds r2, r2, r3
	ldrh r3, [r2]
	movs r2, #0xf
	ands r3, r2
	ldrb r2, [r7, #0xa]
	adds r3, r3, r2
	adds r3, #3
	adds r0, #1
	ands r0, r4
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _0805AD00 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r2, sl
	ands r0, r2
	ldrh r2, [r7, #0x10]
	adds r0, r0, r2
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	mov r2, sb
	str r2, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r6, #0
	add r2, sp, #0x10
	bl FUN_080ddcc8
	ldr r0, _0805AD04 @ =0x00000339
	bl PlaySound_082406e0
_0805ACCA:
	add r3, sp, #0x18
	ldrb r4, [r7, #0xa]
	ldrh r5, [r7, #0x10]
	ldr r2, _0805AD08 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	muls r0, r5, r0
	adds r6, r3, #0
	cmp r0, #0
	blt _0805AD0C
	asrs r1, r0, #0xc
	b _0805AD12
	.align 2, 0
_0805ACF0: .4byte 0xFFFF0000
_0805ACF4: .4byte 0x0000FFFF
_0805ACF8: .4byte 0x030046B8
_0805ACFC: .4byte 0x000003FF
_0805AD00: .4byte 0x0203B400
_0805AD04: .4byte 0x00000339
_0805AD08: .4byte 0x085B0A08
_0805AD0C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805AD12:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0805AD2A
	asrs r0, r0, #0xc
	b _0805AD30
_0805AD2A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805AD30:
	strh r0, [r3, #4]
	adds r1, r7, #0
	adds r1, #0x14
	add r0, sp, #0x18
	ldrh r0, [r0]
	ldrh r2, [r7, #0x14]
	adds r0, r0, r2
	strh r0, [r7, #0x14]
	ldrh r0, [r6, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r6, #4]
	ldrh r6, [r1, #4]
	adds r0, r0, r6
	strh r0, [r1, #4]
	ldrb r0, [r7, #4]
	cmp r0, #0
	beq _0805AD62
	ldr r0, [sp, #0x20]
	adds r1, r7, #0
	ldr r2, [sp, #0x24]
	bl FUN_0805a6ec
	b _0805AD68
_0805AD62:
	ldrh r0, [r7, #6]
	adds r0, #1
	strh r0, [r7, #6]
_0805AD68:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805ad78
FUN_0805ad78: @ 0x0805AD78
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r1, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805ADA0
	movs r0, #0
	strb r0, [r4]
	adds r2, r4, #0
	adds r2, #0x98
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	movs r1, #0xd4
	lsls r1, r1, #1
	adds r0, r4, r1
	subs r1, #0x76
	bl Video_SetAuxSpritePltt
_0805ADA0:
	ldrh r1, [r4, #6]
	movs r0, #0x14
	subs r0, r0, r1
	mov r3, sp
	ldrb r5, [r4, #0xa]
	lsls r6, r0, #1
	ldr r2, _0805ADC8 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805ADCC
	asrs r1, r0, #0xc
	b _0805ADD2
	.align 2, 0
_0805ADC8: .4byte 0x085B0A08
_0805ADCC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805ADD2:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805ADEA
	asrs r0, r0, #0xc
	b _0805ADF0
_0805ADEA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805ADF0:
	strh r0, [r3, #4]
	adds r1, r4, #0
	adds r1, #0x14
	mov r2, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r4, #0x14]
	adds r0, r0, r3
	strh r0, [r4, #0x14]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	ldrh r0, [r4, #6]
	cmp r0, #0x13
	bls _0805AE24
	movs r0, #2
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	movs r0, #0
	b _0805AE38
_0805AE24:
	cmp r0, #0xa
	bne _0805AE34
	movs r3, #0xd4
	lsls r3, r3, #1
	adds r0, r4, r3
	movs r1, #0xc8
	bl Video_SetAuxSpritePltt
_0805AE34:
	ldrh r0, [r4, #6]
	adds r0, #1
_0805AE38:
	strh r0, [r4, #6]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805ae44
FUN_0805ae44: @ 0x0805AE44
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov sb, r0
	adds r7, r1, #0
	mov sl, r2
	ldrb r0, [r7]
	cmp r0, #0
	beq _0805AE84
	movs r4, #0
	strb r4, [r7]
	adds r2, r7, #0
	adds r2, #0x98
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	adds r0, r7, #0
	bl FUN_0805a8d0
	adds r0, r7, #0
	adds r0, #0xe8
	mov r2, sb
	ldr r1, [r2, #0x20]
	str r4, [sp]
	movs r2, #4
	movs r3, #0
	bl AuxAnim_SetAnim
_0805AE84:
	add r3, sp, #0x10
	ldrb r4, [r7, #0xa]
	movs r5, #0x14
	ldr r2, _0805AEA8 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0805AEAC
	asrs r1, r0, #0xc
	b _0805AEB2
	.align 2, 0
_0805AEA8: .4byte 0x085B0A08
_0805AEAC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805AEB2:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0805AECA
	asrs r0, r0, #0xc
	b _0805AED0
_0805AECA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805AED0:
	strh r0, [r3, #4]
	adds r6, r7, #0
	adds r6, #0x14
	add r1, sp, #0x10
	adds r0, r1, #0
	ldrh r0, [r0]
	ldrh r4, [r7, #0x14]
	adds r0, r0, r4
	strh r0, [r7, #0x14]
	ldrh r0, [r1, #2]
	ldrh r2, [r6, #2]
	adds r0, r0, r2
	strh r0, [r6, #2]
	ldrh r0, [r1, #4]
	ldrh r4, [r6, #4]
	adds r0, r0, r4
	strh r0, [r6, #4]
	ldrh r0, [r7, #6]
	movs r1, #3
	mov ip, r1
	mov r2, ip
	ands r2, r0
	mov ip, r2
	cmp r2, #0
	bne _0805AF74
	ldr r4, _0805AF88 @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r4
	movs r3, #0x40
	orrs r0, r3
	ldr r1, _0805AF8C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x18]
	add r2, sp, #0x18
	ldr r0, [r2, #4]
	ands r0, r4
	orrs r0, r3
	str r0, [r2, #4]
	ldr r5, _0805AF90 @ =0x0203B400
	ldr r4, _0805AF94 @ =0x030046B8
	mov r8, r4
	ldr r0, [r4]
	adds r0, #1
	ldr r4, _0805AF98 @ =0x000003FF
	ands r0, r4
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	movs r3, #1
	ands r1, r3
	adds r1, #1
	adds r0, #1
	ands r0, r4
	lsls r3, r0, #1
	adds r3, r3, r5
	ldrb r3, [r3]
	adds r0, #1
	ands r0, r4
	mov r4, r8
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r4, #7
	ands r0, r4
	adds r0, #0x10
	mov r4, ip
	str r4, [sp]
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	bl FUN_080ddcc8
	ldr r0, _0805AF9C @ =0x00000339
	bl PlaySound_082406e0
_0805AF74:
	ldrb r0, [r7, #4]
	cmp r0, #0
	beq _0805AFA0
	mov r0, sb
	adds r1, r7, #0
	mov r2, sl
	bl FUN_0805a6ec
	b _0805AFA6
	.align 2, 0
_0805AF88: .4byte 0xFFFF0000
_0805AF8C: .4byte 0x0000FFFF
_0805AF90: .4byte 0x0203B400
_0805AF94: .4byte 0x030046B8
_0805AF98: .4byte 0x000003FF
_0805AF9C: .4byte 0x00000339
_0805AFA0:
	ldrh r0, [r7, #6]
	adds r0, #1
	strh r0, [r7, #6]
_0805AFA6:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805afb8
FUN_0805afb8: @ 0x0805AFB8
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x24
	movs r5, #0
	ldr r7, _0805AFFC @ =0x085ABA04
_0805AFC4:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _0805AFE8
	ldrb r0, [r4, #1]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r3, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl _call_via_r3
	adds r0, r4, #0
	bl FUN_0805a728
_0805AFE8:
	adds r5, #1
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r4, r4, r0
	cmp r5, #7
	ble _0805AFC4
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805AFFC: .4byte 0x085ABA04

	thumb_func_start FUN_0805b000
FUN_0805b000: @ 0x0805B000
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x24
	movs r4, #0
_0805B00A:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805a6c8
	adds r4, #1
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r5, r5, r0
	cmp r4, #7
	ble _0805B00A
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805b028
FUN_0805b028: @ 0x0805B028
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	strh r1, [r6, #0x1c]
	strh r2, [r6, #0x1e]
	ldr r0, _0805B060 @ =0x0000922E
	ldr r1, _0805B064 @ =0x000078E1
	bl GetFile
	str r0, [r6, #0x20]
	adds r5, r6, #0
	adds r5, #0x24
	movs r4, #0
_0805B040:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805a53c
	adds r4, #1
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r5, r5, r0
	cmp r4, #7
	ble _0805B040
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805B060: .4byte 0x0000922E
_0805B064: .4byte 0x000078E1

	thumb_func_start FUN_0805b068
FUN_0805b068: @ 0x0805B068
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r1, _0805B09C @ =0x00000E44
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805B0A8
	ldr r1, _0805B0A0 @ =FUN_0805afb8
	ldr r2, _0805B0A4 @ =FUN_0805b000
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0805b028
	cmp r0, #0
	bge _0805B0A8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805B0AA
	.align 2, 0
_0805B09C: .4byte 0x00000E44
_0805B0A0: .4byte FUN_0805afb8
_0805B0A4: .4byte FUN_0805b000
_0805B0A8:
	adds r0, r4, #0
_0805B0AA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805b0b0
FUN_0805b0b0: @ 0x0805B0B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov r8, r0
	adds r7, r1, #0
	adds r6, r2, #0
	adds r5, r3, #0
	add r1, sp, #4
	bl FUN_0805a43c
	adds r4, r0, #0
	cmp r4, #0
	bne _0805B0D6
	movs r0, #1
	rsbs r0, r0, #0
	b _0805B190
_0805B0D6:
	movs r1, #0
	strb r1, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	movs r2, #0
	strh r1, [r4, #6]
	strb r5, [r4, #0xa]
	strb r5, [r4, #0xb]
	ldr r0, [sp, #0x28]
	strh r0, [r4, #0x10]
	ldr r0, [sp, #0x2c]
	strh r0, [r4, #0x12]
	strh r1, [r4, #8]
	str r6, [r4, #0x44]
	strb r2, [r4, #0xc]
	ldr r0, [r7]
	ldr r1, [r7, #4]
	str r0, [r4, #0x14]
	str r1, [r4, #0x18]
	adds r5, r4, #0
	adds r5, #0xf8
	movs r6, #0
	movs r0, #0x48
	adds r0, r0, r4
	mov sl, r0
	movs r1, #0x14
	adds r1, r1, r4
	mov sb, r1
	adds r7, r4, #0
	adds r7, #0x98
_0805B112:
	lsls r0, r6, #3
	adds r0, r0, r4
	ldr r1, [r4, #0x14]
	ldr r2, [r4, #0x18]
	str r1, [r0, #0x1c]
	str r2, [r0, #0x20]
	ldr r0, [r4, #0x14]
	ldr r1, [r4, #0x18]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	cmp r6, #0
	bne _0805B148
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	mov r2, r8
	ldr r1, [r2, #0x20]
	str r6, [sp]
	adds r0, r4, #0
	adds r0, #0xe8
	movs r2, #1
	movs r3, #0
	bl AuxAnim_SetAnim
	b _0805B150
_0805B148:
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
_0805B150:
	adds r6, #1
	adds r5, #0x2c
	cmp r6, #3
	ble _0805B112
	movs r1, #0xd4
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0xc8
	bl Video_SetAuxSpritePltt
	mov r0, sl
	mov r1, sb
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r7, #0
	mov r1, sb
	movs r2, #0
	bl Hitbox_SetPos
	ldrh r1, [r7, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r7, #6]
	ldr r0, [sp, #4]
	movs r1, #1
	lsls r1, r0
	mov r2, r8
	ldr r0, [r2, #0x18]
	orrs r0, r1
	str r0, [r2, #0x18]
	movs r0, #0
_0805B190:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805b1a0
FUN_0805b1a0: @ 0x0805B1A0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r3, r5, #0
	adds r3, #0x24
	movs r4, #0
	movs r6, #1
	movs r1, #3
	mov r8, r1
	mov ip, r4
	movs r7, #0xe2
	lsls r7, r7, #1
_0805B1BA:
	adds r2, r6, #0
	lsls r2, r4
	ldr r1, [r5, #0x18]
	ands r1, r2
	cmp r1, #0
	beq _0805B1D6
	ldrb r1, [r3, #1]
	cmp r1, #2
	bhi _0805B1D6
	mov r1, r8
	strb r1, [r3, #1]
	strb r6, [r3]
	mov r1, ip
	strh r1, [r3, #6]
_0805B1D6:
	adds r4, #1
	adds r3, r3, r7
	cmp r4, #7
	ble _0805B1BA
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805b1e8
FUN_0805b1e8: @ 0x0805B1E8
	push {r4, r5, lr}
	adds r4, r1, #0
	movs r2, #0
	movs r5, #1
	ldr r1, [r0, #0x18]
	adds r3, r0, #0
	adds r3, #0x40
_0805B1F6:
	adds r0, r5, #0
	lsls r0, r2
	ands r0, r1
	cmp r0, #0
	bne _0805B206
	str r2, [r4]
	adds r0, r3, #0
	b _0805B210
_0805B206:
	adds r3, #0x8c
	adds r2, #1
	cmp r2, #0xf
	ble _0805B1F6
	movs r0, #0
_0805B210:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805b218
FUN_0805b218: @ 0x0805B218
	movs r0, #2
	movs r1, #0
	strb r0, [r2, #2]
	movs r0, #1
	strb r0, [r2, #1]
	strh r1, [r2, #4]
	bx lr
	.align 2, 0

	thumb_func_start FUN_0805b228
FUN_0805b228: @ 0x0805B228
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x20
	adds r2, r0, #0
	adds r7, r1, #0
	movs r0, #0
	movs r5, #0
	strb r0, [r7, #2]
	movs r6, #1
	strb r6, [r7, #1]
	strh r5, [r7, #4]
	strb r0, [r7, #3]
	adds r4, r7, #0
	adds r4, #0x60
	adds r2, #0x24
	adds r0, r4, #0
	adds r1, r2, #0
	movs r2, #3
	bl AuxSprite_Add
	strh r6, [r4, #0x10]
	movs r0, #2
	strb r0, [r4, #7]
	movs r0, #0x7c
	adds r0, r0, r7
	mov r8, r0
	str r5, [sp, #0xc]
	add r0, sp, #0xc
	mov r1, r8
	ldr r2, _0805B2E0 @ =0x05000002
	bl CpuSet
	subs r4, #0x50
	ldr r2, _0805B2E4 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r5, #0x1e
	orrs r0, r5
	ldr r1, _0805B2E8 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x10]
	add r3, sp, #0x10
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r5
	str r0, [r3, #4]
	movs r0, #0xf0
	lsls r0, r0, #0xf
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _0805B2EC @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	str r3, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _0805B2F0 @ =FUN_0805b218
	adds r0, r4, #0
	adds r2, r7, #0
	bl Hitbox_SetHandler
	str r6, [sp]
	str r5, [sp, #4]
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0xa
	movs r3, #0x10
	bl Hitbox_SetAttack
	add sp, #0x20
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805B2E0: .4byte 0x05000002
_0805B2E4: .4byte 0xFFFF0000
_0805B2E8: .4byte 0x0000FFFF
_0805B2EC: .4byte 0x00002001
_0805B2F0: .4byte FUN_0805b218

	thumb_func_start FUN_0805b2f4
FUN_0805b2f4: @ 0x0805B2F4
	push {lr}
	adds r0, r1, #0
	adds r0, #0x60
	bl AuxSprite_Remove
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805b304
FUN_0805b304: @ 0x0805B304
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r3, [r1, #0x60]
	movs r4, #1
	orrs r3, r4
	str r3, [r1, #0x60]
	lsls r4, r2
	ldr r1, [r5, #0x18]
	bics r1, r4
	str r1, [r5, #0x18]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805b320
FUN_0805b320: @ 0x0805B320
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r3, r4, #0
	adds r3, #0x7c
	ldr r2, [r4, #0xc]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r5, #0
	ldrsh r1, [r3, r5]
	subs r0, r0, r1
	movs r5, #4
	ldrsh r1, [r2, r5]
	movs r5, #4
	ldrsh r2, [r3, r5]
	subs r1, r1, r2
	bl ArcTan2_8
	ldrb r1, [r4, #3]
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	asrs r3, r0, #0x18
	ldrb r1, [r4, #8]
	rsbs r0, r1, #0
	cmp r3, r0
	bge _0805B35A
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	b _0805B360
_0805B35A:
	cmp r3, r1
	ble _0805B360
	adds r2, r1, #0
_0805B360:
	ldrb r0, [r4, #3]
	adds r0, r0, r2
	strb r0, [r4, #3]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805b36c
FUN_0805b36c: @ 0x0805B36C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	adds r6, r1, #0
	mov sl, r2
	adds r7, r6, #0
	adds r7, #0x60
	ldrb r0, [r6, #1]
	cmp r0, #0
	beq _0805B38C
	movs r0, #0
	strb r0, [r6, #1]
_0805B38C:
	mov r3, sp
	ldrb r4, [r6, #3]
	ldrh r5, [r6, #6]
	ldr r2, _0805B3B0 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0805B3B4
	asrs r1, r0, #0xc
	b _0805B3BA
	.align 2, 0
_0805B3B0: .4byte 0x085B0A08
_0805B3B4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805B3BA:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0805B3D2
	asrs r0, r0, #0xc
	b _0805B3D8
_0805B3D2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805B3D8:
	strh r0, [r3, #4]
	adds r4, r7, #0
	adds r4, #0x1c
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r2, [r7, #0x1c]
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r2, [r4, #2]
	adds r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r4, #4]
	adds r0, r0, r1
	strh r0, [r4, #4]
	adds r5, r6, #0
	adds r5, #0x10
	adds r1, r6, #0
	adds r1, #0x7c
	adds r0, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r5, #0
	bl Hitbox_Register
	movs r0, #0x1e
	ldrsh r2, [r7, r0]
	mov r8, r2
	adds r5, r4, #0
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r4, #0
	blt _0805B43C
	cmp r1, #0
	blt _0805B43C
	ldr r0, _0805B440 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0805B43C
	ldr r0, _0805B444 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0805B448
_0805B43C:
	movs r4, #0
	b _0805B456
	.align 2, 0
_0805B440: .4byte 0x030046A8
_0805B444: .4byte 0x030046AC
_0805B448:
	ldr r0, _0805B468 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0805B456:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0805B46C
	adds r0, #4
	b _0805B478
	.align 2, 0
_0805B468: .4byte 0x030046A4
_0805B46C:
	ldr r0, _0805B48C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0805B478:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0805B490
	cmp r2, #2
	beq _0805B494
	b _0805B498
	.align 2, 0
_0805B48C: .4byte 0x030046A4
_0805B490:
	ldrb r0, [r5, #4]
	b _0805B496
_0805B494:
	ldrb r0, [r5]
_0805B496:
	subs r1, r1, r0
_0805B498:
	cmp r8, r1
	bhi _0805B4AA
	movs r0, #2
	movs r1, #0
	strb r0, [r6, #2]
	movs r0, #1
	strb r0, [r6, #1]
	strh r1, [r6, #4]
	b _0805B4C0
_0805B4AA:
	ldrh r0, [r6, #4]
	cmp r0, #0x7f
	bls _0805B4BC
	mov r0, sb
	adds r1, r6, #0
	mov r2, sl
	bl FUN_0805b304
	b _0805B4C0
_0805B4BC:
	adds r0, #1
	strh r0, [r6, #4]
_0805B4C0:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805b4d0
FUN_0805b4d0: @ 0x0805B4D0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	adds r6, r1, #0
	mov sl, r2
	adds r7, r6, #0
	adds r7, #0x60
	ldrb r0, [r6, #1]
	cmp r0, #0
	beq _0805B4F0
	movs r0, #0
	strb r0, [r6, #1]
_0805B4F0:
	adds r0, r6, #0
	bl FUN_0805b320
	mov r3, sp
	ldrb r4, [r6, #3]
	ldrh r5, [r6, #6]
	ldr r2, _0805B518 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0805B51C
	asrs r1, r0, #0xc
	b _0805B522
	.align 2, 0
_0805B518: .4byte 0x085B0A08
_0805B51C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805B522:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _0805B53C @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0805B540
	asrs r0, r0, #0xc
	b _0805B546
	.align 2, 0
_0805B53C: .4byte 0x085B0A08
_0805B540:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805B546:
	strh r0, [r3, #4]
	adds r4, r7, #0
	adds r4, #0x1c
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r2, [r7, #0x1c]
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r2, [r4, #2]
	adds r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r4, #4]
	adds r0, r0, r1
	strh r0, [r4, #4]
	adds r5, r6, #0
	adds r5, #0x10
	adds r1, r6, #0
	adds r1, #0x7c
	adds r0, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r5, #0
	bl Hitbox_Register
	movs r0, #0x1e
	ldrsh r2, [r7, r0]
	mov r8, r2
	adds r5, r4, #0
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r4, #0
	blt _0805B5AA
	cmp r1, #0
	blt _0805B5AA
	ldr r0, _0805B5B0 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0805B5AA
	ldr r0, _0805B5B4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0805B5B8
_0805B5AA:
	movs r4, #0
	b _0805B5C6
	.align 2, 0
_0805B5B0: .4byte 0x030046A8
_0805B5B4: .4byte 0x030046AC
_0805B5B8:
	ldr r0, _0805B5D8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0805B5C6:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0805B5DC
	adds r0, #4
	b _0805B5E8
	.align 2, 0
_0805B5D8: .4byte 0x030046A4
_0805B5DC:
	ldr r0, _0805B5FC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0805B5E8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0805B600
	cmp r2, #2
	beq _0805B604
	b _0805B608
	.align 2, 0
_0805B5FC: .4byte 0x030046A4
_0805B600:
	ldrb r0, [r5, #4]
	b _0805B606
_0805B604:
	ldrb r0, [r5]
_0805B606:
	subs r1, r1, r0
_0805B608:
	cmp r8, r1
	bhi _0805B61A
	movs r0, #2
	movs r1, #0
	strb r0, [r6, #2]
	movs r0, #1
	strb r0, [r6, #1]
	strh r1, [r6, #4]
	b _0805B630
_0805B61A:
	ldrh r0, [r6, #4]
	cmp r0, #0x7f
	bls _0805B62C
	mov r0, sb
	adds r1, r6, #0
	mov r2, sl
	bl FUN_0805b304
	b _0805B630
_0805B62C:
	adds r0, #1
	strh r0, [r6, #4]
_0805B630:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805b640
FUN_0805b640: @ 0x0805B640
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r3, r4, #0
	adds r3, #0x60
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0805B658
	movs r0, #0
	strb r0, [r4, #1]
	movs r0, #4
	strh r0, [r3, #0x10]
_0805B658:
	ldrh r0, [r4, #4]
	cmp r0, #3
	bne _0805B6C4
	ldrb r0, [r4, #3]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r1, r0, #3
	movs r0, #7
	ands r1, r0
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _0805B67C
	movs r0, #7
	b _0805B68A
_0805B67C:
	asrs r0, r1, #1
	ands r0, r2
	cmp r0, #0
	beq _0805B688
	movs r0, #8
	b _0805B68A
_0805B688:
	movs r0, #6
_0805B68A:
	strh r0, [r3, #0x10]
	cmp r1, #2
	bgt _0805B698
	ldr r0, [r3]
	movs r1, #0xd
	rsbs r1, r1, #0
	b _0805B6BE
_0805B698:
	cmp r1, #4
	bgt _0805B6A8
	ldr r0, [r3]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #8
	b _0805B6B0
_0805B6A8:
	cmp r1, #5
	bgt _0805B6B6
	ldr r0, [r3]
	movs r1, #0xc
_0805B6B0:
	orrs r0, r1
	str r0, [r3]
	b _0805B6D2
_0805B6B6:
	ldr r0, [r3]
	movs r1, #4
	orrs r0, r1
	subs r1, #0xd
_0805B6BE:
	ands r0, r1
	str r0, [r3]
	b _0805B6D2
_0805B6C4:
	cmp r0, #5
	bls _0805B6D2
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0805b304
	b _0805B6D8
_0805B6D2:
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
_0805B6D8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805b6e0
FUN_0805b6e0: @ 0x0805B6E0
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x40
	movs r5, #0
	ldr r7, _0805B71C @ =0x085ABA20
_0805B6EC:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _0805B70A
	ldrb r0, [r4, #2]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r3, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl _call_via_r3
_0805B70A:
	adds r5, #1
	adds r4, #0x8c
	cmp r5, #0xf
	ble _0805B6EC
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805B71C: .4byte 0x085ABA20

	thumb_func_start FUN_0805b720
FUN_0805b720: @ 0x0805B720
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x40
	movs r4, #0
_0805B72A:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805b2f4
	adds r4, #1
	adds r5, #0x8c
	cmp r4, #0xf
	ble _0805B72A
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805b744
FUN_0805b744: @ 0x0805B744
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	movs r0, #0xa
	strh r0, [r6, #0x1c]
	strh r0, [r6, #0x1e]
	adds r5, r6, #0
	adds r5, #0x24
	ldr r1, _0805B78C @ =0x0000210E
	adds r0, r5, #0
	bl Video_GetAuxSprite
	str r4, [r6, #0x20]
	movs r1, #0x32
	cmp r4, #0
	bne _0805B766
	movs r1, #0x2c
_0805B766:
	adds r0, r5, #0
	bl Video_SetAuxSpritePltt
	adds r5, r6, #0
	adds r5, #0x40
	movs r4, #0
_0805B772:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805b228
	adds r4, #1
	adds r5, #0x8c
	cmp r4, #0xf
	ble _0805B772
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805B78C: .4byte 0x0000210E

	thumb_func_start FUN_0805b790
FUN_0805b790: @ 0x0805B790
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0x90
	lsls r1, r1, #4
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805B7CC
	ldr r1, _0805B7C4 @ =FUN_0805b6e0
	ldr r2, _0805B7C8 @ =FUN_0805b720
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0805b744
	cmp r0, #0
	bge _0805B7CC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805B7CE
	.align 2, 0
_0805B7C4: .4byte FUN_0805b6e0
_0805B7C8: .4byte FUN_0805b720
_0805B7CC:
	adds r0, r4, #0
_0805B7CE:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805b7d4
FUN_0805b7d4: @ 0x0805B7D4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	mov sb, r1
	mov r8, r2
	adds r4, r3, #0
	add r1, sp, #8
	bl FUN_0805b1e8
	adds r5, r0, #0
	cmp r5, #0
	bne _0805B7F8
	movs r0, #1
	rsbs r0, r0, #0
	b _0805B886
_0805B7F8:
	adds r6, r5, #0
	adds r6, #0x60
	movs r1, #0
	strb r4, [r5]
	ldrb r0, [r5]
	cmp r0, #1
	beq _0805B816
	cmp r0, #1
	bgt _0805B810
	cmp r0, #0
	beq _0805B81A
	b _0805B822
_0805B810:
	cmp r0, #2
	beq _0805B81A
	b _0805B822
_0805B816:
	strb r0, [r5, #2]
	b _0805B81E
_0805B81A:
	strb r1, [r5, #2]
	movs r0, #1
_0805B81E:
	strb r0, [r5, #1]
	strh r1, [r5, #4]
_0805B822:
	ldr r0, [sp, #0x2c]
	strh r0, [r5, #6]
	ldr r0, [sp, #0x28]
	strb r0, [r5, #3]
	movs r2, #1
	strb r2, [r5, #8]
	mov r0, r8
	str r0, [r5, #0xc]
	adds r1, r5, #0
	adds r1, #0x10
	ldr r0, [r7, #0x20]
	mov r8, r1
	cmp r0, #0
	bne _0805B842
	str r2, [sp]
	b _0805B846
_0805B842:
	movs r0, #2
	str r0, [sp]
_0805B846:
	movs r0, #0x1e
	str r0, [sp, #4]
	adds r0, r1, #0
	ldr r1, [sp, #0x30]
	ldr r2, [sp, #0x34]
	movs r3, #0x10
	bl Hitbox_SetAttack
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	movs r4, #1
	strh r4, [r6, #0x10]
	adds r1, r5, #0
	adds r1, #0x7c
	mov r0, r8
	movs r2, #0
	bl Hitbox_SetPos
	ldr r0, [sp, #8]
	lsls r4, r0
	ldr r0, [r7, #0x18]
	orrs r0, r4
	str r0, [r7, #0x18]
	movs r0, #0
_0805B886:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805b894
FUN_0805b894: @ 0x0805B894
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r2, #0
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r5, #6]
	ands r0, r1
	cmp r0, #0
	beq _0805B8B6
	adds r0, r5, #0
	adds r0, #0x42
	ldrb r0, [r0]
	b _0805B8CE
_0805B8B6:
	movs r1, #0x24
	ldrsh r0, [r6, r1]
	movs r2, #0x24
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	movs r3, #0x28
	ldrsh r1, [r6, r3]
	movs r3, #0x28
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl ArcTan2_8
_0805B8CE:
	strb r0, [r4, #6]
	movs r0, #0
	mov r8, r0
	movs r0, #8
	ldrsb r0, [r4, r0]
	cmp r0, #0
	blt _0805B8E4
	movs r0, #0xfa
	strb r0, [r4, #9]
	mov r1, r8
	strb r1, [r4, #8]
_0805B8E4:
	adds r0, r5, #0
	adds r1, r6, #0
	bl Hitbox_ApplyDamage
	ldr r3, _0805B93C @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r2, #0x10
	orrs r0, r2
	ldr r1, _0805B940 @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0xc]
	ldrh r1, [r6, #0x3e]
	adds r3, r4, #0
	adds r3, #0x14
	add r2, sp, #8
	str r2, [sp]
	movs r7, #1
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r2, #0
	bl FUN_0805fe7c
	ldrh r0, [r5, #0x3e]
	adds r0, #2
	strh r0, [r5, #0x3e]
	ldrh r0, [r6, #0x3e]
	bl FUN_08029864
	bl FUN_08084710
	adds r1, r0, #0
	cmp r1, #0
	beq _0805B944
	movs r0, #6
	strb r0, [r4, #1]
	strb r7, [r4]
	mov r3, r8
	strh r3, [r4, #4]
	b _0805B94C
	.align 2, 0
_0805B93C: .4byte 0xFFFF0000
_0805B940: .4byte 0x0000FFFF
_0805B944:
	movs r0, #8
	strb r0, [r4, #1]
	strb r7, [r4]
	strh r1, [r4, #4]
_0805B94C:
	movs r0, #0x84
	lsls r0, r0, #1
	bl PlaySound_082406e0
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805b960
FUN_0805b960: @ 0x0805B960
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	bl Hitbox_ApplyDamage
	ldr r3, _0805B9AC @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r2, #0x10
	orrs r0, r2
	ldr r1, _0805B9B0 @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0xc]
	ldrh r1, [r5, #0x3e]
	adds r4, #0x14
	add r0, sp, #8
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	adds r0, r6, #0
	movs r2, #1
	adds r3, r4, #0
	bl FUN_0805fe7c
	ldrh r0, [r5, #0x3e]
	bl FUN_080298b8
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805B9AC: .4byte 0xFFFF0000
_0805B9B0: .4byte 0x0000FFFF

	thumb_func_start FUN_0805b9b4
FUN_0805b9b4: @ 0x0805B9B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov r8, r0
	mov sl, r1
	movs r1, #0
	mov r0, sl
	strb r1, [r0, #1]
	movs r0, #1
	mov r2, sl
	strb r0, [r2]
	strh r1, [r2, #4]
	strb r1, [r2, #6]
	movs r4, #0x84
	lsls r4, r4, #1
	add r4, sl
	ldr r1, _0805BB08 @ =0x0000DA6D
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r4, #0
	ldr r1, _0805BB0C @ =0x00000263
	bl Video_SetAuxSpritePltt
	ldr r0, _0805BB10 @ =0x00001688
	add r0, r8
	str r0, [r4, #0xc]
	mov r5, sl
	adds r5, #0xdc
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #1
	bl AuxSprite_Add
	movs r0, #2
	strb r0, [r5, #7]
	adds r5, #0x1c
	movs r0, #0
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	adds r1, r5, #0
	ldr r2, _0805BB14 @ =0x05000002
	bl CpuSet
	movs r4, #0x92
	lsls r4, r4, #1
	add r4, sl
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl ParticleShadow_Init
	adds r0, r4, #0
	bl ParticleShadow_Hide
	mov r7, sl
	adds r7, #0x7c
	ldr r2, _0805BB18 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x20
	orrs r0, r1
	ldr r1, _0805BB1C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x10]
	add r5, sp, #0x10
	ldr r0, [r5, #4]
	ands r0, r2
	movs r1, #0x20
	orrs r0, r1
	str r0, [r5, #4]
	movs r0, #0xf0
	lsls r0, r0, #0xf
	str r0, [sp, #0x18]
	add r4, sp, #0x18
	ldr r0, [r4, #4]
	ands r0, r2
	str r0, [r4, #4]
	ldr r2, _0805BB20 @ =0x00004005
	movs r0, #0x10
	mov sb, r0
	str r0, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	mov r6, sl
	adds r6, #0x14
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _0805BB24 @ =FUN_0805b894
	adds r0, r7, #0
	mov r2, sl
	bl Hitbox_SetHandler
	mov r2, r8
	ldrh r1, [r2, #0x22]
	adds r0, r7, #0
	movs r2, #0x80
	movs r3, #0
	bl Hitbox_SetPowerAndAttributes
	adds r0, r7, #0
	bl Hitbox_Register
	subs r7, #0x50
	movs r0, #0x20
	strh r0, [r5]
	movs r0, #0xf0
	strh r0, [r5, #2]
	movs r1, #0x20
	strh r1, [r5, #4]
	movs r2, #0
	strh r2, [r4]
	movs r0, #0x78
	strh r0, [r4, #2]
	strh r2, [r4, #4]
	ldr r2, _0805BB28 @ =0x00002001
	mov r0, sb
	str r0, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _0805BB2C @ =FUN_0805b960
	adds r0, r7, #0
	mov r2, sl
	bl Hitbox_SetHandler
	mov r2, r8
	ldrh r1, [r2, #0x20]
	movs r3, #0x80
	lsls r3, r3, #5
	movs r0, #0
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r2, #0x1e
	bl Hitbox_SetAttack
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805BB08: .4byte 0x0000DA6D
_0805BB0C: .4byte 0x00000263
_0805BB10: .4byte 0x00001688
_0805BB14: .4byte 0x05000002
_0805BB18: .4byte 0xFFFF0000
_0805BB1C: .4byte 0x0000FFFF
_0805BB20: .4byte 0x00004005
_0805BB24: .4byte FUN_0805b894
_0805BB28: .4byte 0x00002001
_0805BB2C: .4byte FUN_0805b960

	thumb_func_start FUN_0805bb30
FUN_0805bb30: @ 0x0805BB30
	push {r4, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	adds r0, #0x7c
	bl Hitbox_Unregister
	movs r1, #0x92
	lsls r1, r1, #1
	adds r0, r4, r1
	bl ParticleShadow_Remove
	adds r0, r4, #0
	adds r0, #0xdc
	bl AuxSprite_Remove
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805bb54
FUN_0805bb54: @ 0x0805BB54
	push {lr}
	adds r3, r1, #0
	adds r2, r3, #0
	adds r2, #0xdc
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	subs r2, #0x60
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	movs r1, #0x92
	lsls r1, r1, #1
	adds r0, r3, r1
	bl ParticleShadow_Hide
	pop {r1}
	bx r1

	thumb_func_start FUN_0805bb7c
FUN_0805bb7c: @ 0x0805BB7C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x44
	movs r4, #0
_0805BB86:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805bb54
	adds r4, #1
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r5, r5, r0
	cmp r4, #0xf
	ble _0805BB86
	adds r0, r6, #0
	adds r0, #0x38
	bl FUN_080297fc
	movs r0, #0
	str r0, [r6, #0x18]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805bbb0
FUN_0805bbb0: @ 0x0805BBB0
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r5, r1, #0
	ldrb r0, [r5, #6]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r1, r0, #1
	movs r0, #3
	ands r1, r0
	add r4, sp, #4
	mov r3, sp
	adds r3, #5
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r7, r3, #0
	cmp r0, #1
	bhi _0805BBDE
	movs r0, #1
	b _0805BBE0
_0805BBDE:
	movs r0, #0
_0805BBE0:
	strb r0, [r4]
	cmp r1, #1
	bls _0805BBEA
	movs r0, #1
	b _0805BBEC
_0805BBEA:
	movs r0, #0
_0805BBEC:
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0xcc
	ldr r1, [r6, #0x40]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	add r3, sp, #4
	ldrb r3, [r3]
	ldrb r4, [r7]
	str r4, [sp]
	bl AuxAnim_SetAnim
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805bc0c
FUN_0805bc0c: @ 0x0805BC0C
	push {r4, r5, r6, lr}
	mov ip, r0
	mov r6, ip
	adds r6, #0xdc
	mov r2, ip
	adds r2, #0xf8
	mov r3, ip
	ldr r0, [r3, #0x14]
	ldr r1, [r3, #0x18]
	str r0, [r2]
	str r1, [r2, #4]
	mov r4, ip
	adds r4, #0xcc
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
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
	beq _0805BC52
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _0805BC5A
_0805BC52:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0805BC5A:
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
	beq _0805BC7E
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0805BC86
_0805BC7E:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0805BC86:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0805BCC0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _0805BD06
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0805BCCA
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0805BCC4
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _0805BCE0
	.align 2, 0
_0805BCC0: .4byte 0x0000FFFF
_0805BCC4:
	subs r0, #1
	strh r0, [r4, #8]
	b _0805BCDE
_0805BCCA:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0805BCDE
	strh r1, [r4, #8]
	movs r2, #1
	b _0805BCE0
_0805BCDE:
	movs r2, #0
_0805BCE0:
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
	bne _0805BD08
	movs r0, #1
	strb r0, [r4, #7]
	b _0805BD08
_0805BD06:
	movs r2, #0
_0805BD08:
	mov r3, ip
	strb r2, [r3, #2]
	ldrb r0, [r3, #1]
	cmp r0, #7
	beq _0805BD58
	movs r0, #0x16
	ldrsh r1, [r3, r0]
	ldrh r0, [r3, #0xe]
	cmp r1, r0
	ble _0805BD24
	ldrh r0, [r3, #0x16]
	subs r0, #1
	strh r0, [r3, #0x16]
	b _0805BD30
_0805BD24:
	cmp r1, r0
	bge _0805BD30
	mov r1, ip
	ldrh r0, [r1, #0x16]
	adds r0, #1
	strh r0, [r1, #0x16]
_0805BD30:
	ldr r0, _0805BD48 @ =0x085B0A08
	mov r2, ip
	ldrb r1, [r2, #3]
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	lsls r0, r0, #5
	cmp r0, #0
	blt _0805BD4C
	asrs r1, r0, #0xc
	b _0805BD52
	.align 2, 0
_0805BD48: .4byte 0x085B0A08
_0805BD4C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805BD52:
	ldrh r0, [r6, #0x1e]
	adds r0, r0, r1
	strh r0, [r6, #0x1e]
_0805BD58:
	mov r1, ip
	ldrb r0, [r1, #3]
	adds r0, #4
	strb r0, [r1, #3]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805bd68
FUN_0805bd68: @ 0x0805BD68
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	adds r4, r1, #0
	mov r8, r2
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805BD80
	movs r0, #0
	strb r0, [r4]
_0805BD80:
	ldrh r0, [r4, #0x10]
	mov r3, sp
	ldrb r5, [r4, #6]
	lsls r6, r0, #1
	ldr r2, _0805BDA4 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805BDA8
	asrs r1, r0, #0xc
	b _0805BDAE
	.align 2, 0
_0805BDA4: .4byte 0x085B0A08
_0805BDA8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805BDAE:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805BDC6
	asrs r0, r0, #0xc
	b _0805BDCC
_0805BDC6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805BDCC:
	strh r0, [r3, #4]
	adds r1, r4, #0
	adds r1, #0x14
	mov r2, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r4, #0x14]
	adds r0, r0, r3
	strh r0, [r4, #0x14]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0805bbb0
	ldrh r1, [r4, #4]
	mov r0, r8
	adds r0, #2
	cmp r1, r0
	blt _0805BE16
	movs r0, #1
	strb r0, [r4, #1]
	strb r0, [r4]
	movs r0, #0
	strh r0, [r4, #4]
_0805BE16:
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805be28
FUN_0805be28: @ 0x0805BE28
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	adds r4, r1, #0
	mov sb, r2
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805BE58
	movs r0, #0
	strb r0, [r4]
	adds r0, r4, #0
	adds r0, #0x7c
	movs r1, #5
	rsbs r1, r1, #0
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
	adds r1, r4, #0
	adds r1, #0x14
	movs r2, #0
	bl Hitbox_SetPos
_0805BE58:
	mov r0, r8
	ldrb r1, [r0, #0x1c]
	cmp r1, #0
	beq _0805BE66
	movs r0, #5
	movs r1, #0
	b _0805BE70
_0805BE66:
	mov r2, r8
	ldrb r0, [r2, #0x1e]
	cmp r0, #0
	beq _0805BE7A
	movs r0, #9
_0805BE70:
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	strh r1, [r4, #4]
	b _0805BF52
_0805BE7A:
	movs r0, #8
	ldrsb r0, [r4, r0]
	adds r5, r4, #0
	adds r5, #0x14
	cmp r0, #0
	blt _0805BEF4
	ldrh r0, [r4, #4]
	movs r3, #7
	ands r3, r0
	movs r6, #8
	ldrsb r6, [r4, r6]
	movs r7, #0x28
	add r7, r8
	mov ip, r7
	cmp r3, #0
	bne _0805BED4
	lsls r0, r6, #2
	add r0, ip
	ldr r1, [r0]
	movs r0, #0
	ldrsh r2, [r1, r0]
	movs r7, #0x14
	ldrsh r0, [r4, r7]
	subs r2, r2, r0
	movs r7, #4
	ldrsh r0, [r1, r7]
	movs r7, #4
	ldrsh r1, [r5, r7]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _0805BED0 @ =0x00022E24
	cmp r1, r0
	ble _0805BED4
	movs r0, #1
	strb r0, [r4, #1]
	strb r0, [r4]
	strh r3, [r4, #4]
	b _0805BF52
	.align 2, 0
_0805BED0: .4byte 0x00022E24
_0805BED4:
	lsls r0, r6, #2
	add r0, ip
	ldr r2, [r0]
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r7, #0x14
	ldrsh r1, [r4, r7]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r7, #4
	ldrsh r2, [r5, r7]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r4, #6]
_0805BEF4:
	adds r0, r4, #0
	adds r0, #0x7c
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	mov r0, r8
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0805bbb0
	ldrh r0, [r4, #4]
	cmp r0, #0x3f
	bls _0805BF1C
	movs r0, #4
	movs r1, #0
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	strh r1, [r4, #4]
_0805BF1C:
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _0805BF4C
	subs r0, #1
	strb r0, [r4, #9]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0805BF4C
	mov r2, r8
	ldrb r0, [r2, #0x1f]
	cmp r0, #2
	bne _0805BF44
	mov r3, sb
	cmp r3, #7
	bgt _0805BF40
	movs r0, #1
	b _0805BF4A
_0805BF40:
	strb r1, [r4, #8]
	b _0805BF4C
_0805BF44:
	cmp r0, #0
	beq _0805BF4A
	movs r0, #0xff
_0805BF4A:
	strb r0, [r4, #8]
_0805BF4C:
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
_0805BF52:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805bf60
FUN_0805bf60: @ 0x0805BF60
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	adds r5, r1, #0
	mov sl, r2
	ldrb r0, [r5]
	cmp r0, #0
	bne _0805BF7A
	b _0805C084
_0805BF7A:
	movs r0, #0
	strb r0, [r5]
	movs r0, #8
	ldrsb r0, [r5, r0]
	adds r7, r5, #0
	adds r7, #0x1c
	cmp r0, #0
	blt _0805C026
	ldr r2, _0805BFBC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0805BFC0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0805BFC4 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	mov r4, sp
	ldrb r6, [r0]
	ldr r1, _0805BFC8 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #8
	cmp r0, #0
	blt _0805BFCC
	asrs r3, r0, #0xc
	b _0805BFD2
	.align 2, 0
_0805BFBC: .4byte 0x030046B8
_0805BFC0: .4byte 0x000003FF
_0805BFC4: .4byte 0x0203B400
_0805BFC8: .4byte 0x085B0A08
_0805BFCC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805BFD2:
	movs r0, #0
	strh r3, [r4]
	strh r0, [r4, #2]
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x80
	lsls r0, r0, #1
	muls r0, r1, r0
	cmp r0, #0
	blt _0805BFEE
	asrs r0, r0, #0xc
	b _0805BFF4
_0805BFEE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805BFF4:
	strh r0, [r4, #4]
	movs r0, #8
	ldrsb r0, [r5, r0]
	lsls r0, r0, #2
	mov r1, sb
	adds r1, #0x28
	adds r1, r1, r0
	adds r2, r5, #0
	adds r2, #0x1c
	ldr r1, [r1]
	mov r3, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r4, [r1]
	adds r0, r0, r4
	strh r0, [r5, #0x1c]
	ldrh r0, [r3, #2]
	ldrh r4, [r1, #2]
	adds r0, r0, r4
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	adds r7, r2, #0
_0805C026:
	movs r1, #0x1c
	ldrsh r0, [r5, r1]
	movs r2, #0x14
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r7, r3]
	movs r4, #0x18
	ldrsh r2, [r5, r4]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r5, #6]
	ldr r4, _0805C094 @ =0x0203B400
	ldr r2, _0805C098 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r3, _0805C09C @ =0x000003FF
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	subs r0, #0x20
	ldrb r1, [r5, #6]
	adds r0, r0, r1
	strb r0, [r5, #6]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x10
	strb r0, [r5, #7]
	adds r2, r5, #0
	adds r2, #0x7c
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_0805C084:
	mov r2, sb
	ldrb r1, [r2, #0x1c]
	cmp r1, #0
	beq _0805C0A0
	movs r0, #5
	movs r1, #0
	b _0805C0AA
	.align 2, 0
_0805C094: .4byte 0x0203B400
_0805C098: .4byte 0x030046B8
_0805C09C: .4byte 0x000003FF
_0805C0A0:
	mov r3, sb
	ldrb r0, [r3, #0x1e]
	cmp r0, #0
	beq _0805C0B4
	movs r0, #9
_0805C0AA:
	strb r0, [r5, #1]
	movs r0, #1
	strb r0, [r5]
	strh r1, [r5, #4]
	b _0805C320
_0805C0B4:
	ldrb r0, [r5, #7]
	cmp r0, #0
	beq _0805C0BC
	b _0805C210
_0805C0BC:
	ldr r6, _0805C110 @ =0x0203B400
	ldr r2, _0805C114 @ =0x030046B8
	ldr r0, [r2]
	adds r1, r0, #1
	ldr r3, _0805C118 @ =0x000003FF
	ands r1, r3
	str r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r6
	movs r4, #0xff
	ldrb r0, [r0]
	cmp r0, #0xbf
	ble _0805C0D8
	b _0805C1CC
_0805C0D8:
	movs r0, #8
	ldrsb r0, [r5, r0]
	adds r7, r5, #0
	adds r7, #0x1c
	cmp r0, #0
	blt _0805C180
	adds r0, r1, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r2, [r0]
	mov r3, sp
	ands r2, r4
	ldr r1, _0805C11C @ =0x085B0A08
	adds r0, r2, #0
	adds r0, #0x40
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #8
	cmp r0, #0
	blt _0805C120
	asrs r1, r0, #0xc
	b _0805C126
	.align 2, 0
_0805C110: .4byte 0x0203B400
_0805C114: .4byte 0x030046B8
_0805C118: .4byte 0x000003FF
_0805C11C: .4byte 0x085B0A08
_0805C120:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805C126:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _0805C144 @ =0x085B0A08
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #1
	muls r0, r1, r0
	cmp r0, #0
	blt _0805C148
	asrs r0, r0, #0xc
	b _0805C14E
	.align 2, 0
_0805C144: .4byte 0x085B0A08
_0805C148:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805C14E:
	strh r0, [r3, #4]
	movs r0, #8
	ldrsb r0, [r5, r0]
	lsls r0, r0, #2
	mov r1, sb
	adds r1, #0x28
	adds r1, r1, r0
	adds r2, r5, #0
	adds r2, #0x1c
	ldr r1, [r1]
	mov r3, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r4, [r1]
	adds r0, r0, r4
	strh r0, [r5, #0x1c]
	ldrh r0, [r3, #2]
	ldrh r4, [r1, #2]
	adds r0, r0, r4
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	adds r7, r2, #0
_0805C180:
	adds r4, r5, #0
	adds r4, #0x14
	movs r1, #0x1c
	ldrsh r0, [r5, r1]
	movs r2, #0x14
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r7, r3]
	movs r3, #4
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r5, #6]
	ldr r2, _0805C1C0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0805C1C4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0805C1C8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	subs r0, #0x20
	ldrb r2, [r5, #6]
	adds r0, r0, r2
	strb r0, [r5, #6]
	b _0805C1E4
	.align 2, 0
_0805C1C0: .4byte 0x030046B8
_0805C1C4: .4byte 0x000003FF
_0805C1C8: .4byte 0x0203B400
_0805C1CC:
	adds r0, r1, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0805C204 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	strb r0, [r5, #6]
	adds r7, r5, #0
	adds r7, #0x1c
	adds r4, r5, #0
	adds r4, #0x14
_0805C1E4:
	ldr r2, _0805C208 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0805C20C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0805C204 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x10
	strb r0, [r5, #7]
	b _0805C21C
	.align 2, 0
_0805C204: .4byte 0x0203B400
_0805C208: .4byte 0x030046B8
_0805C20C: .4byte 0x000003FF
_0805C210:
	subs r0, #1
	strb r0, [r5, #7]
	adds r7, r5, #0
	adds r7, #0x1c
	adds r4, r5, #0
	adds r4, #0x14
_0805C21C:
	mov r6, sp
	ldrb r2, [r5, #6]
	mov ip, r2
	ldrh r3, [r5, #0x10]
	mov r8, r3
	ldr r2, _0805C248 @ =0x085B0A08
	mov r0, ip
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r3, r8
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r2, #0
	cmp r0, #0
	blt _0805C24C
	asrs r3, r0, #0xc
	b _0805C252
	.align 2, 0
_0805C248: .4byte 0x085B0A08
_0805C24C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805C252:
	movs r0, #0
	strh r3, [r6]
	strh r0, [r6, #2]
	mov r2, ip
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _0805C270
	asrs r0, r0, #0xc
	b _0805C276
_0805C270:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805C276:
	movs r2, #0
	mov r8, r2
	strh r0, [r6, #4]
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r5, #0x14]
	adds r0, r0, r3
	strh r0, [r5, #0x14]
	ldrh r0, [r1, #2]
	ldrh r2, [r4, #2]
	adds r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r4, #4]
	adds r0, r0, r3
	strh r0, [r4, #4]
	adds r0, r5, #0
	adds r0, #0x7c
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	mov r0, sb
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0805bbb0
	movs r0, #0x1c
	ldrsh r2, [r5, r0]
	movs r1, #0x14
	ldrsh r0, [r5, r1]
	subs r2, r2, r0
	movs r3, #4
	ldrsh r0, [r7, r3]
	movs r3, #4
	ldrsh r1, [r4, r3]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	ldr r0, _0805C2E0 @ =0x00003FFF
	cmp r1, r0
	bgt _0805C2E4
	movs r0, #2
	strb r0, [r5, #1]
	movs r0, #1
	strb r0, [r5]
	movs r0, #0
	b _0805C31E
	.align 2, 0
_0805C2E0: .4byte 0x00003FFF
_0805C2E4:
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _0805C31A
	subs r0, #1
	strb r0, [r5, #9]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805C31A
	mov r1, sb
	ldrb r0, [r1, #0x1f]
	cmp r0, #2
	bne _0805C30C
	mov r2, sl
	cmp r2, #7
	bgt _0805C306
	movs r0, #1
	b _0805C318
_0805C306:
	mov r3, r8
	strb r3, [r5, #8]
	b _0805C31A
_0805C30C:
	cmp r0, #0
	bne _0805C316
	mov r4, r8
	strb r4, [r5, #8]
	b _0805C31A
_0805C316:
	movs r0, #0xff
_0805C318:
	strb r0, [r5, #8]
_0805C31A:
	ldrh r0, [r5, #4]
	adds r0, #1
_0805C31E:
	strh r0, [r5, #4]
_0805C320:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805c330
FUN_0805c330: @ 0x0805C330
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	adds r4, r1, #0
	mov r8, r2
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805C382
	movs r0, #0
	strb r0, [r4]
	ldr r3, _0805C390 @ =0x0203B400
	ldr r1, _0805C394 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0805C398 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	strb r0, [r4, #6]
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x10
	strb r0, [r4, #7]
	adds r2, r4, #0
	adds r2, #0x7c
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_0805C382:
	ldrb r1, [r7, #0x1c]
	cmp r1, #0
	beq _0805C39C
	movs r0, #5
	movs r1, #0
	b _0805C3A4
	.align 2, 0
_0805C390: .4byte 0x0203B400
_0805C394: .4byte 0x030046B8
_0805C398: .4byte 0x000003FF
_0805C39C:
	ldrb r0, [r7, #0x1e]
	cmp r0, #0
	beq _0805C3AE
	movs r0, #9
_0805C3A4:
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	strh r1, [r4, #4]
	b _0805C4B8
_0805C3AE:
	ldrb r0, [r4, #7]
	cmp r0, #0
	bne _0805C3EC
	ldr r3, _0805C3E0 @ =0x0203B400
	ldr r1, _0805C3E4 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0805C3E8 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	strb r0, [r4, #6]
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x10
	b _0805C3EE
	.align 2, 0
_0805C3E0: .4byte 0x0203B400
_0805C3E4: .4byte 0x030046B8
_0805C3E8: .4byte 0x000003FF
_0805C3EC:
	subs r0, #1
_0805C3EE:
	strb r0, [r4, #7]
	mov r3, sp
	ldrb r5, [r4, #6]
	ldrh r6, [r4, #0x10]
	ldr r2, _0805C414 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805C418
	asrs r1, r0, #0xc
	b _0805C41E
	.align 2, 0
_0805C414: .4byte 0x085B0A08
_0805C418:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805C41E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805C436
	asrs r0, r0, #0xc
	b _0805C43C
_0805C436:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805C43C:
	movs r5, #0
	strh r0, [r3, #4]
	adds r1, r4, #0
	adds r1, #0x14
	mov r2, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r4, #0x14]
	adds r0, r0, r3
	strh r0, [r4, #0x14]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0805bbb0
	ldrh r0, [r4, #4]
	cmp r0, #0x1f
	bls _0805C486
	movs r0, #2
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	movs r0, #0
	b _0805C4B6
_0805C486:
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _0805C4B2
	subs r0, #1
	strb r0, [r4, #9]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805C4B2
	ldrb r0, [r7, #0x1f]
	cmp r0, #2
	bne _0805C4A6
	mov r3, r8
	cmp r3, #7
	bgt _0805C4AA
	movs r0, #1
	b _0805C4B0
_0805C4A6:
	cmp r0, #0
	bne _0805C4AE
_0805C4AA:
	strb r5, [r4, #8]
	b _0805C4B2
_0805C4AE:
	movs r0, #0xff
_0805C4B0:
	strb r0, [r4, #8]
_0805C4B2:
	ldrh r0, [r4, #4]
	adds r0, #1
_0805C4B6:
	strh r0, [r4, #4]
_0805C4B8:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805c4c4
FUN_0805c4c4: @ 0x0805C4C4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	adds r6, r1, #0
	mov sb, r2
	ldrb r0, [r6]
	cmp r0, #0
	beq _0805C524
	movs r0, #0
	strb r0, [r6]
	adds r2, r6, #0
	adds r2, #0x7c
	subs r0, #5
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
	adds r3, r6, #0
	adds r3, #0x14
	ldr r0, [r6, #0x14]
	ldr r1, [r6, #0x18]
	str r0, [r6, #0x24]
	str r1, [r6, #0x28]
	movs r0, #8
	ldrsb r0, [r6, r0]
	cmp r0, #0
	blt _0805C524
	adds r1, r0, #0
	lsls r1, r1, #2
	adds r0, r7, #0
	adds r0, #0x28
	adds r0, r0, r1
	ldr r2, [r0]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r4, #0x14
	ldrsh r1, [r6, r4]
	subs r0, r0, r1
	movs r4, #4
	ldrsh r1, [r2, r4]
	movs r4, #4
	ldrsh r2, [r3, r4]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r6, #6]
_0805C524:
	ldrb r1, [r7, #0x1c]
	cmp r1, #0
	beq _0805C530
	movs r0, #5
	movs r1, #0
	b _0805C538
_0805C530:
	ldrb r0, [r7, #0x1e]
	cmp r0, #0
	beq _0805C542
	movs r0, #9
_0805C538:
	strb r0, [r6, #1]
	movs r0, #1
	strb r0, [r6]
	strh r1, [r6, #4]
	b _0805C636
_0805C542:
	ldrh r0, [r6, #4]
	cmp r0, #0xf
	bls _0805C54E
	ldrh r1, [r6, #4]
	movs r0, #0x20
	subs r0, r0, r1
_0805C54E:
	lsls r3, r0, #4
	mov r4, sp
	ldrb r5, [r6, #6]
	ldr r2, _0805C570 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _0805C574
	asrs r1, r0, #0xc
	b _0805C57A
	.align 2, 0
_0805C570: .4byte 0x085B0A08
_0805C574:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805C57A:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _0805C592
	asrs r0, r0, #0xc
	b _0805C598
_0805C592:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805C598:
	movs r3, #0
	mov r8, r3
	strh r0, [r4, #4]
	adds r4, r6, #0
	adds r4, #0x14
	adds r2, r6, #0
	adds r2, #0x24
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r6, #0x24]
	adds r0, r0, r3
	strh r0, [r6, #0x14]
	ldrh r0, [r1, #2]
	ldrh r3, [r2, #2]
	adds r0, r0, r3
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r4, #4]
	adds r5, r6, #0
	adds r5, #0x2c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r6, #0
	adds r0, #0x7c
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r5, #0
	bl Hitbox_Register
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_0805bbb0
	ldrh r0, [r6, #4]
	cmp r0, #0x1f
	bls _0805C5FE
	movs r0, #2
	strb r0, [r6, #1]
	movs r0, #1
	strb r0, [r6]
	movs r0, #0
	b _0805C634
_0805C5FE:
	ldrb r0, [r6, #9]
	cmp r0, #0
	beq _0805C630
	subs r0, #1
	strb r0, [r6, #9]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805C630
	ldrb r0, [r7, #0x1f]
	cmp r0, #2
	bne _0805C622
	mov r4, sb
	cmp r4, #7
	bgt _0805C61E
	movs r0, #1
	b _0805C62E
_0805C61E:
	mov r0, r8
	b _0805C62E
_0805C622:
	cmp r0, #0
	bne _0805C62C
	mov r1, r8
	strb r1, [r6, #8]
	b _0805C630
_0805C62C:
	movs r0, #0xff
_0805C62E:
	strb r0, [r6, #8]
_0805C630:
	ldrh r0, [r6, #4]
	adds r0, #1
_0805C634:
	strh r0, [r6, #4]
_0805C636:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805c644
FUN_0805c644: @ 0x0805C644
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	mov r8, r0
	adds r7, r1, #0
	ldrb r0, [r7]
	cmp r0, #0
	beq _0805C748
	movs r0, #0
	strb r0, [r7]
	ldr r2, _0805C68C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0805C690 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0805C694 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	mov r4, sp
	ldrb r5, [r0]
	ldr r1, _0805C698 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #5
	cmp r0, #0
	blt _0805C69C
	asrs r3, r0, #0xc
	b _0805C6A2
	.align 2, 0
_0805C68C: .4byte 0x030046B8
_0805C690: .4byte 0x000003FF
_0805C694: .4byte 0x0203B400
_0805C698: .4byte 0x085B0A08
_0805C69C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805C6A2:
	movs r0, #0
	strh r3, [r4]
	strh r0, [r4, #2]
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _0805C6BC
	asrs r0, r0, #0xc
	b _0805C6C2
_0805C6BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805C6C2:
	strh r0, [r4, #4]
	adds r2, r7, #0
	adds r2, #0x1c
	mov r3, r8
	adds r3, #0x30
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	mov r4, r8
	ldrh r4, [r4, #0x30]
	adds r0, r0, r4
	strh r0, [r7, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r5, [r3, #2]
	adds r0, r0, r5
	strh r0, [r2, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	movs r1, #0x1c
	ldrsh r0, [r7, r1]
	movs r3, #0x14
	ldrsh r1, [r7, r3]
	subs r0, r0, r1
	movs r4, #4
	ldrsh r1, [r2, r4]
	movs r5, #0x18
	ldrsh r2, [r7, r5]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r7, #6]
	ldr r4, _0805C758 @ =0x0203B400
	ldr r2, _0805C75C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r3, _0805C760 @ =0x000003FF
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x60
	ldrb r1, [r7, #6]
	adds r0, r0, r1
	strb r0, [r7, #6]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	adds r0, #0x20
	strb r0, [r7, #7]
	adds r2, r7, #0
	adds r2, #0x7c
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_0805C748:
	mov r2, r8
	ldrb r1, [r2, #0x1c]
	cmp r1, #0
	bne _0805C764
	movs r0, #1
	strb r0, [r7, #1]
	b _0805C80A
	.align 2, 0
_0805C758: .4byte 0x0203B400
_0805C75C: .4byte 0x030046B8
_0805C760: .4byte 0x000003FF
_0805C764:
	ldrb r0, [r7, #7]
	cmp r0, #0
	bne _0805C7D0
	adds r6, r7, #0
	adds r6, #0x14
	adds r5, r7, #0
	adds r5, #0x1c
	movs r3, #0x1c
	ldrsh r0, [r7, r3]
	movs r4, #0x14
	ldrsh r1, [r7, r4]
	subs r0, r0, r1
	movs r2, #4
	ldrsh r1, [r5, r2]
	movs r3, #4
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r7, #6]
	ldr r4, _0805C7C4 @ =0x0203B400
	ldr r2, _0805C7C8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r3, _0805C7CC @ =0x000003FF
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x60
	ldrb r1, [r7, #6]
	adds r0, r0, r1
	strb r0, [r7, #6]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	adds r0, #0x20
	strb r0, [r7, #7]
	b _0805C7DC
	.align 2, 0
_0805C7C4: .4byte 0x0203B400
_0805C7C8: .4byte 0x030046B8
_0805C7CC: .4byte 0x000003FF
_0805C7D0:
	subs r0, #1
	strb r0, [r7, #7]
	adds r5, r7, #0
	adds r5, #0x1c
	adds r6, r7, #0
	adds r6, #0x14
_0805C7DC:
	movs r3, #0x1c
	ldrsh r2, [r7, r3]
	movs r4, #0x14
	ldrsh r0, [r7, r4]
	subs r2, r2, r0
	movs r1, #4
	ldrsh r0, [r5, r1]
	movs r3, #4
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	ldr r0, _0805C810 @ =0x00000FFF
	cmp r1, r0
	bhi _0805C814
	movs r0, #7
	movs r1, #0
	strb r0, [r7, #1]
	movs r0, #1
_0805C80A:
	strb r0, [r7]
	strh r1, [r7, #4]
	b _0805C9A8
	.align 2, 0
_0805C810: .4byte 0x00000FFF
_0805C814:
	ldr r0, _0805C848 @ =0x0000FFFF
	cmp r1, r0
	bhi _0805C898
	ldrb r0, [r7, #6]
	add r5, sp, #8
	adds r4, r0, #0
	adds r4, #0x80
	movs r1, #5
	mov ip, r1
	ldr r2, _0805C84C @ =0x085B0A08
	adds r0, #0xc0
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	adds r1, r2, #0
	adds r2, r5, #0
	cmp r0, #0
	blt _0805C850
	asrs r3, r0, #0xc
	b _0805C856
	.align 2, 0
_0805C848: .4byte 0x0000FFFF
_0805C84C: .4byte 0x085B0A08
_0805C850:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805C856:
	movs r0, #0
	strh r3, [r5]
	strh r0, [r5, #2]
	movs r0, #0xff
	ands r4, r0
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r4, ip
	muls r4, r0, r4
	adds r0, r4, #0
	cmp r0, #0
	blt _0805C876
	asrs r0, r0, #0xc
	b _0805C87C
_0805C876:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805C87C:
	strh r0, [r5, #4]
	add r0, sp, #8
	ldrh r0, [r0]
	ldrh r5, [r7, #0x14]
	adds r0, r0, r5
	strh r0, [r7, #0x14]
	ldrh r0, [r2, #2]
	ldrh r1, [r6, #2]
	adds r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r6, #4]
	adds r0, r0, r2
	b _0805C98A
_0805C898:
	ldrh r0, [r7, #4]
	movs r1, #0x7f
	ands r1, r0
	cmp r1, #0x3f
	bgt _0805C912
	ldrb r0, [r7, #6]
	add r5, sp, #8
	adds r4, r0, #0
	adds r4, #0x80
	ldr r2, _0805C8C8 @ =0x085B0A08
	adds r0, #0xc0
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #3
	adds r1, r2, #0
	adds r2, r5, #0
	cmp r0, #0
	blt _0805C8CC
	asrs r3, r0, #0xc
	b _0805C8D2
	.align 2, 0
_0805C8C8: .4byte 0x085B0A08
_0805C8CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805C8D2:
	movs r0, #0
	strh r3, [r5]
	strh r0, [r5, #2]
	movs r0, #0xff
	ands r4, r0
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #8
	muls r0, r1, r0
	cmp r0, #0
	blt _0805C8F0
	asrs r0, r0, #0xc
	b _0805C8F6
_0805C8F0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805C8F6:
	strh r0, [r5, #4]
	add r0, sp, #8
	ldrh r0, [r0]
	ldrh r5, [r7, #0x14]
	adds r0, r0, r5
	strh r0, [r7, #0x14]
	ldrh r0, [r2, #2]
	ldrh r1, [r6, #2]
	adds r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r6, #4]
	adds r0, r0, r2
	b _0805C98A
_0805C912:
	cmp r1, #0x5f
	bgt _0805C98C
	add r4, sp, #8
	ldrb r5, [r7, #6]
	movs r3, #6
	mov ip, r3
	ldr r2, _0805C944 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r3, ip
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r2, #0
	adds r2, r4, #0
	cmp r0, #0
	blt _0805C948
	asrs r3, r0, #0xc
	b _0805C94E
	.align 2, 0
_0805C944: .4byte 0x085B0A08
_0805C948:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805C94E:
	movs r0, #0
	strh r3, [r4]
	strh r0, [r4, #2]
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _0805C96A
	asrs r0, r0, #0xc
	b _0805C970
_0805C96A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805C970:
	strh r0, [r4, #4]
	add r0, sp, #8
	ldrh r0, [r0]
	ldrh r3, [r7, #0x14]
	adds r0, r0, r3
	strh r0, [r7, #0x14]
	ldrh r0, [r2, #2]
	ldrh r4, [r6, #2]
	adds r0, r0, r4
	strh r0, [r6, #2]
	ldrh r0, [r2, #4]
	ldrh r5, [r6, #4]
	adds r0, r0, r5
_0805C98A:
	strh r0, [r6, #4]
_0805C98C:
	adds r0, r7, #0
	adds r0, #0x7c
	adds r1, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	mov r0, r8
	adds r1, r7, #0
	movs r2, #0
	bl FUN_0805bbb0
	ldrh r0, [r7, #4]
	adds r0, #1
	strh r0, [r7, #4]
_0805C9A8:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805c9b4
FUN_0805c9b4: @ 0x0805C9B4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805CA82
	movs r0, #0
	strb r0, [r4]
	ldr r2, _0805CA00 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0805CA04 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0805CA08 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	mov r5, sp
	ldrb r6, [r0]
	ldr r1, _0805CA0C @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #5
	adds r2, r1, #0
	cmp r0, #0
	blt _0805CA10
	asrs r3, r0, #0xc
	b _0805CA16
	.align 2, 0
_0805CA00: .4byte 0x030046B8
_0805CA04: .4byte 0x000003FF
_0805CA08: .4byte 0x0203B400
_0805CA0C: .4byte 0x085B0A08
_0805CA10:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805CA16:
	movs r0, #0
	strh r3, [r5]
	strh r0, [r5, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _0805CA30
	asrs r0, r0, #0xc
	b _0805CA36
_0805CA30:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805CA36:
	strh r0, [r5, #4]
	adds r2, r4, #0
	adds r2, #0x1c
	adds r3, r7, #0
	adds r3, #0x30
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r5, [r7, #0x30]
	adds r0, r0, r5
	strh r0, [r4, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r5, [r3, #2]
	adds r0, r0, r5
	strh r0, [r2, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	movs r1, #0x1c
	ldrsh r0, [r4, r1]
	movs r3, #0x14
	ldrsh r1, [r4, r3]
	subs r0, r0, r1
	movs r5, #4
	ldrsh r1, [r2, r5]
	movs r3, #0x18
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r4, #6]
	adds r2, r4, #0
	adds r2, #0x7c
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
_0805CA82:
	ldrb r1, [r7, #0x1c]
	cmp r1, #0
	bne _0805CA8E
	movs r0, #1
	strb r0, [r4, #1]
	b _0805CAC2
_0805CA8E:
	adds r3, r4, #0
	adds r3, #0x14
	movs r5, #0x1c
	ldrsh r2, [r4, r5]
	movs r1, #0x14
	ldrsh r0, [r4, r1]
	subs r2, r2, r0
	movs r5, #0x20
	ldrsh r0, [r4, r5]
	movs r5, #4
	ldrsh r1, [r3, r5]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _0805CAC8 @ =0x00000FFF
	adds r5, r3, #0
	cmp r1, r0
	bhi _0805CACC
	movs r0, #7
	movs r1, #0
	strb r0, [r4, #1]
	movs r0, #1
_0805CAC2:
	strb r0, [r4]
	strh r1, [r4, #4]
	b _0805CB6E
	.align 2, 0
_0805CAC8: .4byte 0x00000FFF
_0805CACC:
	add r3, sp, #8
	ldrb r6, [r4, #6]
	movs r0, #0x18
	mov ip, r0
	ldr r2, _0805CAF8 @ =0x085B0A08
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
	mov r8, r3
	cmp r0, #0
	blt _0805CAFC
	asrs r1, r0, #0xc
	b _0805CB02
	.align 2, 0
_0805CAF8: .4byte 0x085B0A08
_0805CAFC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805CB02:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _0805CB1E
	asrs r0, r0, #0xc
	b _0805CB24
_0805CB1E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805CB24:
	strh r0, [r3, #4]
	add r0, sp, #8
	ldrh r0, [r0]
	ldrh r2, [r4, #0x14]
	adds r0, r0, r2
	strh r0, [r4, #0x14]
	mov r3, r8
	ldrh r0, [r3, #2]
	ldrh r1, [r5, #2]
	adds r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r3, #4]
	ldrh r2, [r5, #4]
	adds r0, r0, r2
	strh r0, [r5, #4]
	adds r0, r4, #0
	adds r0, #0x7c
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #1
	bl FUN_0805bbb0
	ldrh r0, [r4, #4]
	cmp r0, #9
	bls _0805CB6A
	movs r0, #5
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	movs r0, #0
	b _0805CB6C
_0805CB6A:
	adds r0, #1
_0805CB6C:
	strh r0, [r4, #4]
_0805CB6E:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805cb7c
FUN_0805cb7c: @ 0x0805CB7C
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805CBCE
	movs r0, #0
	strb r0, [r4]
	movs r1, #0x1c
	ldrsh r0, [r4, r1]
	movs r2, #0x14
	ldrsh r1, [r4, r2]
	subs r0, r0, r1
	movs r3, #0x20
	ldrsh r1, [r4, r3]
	movs r5, #0x18
	ldrsh r2, [r4, r5]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r2, r4, #0
	adds r2, #0x7c
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, _0805CBE0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0805CBE4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0805CBE8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x10
	strb r0, [r4, #7]
_0805CBCE:
	ldrb r1, [r7, #0x1c]
	cmp r1, #0
	bne _0805CBEC
	movs r0, #1
	strb r0, [r4, #1]
	strb r0, [r4]
	strh r1, [r4, #4]
	b _0805CD00
	.align 2, 0
_0805CBE0: .4byte 0x030046B8
_0805CBE4: .4byte 0x000003FF
_0805CBE8: .4byte 0x0203B400
_0805CBEC:
	ldrb r0, [r4, #7]
	cmp r0, #0
	bne _0805CC2C
	ldr r3, _0805CC20 @ =0x0203B400
	ldr r1, _0805CC24 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0805CC28 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	strb r0, [r4, #6]
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x10
	b _0805CC2E
	.align 2, 0
_0805CC20: .4byte 0x0203B400
_0805CC24: .4byte 0x030046B8
_0805CC28: .4byte 0x000003FF
_0805CC2C:
	subs r0, #1
_0805CC2E:
	strb r0, [r4, #7]
	adds r3, r4, #0
	adds r3, #0x14
	movs r5, #0x1c
	ldrsh r2, [r4, r5]
	movs r1, #0x14
	ldrsh r0, [r4, r1]
	subs r2, r2, r0
	movs r5, #0x20
	ldrsh r0, [r4, r5]
	movs r5, #4
	ldrsh r1, [r3, r5]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r6, r1, r0
	ldrh r1, [r4, #0x16]
	movs r5, #0x16
	ldrsh r0, [r4, r5]
	movs r5, #0x1e
	ldrsh r2, [r4, r5]
	adds r5, r3, #0
	cmp r0, r2
	ble _0805CC68
	subs r0, r1, #1
	b _0805CC6E
_0805CC68:
	cmp r0, r2
	bge _0805CC70
	adds r0, r1, #1
_0805CC6E:
	strh r0, [r4, #0x16]
_0805CC70:
	ldr r0, _0805CC98 @ =0x00000FFF
	cmp r6, r0
	bhi _0805CCE4
	mov r3, sp
	ldrb r6, [r4, #6]
	ldr r2, _0805CC9C @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	cmp r0, #0
	blt _0805CCA0
	asrs r1, r0, #0xc
	b _0805CCA6
	.align 2, 0
_0805CC98: .4byte 0x00000FFF
_0805CC9C: .4byte 0x085B0A08
_0805CCA0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805CCA6:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #4
	muls r0, r1, r0
	cmp r0, #0
	blt _0805CCC0
	asrs r0, r0, #0xc
	b _0805CCC6
_0805CCC0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805CCC6:
	strh r0, [r3, #4]
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r4, #0x14]
	adds r0, r0, r3
	strh r0, [r4, #0x14]
	ldrh r0, [r1, #2]
	ldrh r2, [r5, #2]
	adds r0, r0, r2
	strh r0, [r5, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r5, #4]
	adds r0, r0, r3
	strh r0, [r5, #4]
_0805CCE4:
	adds r0, r4, #0
	adds r0, #0x7c
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0805bbb0
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
_0805CD00:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805cd08
FUN_0805cd08: @ 0x0805CD08
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	adds r5, r1, #0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0805CD32
	movs r0, #0
	strb r0, [r5]
	adds r2, r5, #0
	adds r2, #0x7c
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, #0x2a
	bl Video_SetAuxSpritePltt
_0805CD32:
	ldrh r1, [r5, #4]
	movs r0, #0x14
	subs r0, r0, r1
	mov r3, sp
	ldrb r4, [r5, #6]
	lsls r6, r0, #1
	ldr r2, _0805CD5C @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805CD60
	asrs r1, r0, #0xc
	b _0805CD66
	.align 2, 0
_0805CD5C: .4byte 0x085B0A08
_0805CD60:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805CD66:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805CD7E
	asrs r0, r0, #0xc
	b _0805CD84
_0805CD7E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805CD84:
	strh r0, [r3, #4]
	adds r1, r5, #0
	adds r1, #0x14
	mov r2, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r5, #0x14]
	adds r0, r0, r3
	strh r0, [r5, #0x14]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #1
	bl FUN_0805bbb0
	ldrh r0, [r5, #4]
	cmp r0, #0x13
	bls _0805CDD0
	movs r0, #1
	strb r0, [r5, #1]
	strb r0, [r5]
	movs r0, #0
	strh r0, [r5, #4]
	adds r2, r5, #0
	adds r2, #0xdc
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	b _0805CE1E
_0805CDD0:
	cmp r0, #6
	bne _0805CDE8
	movs r3, #0x84
	lsls r3, r3, #1
	adds r4, r5, r3
	adds r0, r4, #0
	ldr r1, _0805CE04 @ =0x00000263
	bl Video_SetAuxSpritePltt
	ldr r1, _0805CE08 @ =0x00001688
	adds r0, r7, r1
	str r0, [r4, #0xc]
_0805CDE8:
	ldrh r0, [r5, #4]
	lsrs r0, r0, #2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0805CE0C
	adds r0, r5, #0
	adds r0, #0xdc
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _0805CE16
	.align 2, 0
_0805CE04: .4byte 0x00000263
_0805CE08: .4byte 0x00001688
_0805CE0C:
	adds r0, r5, #0
	adds r0, #0xdc
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_0805CE16:
	str r1, [r0]
	ldrh r0, [r5, #4]
	adds r0, #1
	strh r0, [r5, #4]
_0805CE1E:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805ce28
FUN_0805ce28: @ 0x0805CE28
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	mov r8, r0
	adds r7, r1, #0
	ldrb r0, [r7]
	cmp r0, #0
	bne _0805CE3C
	b _0805CF40
_0805CE3C:
	movs r0, #0
	strb r0, [r7]
	adds r2, r7, #0
	adds r2, #0x7c
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r4, _0805CE90 @ =0x0203B400
	ldr r3, _0805CE94 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _0805CE98 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r6, #0xff
	ldrb r5, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	movs r0, #0x3f
	ands r1, r0
	mov r4, sp
	adds r2, r1, #0
	adds r2, #0x10
	ldr r1, _0805CE9C @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	ands r0, r6
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r2, r0
	cmp r0, #0
	blt _0805CEA0
	asrs r3, r0, #0xc
	b _0805CEA6
	.align 2, 0
_0805CE90: .4byte 0x0203B400
_0805CE94: .4byte 0x030046B8
_0805CE98: .4byte 0x000003FF
_0805CE9C: .4byte 0x085B0A08
_0805CEA0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805CEA6:
	movs r0, #0
	strh r3, [r4]
	strh r0, [r4, #2]
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r2, r0
	cmp r0, #0
	blt _0805CEBE
	asrs r0, r0, #0xc
	b _0805CEC4
_0805CEBE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805CEC4:
	strh r0, [r4, #4]
	adds r2, r7, #0
	adds r2, #0x1c
	mov r3, r8
	adds r3, #0x38
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	mov r4, r8
	ldrh r4, [r4, #0x38]
	adds r0, r0, r4
	strh r0, [r7, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r5, [r3, #2]
	adds r0, r0, r5
	strh r0, [r2, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	movs r1, #0x1c
	ldrsh r0, [r7, r1]
	movs r3, #0x14
	ldrsh r1, [r7, r3]
	subs r0, r0, r1
	movs r4, #4
	ldrsh r1, [r2, r4]
	movs r5, #0x18
	ldrsh r2, [r7, r5]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r7, #6]
	ldr r4, _0805CF58 @ =0x0203B400
	ldr r2, _0805CF5C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r3, _0805CF60 @ =0x000003FF
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	subs r0, #8
	ldrb r1, [r7, #6]
	adds r0, r0, r1
	strb r0, [r7, #6]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #8
	strb r0, [r7, #7]
	movs r0, #0x10
	strh r0, [r7, #0x10]
_0805CF40:
	mov r2, r8
	ldrb r0, [r2, #0x1c]
	cmp r0, #0
	beq _0805CF64
	movs r0, #5
	movs r1, #0
	strb r0, [r7, #1]
	movs r0, #1
	strb r0, [r7]
	strh r1, [r7, #4]
	b _0805D092
	.align 2, 0
_0805CF58: .4byte 0x0203B400
_0805CF5C: .4byte 0x030046B8
_0805CF60: .4byte 0x000003FF
_0805CF64:
	ldrb r0, [r7, #7]
	cmp r0, #0
	bne _0805CFCC
	adds r5, r7, #0
	adds r5, #0x14
	movs r3, #0x1c
	ldrsh r0, [r7, r3]
	movs r4, #0x14
	ldrsh r1, [r7, r4]
	subs r0, r0, r1
	movs r2, #0x20
	ldrsh r1, [r7, r2]
	movs r3, #4
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r7, #6]
	ldr r4, _0805CFC0 @ =0x0203B400
	ldr r2, _0805CFC4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r3, _0805CFC8 @ =0x000003FF
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	subs r0, #1
	ldrb r1, [r7, #6]
	adds r0, r0, r1
	strb r0, [r7, #6]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #8
	strb r0, [r7, #7]
	b _0805CFD4
	.align 2, 0
_0805CFC0: .4byte 0x0203B400
_0805CFC4: .4byte 0x030046B8
_0805CFC8: .4byte 0x000003FF
_0805CFCC:
	subs r0, #1
	strb r0, [r7, #7]
	adds r5, r7, #0
	adds r5, #0x14
_0805CFD4:
	mov r4, sp
	ldrb r6, [r7, #6]
	ldrh r2, [r7, #0x10]
	mov ip, r2
	ldr r2, _0805D000 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	adds r1, r2, #0
	cmp r0, #0
	blt _0805D004
	asrs r3, r0, #0xc
	b _0805D00A
	.align 2, 0
_0805D000: .4byte 0x085B0A08
_0805D004:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805D00A:
	movs r0, #0
	strh r3, [r4]
	strh r0, [r4, #2]
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r3, ip
	muls r3, r0, r3
	adds r0, r3, #0
	cmp r0, #0
	blt _0805D026
	asrs r0, r0, #0xc
	b _0805D02C
_0805D026:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805D02C:
	strh r0, [r4, #4]
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r4, [r7, #0x14]
	adds r0, r0, r4
	strh r0, [r7, #0x14]
	ldrh r0, [r1, #2]
	ldrh r2, [r5, #2]
	adds r0, r0, r2
	strh r0, [r5, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r5, #4]
	adds r0, r0, r3
	strh r0, [r5, #4]
	mov r0, r8
	adds r1, r7, #0
	movs r2, #0
	bl FUN_0805bbb0
	mov r4, r8
	movs r0, #0x38
	ldrsh r2, [r4, r0]
	movs r1, #0x14
	ldrsh r0, [r7, r1]
	subs r2, r2, r0
	movs r3, #0x3c
	ldrsh r0, [r4, r3]
	movs r4, #4
	ldrsh r1, [r5, r4]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r5, r0, #0
	muls r5, r0, r5
	adds r0, r5, #0
	adds r1, r1, r0
	ldr r0, _0805D088 @ =0x00003FFF
	cmp r1, r0
	bgt _0805D08C
	movs r0, #0xa
	strb r0, [r7, #1]
	movs r0, #1
	strb r0, [r7]
	movs r0, #0
	b _0805D090
	.align 2, 0
_0805D088: .4byte 0x00003FFF
_0805D08C:
	ldrh r0, [r7, #4]
	adds r0, #1
_0805D090:
	strh r0, [r7, #4]
_0805D092:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805d0a0
FUN_0805d0a0: @ 0x0805D0A0
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805D0BC
	movs r0, #0
	strb r0, [r4]
	adds r2, r4, #0
	adds r2, #0x7c
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
_0805D0BC:
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0805bbb0
	ldrb r1, [r5, #0x1d]
	cmp r1, #0
	beq _0805D0D2
	movs r0, #0xb
	movs r1, #0
	b _0805D0DA
_0805D0D2:
	ldrb r0, [r5, #0x1c]
	cmp r0, #0
	beq _0805D0E4
	movs r0, #5
_0805D0DA:
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	strh r1, [r4, #4]
	b _0805D0EA
_0805D0E4:
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
_0805D0EA:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805d0f0
FUN_0805d0f0: @ 0x0805D0F0
	push {r4, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805D10C
	movs r0, #0
	strb r0, [r4]
	adds r2, r4, #0
	adds r2, #0x7c
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
_0805D10C:
	adds r0, r3, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0805bbb0
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805d124
FUN_0805d124: @ 0x0805D124
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, [r5, #0x18]
	cmp r0, #0
	bne _0805D138
	b _0805D288
_0805D138:
	bl FUN_08084710
	strb r0, [r5, #0x1c]
	adds r0, r5, #0
	adds r0, #0x30
	bl FUN_08084734
	ldr r1, [r5, #0x24]
	ldr r0, _0805D188 @ =0x00000257
	cmp r1, r0
	bls _0805D166
	ldrb r0, [r5, #0x1e]
	cmp r0, #0
	bne _0805D15E
	movs r0, #1
	strb r0, [r5, #0x1e]
	movs r0, #0xea
	bl PlaySound_082406e0
_0805D15E:
	ldr r0, _0805D18C @ =0x00001684
	adds r1, r5, r0
	movs r0, #2
	strb r0, [r1]
_0805D166:
	ldr r1, _0805D18C @ =0x00001684
	adds r2, r5, r1
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	bne _0805D194
	ldr r3, _0805D190 @ =0x00001685
	adds r1, r5, r3
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x3e
	ble _0805D1CE
	movs r0, #0x3f
	b _0805D1C8
	.align 2, 0
_0805D188: .4byte 0x00000257
_0805D18C: .4byte 0x00001684
_0805D190: .4byte 0x00001685
_0805D194:
	cmp r0, #1
	bne _0805D1B0
	ldr r4, _0805D1AC @ =0x00001685
	adds r1, r5, r4
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bgt _0805D1CE
	movs r0, #0
	b _0805D1C8
	.align 2, 0
_0805D1AC: .4byte 0x00001685
_0805D1B0:
	cmp r0, #2
	bne _0805D1CE
	ldr r0, _0805D20C @ =0x00001685
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1f
	ble _0805D1CE
	movs r0, #0x20
_0805D1C8:
	strb r0, [r1]
	movs r0, #0xff
	strb r0, [r2]
_0805D1CE:
	ldr r1, _0805D210 @ =0x00001684
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0805D1FE
	ldr r0, _0805D214 @ =0x03003584
	ldr r2, [r0]
	ldr r3, _0805D218 @ =0x00004C60
	adds r1, r2, r3
	ldr r4, _0805D21C @ =0x00004CA0
	adds r2, r2, r4
	ldr r3, _0805D220 @ =0x00001688
	adds r0, r5, r3
	ldr r4, _0805D20C @ =0x00001685
	adds r3, r5, r4
	ldrb r3, [r3]
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	movs r4, #6
	str r4, [sp]
	bl BlendPltt
_0805D1FE:
	ldrb r0, [r5, #0x1d]
	cmp r0, #0
	beq _0805D224
	adds r0, r5, #0
	bl FUN_0805bb7c
	b _0805D288
	.align 2, 0
_0805D20C: .4byte 0x00001685
_0805D210: .4byte 0x00001684
_0805D214: .4byte 0x03003584
_0805D218: .4byte 0x00004C60
_0805D21C: .4byte 0x00004CA0
_0805D220: .4byte 0x00001688
_0805D224:
	movs r7, #0
	movs r0, #0
	mov r8, r0
	adds r4, r5, #0
	adds r4, #0x44
	movs r6, #0
	ldr r1, _0805D298 @ =0x085ABA2C
	mov sb, r1
_0805D234:
	ldrb r0, [r4, #1]
	lsls r0, r0, #2
	add r0, sb
	ldr r3, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl _call_via_r3
	adds r0, r4, #0
	bl FUN_0805bc0c
	ldrb r0, [r4, #1]
	cmp r0, #7
	bne _0805D254
	adds r7, #1
_0805D254:
	cmp r0, #0xa
	bne _0805D25C
	movs r3, #1
	add r8, r3
_0805D25C:
	adds r6, #1
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r4, r4, r0
	cmp r6, #0xf
	ble _0805D234
	ldr r1, [r5, #0x24]
	cmp r7, #0x10
	beq _0805D27A
	mov r3, r8
	cmp r3, #0x10
	beq _0805D27A
	ldr r0, _0805D29C @ =0x000004AF
	cmp r1, r0
	bls _0805D284
_0805D27A:
	ldrb r0, [r5, #0x1d]
	cmp r0, #0
	bne _0805D284
	movs r0, #1
	strb r0, [r5, #0x1d]
_0805D284:
	adds r0, r1, #1
	str r0, [r5, #0x24]
_0805D288:
	movs r0, #0
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805D298: .4byte 0x085ABA2C
_0805D29C: .4byte 0x000004AF

	thumb_func_start FUN_0805d2a0
FUN_0805d2a0: @ 0x0805D2A0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x44
	movs r4, #0
_0805D2AA:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805bb30
	adds r4, #1
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r5, r5, r0
	cmp r4, #0xf
	ble _0805D2AA
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805d2c8
FUN_0805d2c8: @ 0x0805D2C8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r2, #0
	movs r3, #0
	movs r0, #0xa
	strh r0, [r6, #0x20]
	movs r0, #0x64
	strh r0, [r6, #0x22]
	strb r2, [r6, #0x1d]
	str r3, [r6, #0x18]
	strb r1, [r6, #0x1f]
	ldr r0, _0805D348 @ =0x0000922E
	ldr r1, _0805D34C @ =0x00005BB7
	bl GetFile
	str r0, [r6, #0x40]
	ldr r0, _0805D350 @ =0x03003584
	ldr r2, [r0]
	ldr r0, _0805D354 @ =0x00004C60
	adds r1, r2, r0
	ldr r3, _0805D358 @ =0x00004CA0
	adds r2, r2, r3
	ldr r3, _0805D35C @ =0x00001688
	adds r0, r6, r3
	movs r3, #6
	str r3, [sp]
	movs r3, #0x40
	bl BlendPltt
	adds r4, r6, #0
	adds r4, #0x44
	movs r5, #0
_0805D30A:
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_0805b9b4
	adds r5, #1
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r4, r4, r0
	cmp r5, #0xf
	ble _0805D30A
	movs r5, #0
	ldrb r3, [r6, #0x1f]
	cmp r5, r3
	bge _0805D33C
	adds r1, r6, #0
	adds r1, #0x28
	ldr r2, _0805D360 @ =0x03002BE0
_0805D32E:
	ldm r2!, {r0}
	adds r0, #0x2c
	stm r1!, {r0}
	adds r5, #1
	ldrb r0, [r6, #0x1f]
	cmp r5, r0
	blt _0805D32E
_0805D33C:
	movs r0, #0
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805D348: .4byte 0x0000922E
_0805D34C: .4byte 0x00005BB7
_0805D350: .4byte 0x03003584
_0805D354: .4byte 0x00004C60
_0805D358: .4byte 0x00004CA0
_0805D35C: .4byte 0x00001688
_0805D360: .4byte 0x03002BE0

	thumb_func_start FUN_0805d364
FUN_0805d364: @ 0x0805D364
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _0805D394 @ =0x000016A8
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805D3A0
	ldr r1, _0805D398 @ =FUN_0805d124
	ldr r2, _0805D39C @ =FUN_0805d2a0
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0805d2c8
	cmp r0, #0
	bge _0805D3A0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805D3A2
	.align 2, 0
_0805D394: .4byte 0x000016A8
_0805D398: .4byte FUN_0805d124
_0805D39C: .4byte FUN_0805d2a0
_0805D3A0:
	adds r0, r4, #0
_0805D3A2:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805d3a8
FUN_0805d3a8: @ 0x0805D3A8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	str r1, [sp, #4]
	adds r4, r2, #0
	str r3, [sp, #8]
	movs r0, #0
	strb r0, [r6, #0x1c]
	strb r0, [r6, #0x1d]
	strb r0, [r6, #0x1e]
	str r0, [r6, #0x24]
	ldr r0, _0805D45C @ =0x00001684
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r2, _0805D460 @ =0x00001685
	adds r1, r6, r2
	movs r0, #0x3f
	strb r0, [r1]
	ldr r0, _0805D464 @ =0x03003584
	ldr r2, [r0]
	ldr r3, _0805D468 @ =0x00004C60
	adds r1, r2, r3
	ldr r0, _0805D46C @ =0x00004CA0
	adds r2, r2, r0
	ldr r3, _0805D470 @ =0x00001688
	adds r0, r6, r3
	movs r3, #6
	str r3, [sp]
	movs r3, #0x3f
	bl BlendPltt
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r6, #0x38]
	str r1, [r6, #0x3c]
	adds r5, r6, #0
	adds r5, #0x44
	movs r0, #0
	str r0, [sp, #0xc]
	mov sl, r0
	ldr r1, _0805D474 @ =0x030046B8
	mov r8, r1
	adds r7, r6, #0
	adds r7, #0xc0
_0805D40A:
	mov r2, sl
	strb r2, [r5, #1]
	movs r3, #1
	strb r3, [r5]
	mov r0, sl
	strh r0, [r5, #4]
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _0805D478 @ =0x000003FF
	ands r0, r1
	mov r2, r8
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0805D47C @ =0x0203B400
	adds r0, r0, r3
	ldrh r1, [r0]
	ldr r0, [sp, #0xc]
	lsls r2, r0, #5
	movs r0, #0x1f
	ands r1, r0
	adds r2, r2, r1
	strb r2, [r5, #6]
	mov r1, sp
	ldrh r1, [r1, #8]
	strh r1, [r5, #0x10]
	mov r2, sp
	ldrh r2, [r2, #0x30]
	strh r2, [r5, #0x12]
	ldrb r0, [r6, #0x1f]
	movs r3, #0xdc
	adds r3, r3, r5
	mov sb, r3
	cmp r0, #2
	bne _0805D486
	ldr r0, [sp, #0xc]
	cmp r0, #7
	bgt _0805D480
	movs r1, #1
	strb r1, [r5, #8]
	b _0805D494
	.align 2, 0
_0805D45C: .4byte 0x00001684
_0805D460: .4byte 0x00001685
_0805D464: .4byte 0x03003584
_0805D468: .4byte 0x00004C60
_0805D46C: .4byte 0x00004CA0
_0805D470: .4byte 0x00001688
_0805D474: .4byte 0x030046B8
_0805D478: .4byte 0x000003FF
_0805D47C: .4byte 0x0203B400
_0805D480:
	mov r2, sl
	strb r2, [r5, #8]
	b _0805D494
_0805D486:
	cmp r0, #0
	bne _0805D490
	mov r3, sl
	strb r3, [r5, #8]
	b _0805D494
_0805D490:
	movs r0, #0xff
	strb r0, [r5, #8]
_0805D494:
	mov r0, sl
	strb r0, [r5, #9]
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _0805D4D8 @ =0x000003FF
	ands r0, r1
	mov r2, r8
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0805D4DC @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	adds r4, r0, #0
	adds r4, #0x10
	ldr r2, _0805D4E0 @ =0x085B0A08
	ldrb r3, [r5, #6]
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	mov ip, r3
	cmp r0, #0
	blt _0805D4E4
	asrs r1, r0, #0xc
	b _0805D4EA
	.align 2, 0
_0805D4D8: .4byte 0x000003FF
_0805D4DC: .4byte 0x0203B400
_0805D4E0: .4byte 0x085B0A08
_0805D4E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805D4EA:
	ldr r3, [sp, #4]
	ldrh r0, [r3]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
	ldrh r0, [r3, #2]
	strh r0, [r5, #0x16]
	mov r1, ip
	lsls r0, r1, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _0805D50A
	asrs r2, r0, #0xc
	b _0805D510
_0805D50A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0805D510:
	ldr r3, [sp, #4]
	ldrh r0, [r3, #4]
	adds r0, r0, r2
	strh r0, [r5, #0x18]
	ldrh r0, [r5, #0x16]
	strh r0, [r5, #0xe]
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _0805D5C4 @ =0x000003FF
	ands r0, r1
	mov r2, r8
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0805D5C8 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #7
	strb r0, [r5, #7]
	adds r4, r5, #0
	adds r4, #0x14
	ldr r0, [r5, #0x14]
	ldr r1, [r5, #0x18]
	mov r2, sb
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldr r0, [r7, #0x60]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #0x60]
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0805bbb0
	movs r3, #0x84
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r1, _0805D5CC @ =0x00000263
	bl Video_SetAuxSpritePltt
	ldr r1, _0805D5D0 @ =0x00001688
	adds r0, r6, r1
	mov r2, sb
	str r0, [r2, #0x38]
	movs r3, #0x92
	lsls r3, r3, #1
	adds r0, r5, r3
	bl ParticleShadow_Show
	adds r0, r5, #0
	adds r0, #0x2c
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldrh r0, [r7, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r7, #6]
	ldr r0, [sp, #0xc]
	adds r0, #1
	str r0, [sp, #0xc]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r7, r7, r1
	adds r5, r5, r1
	cmp r0, #0xf
	bgt _0805D5AC
	b _0805D40A
_0805D5AC:
	movs r0, #1
	str r0, [r6, #0x18]
	movs r0, #0
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805D5C4: .4byte 0x000003FF
_0805D5C8: .4byte 0x0203B400
_0805D5CC: .4byte 0x00000263
_0805D5D0: .4byte 0x00001688

	thumb_func_start FUN_0805d5d4
FUN_0805d5d4: @ 0x0805D5D4
	movs r1, #0x96
	lsls r1, r1, #2
	str r1, [r0, #0x24]
	bx lr

	thumb_func_start FUN_0805d5dc
FUN_0805d5dc: @ 0x0805D5DC
	movs r0, #0x3c
	str r0, [r2]
	bx lr
	.align 2, 0

	thumb_func_start FUN_0805d5e4
FUN_0805d5e4: @ 0x0805D5E4
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x20
	adds r4, r0, #0
	adds r6, r1, #0
	movs r0, #0
	mov r8, r0
	stm r1!, {r0}
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	ldr r2, _0805D67C @ =0x05000002
	bl CpuSet
	adds r0, r6, #0
	adds r0, #0xc
	adds r4, #0x1c
	adds r1, r4, #0
	movs r2, #1
	bl AuxSprite_Setup
	adds r5, r6, #0
	adds r5, #0x38
	ldr r2, _0805D680 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r4, #8
	orrs r0, r4
	ldr r1, _0805D684 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x10]
	add r3, sp, #0x10
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r4
	str r0, [r3, #4]
	mov r0, r8
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _0805D688 @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	str r3, [sp, #4]
	str r1, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	ldr r1, _0805D68C @ =FUN_0805d5dc
	adds r0, r5, #0
	adds r2, r6, #0
	bl Hitbox_SetHandler
	mov r0, r8
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r1, #0xa
	movs r2, #0x14
	movs r3, #0
	bl Hitbox_SetAttack
	add sp, #0x20
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805D67C: .4byte 0x05000002
_0805D680: .4byte 0xFFFF0000
_0805D684: .4byte 0x0000FFFF
_0805D688: .4byte 0x00002001
_0805D68C: .4byte FUN_0805d5dc

	thumb_func_start FUN_0805d690
FUN_0805d690: @ 0x0805D690
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r0, r1, #0
	adds r5, r2, #0
	ldr r1, [r0, #0xc]
	movs r4, #1
	orrs r1, r4
	str r1, [r0, #0xc]
	adds r0, #0xc
	bl AuxSprite_Remove
	lsls r4, r5
	ldr r0, [r6, #0x18]
	bics r0, r4
	str r0, [r6, #0x18]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805d6b4
FUN_0805d6b4: @ 0x0805D6B4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	mov r6, r8
	adds r6, #0x38
	movs r7, #0
	adds r5, r6, #0
_0805D6C4:
	movs r1, #1
	lsls r1, r7
	mov r2, r8
	ldr r0, [r2, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _0805D716
	adds r4, r6, #0
	adds r4, #0x38
	adds r1, r6, #0
	adds r1, #0x28
	ldrh r0, [r5, #4]
	ldrh r2, [r5, #0x28]
	adds r0, r0, r2
	strh r0, [r5, #0x28]
	ldrh r0, [r5, #6]
	ldrh r2, [r5, #0x2a]
	adds r0, r0, r2
	strh r0, [r5, #0x2a]
	ldrh r0, [r5, #8]
	ldrh r2, [r5, #0x2c]
	adds r0, r0, r2
	strh r0, [r5, #0x2c]
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	ldr r0, [r5]
	cmp r0, #0x3b
	bls _0805D712
	mov r0, r8
	adds r1, r6, #0
	adds r2, r7, #0
	bl FUN_0805d690
	b _0805D716
_0805D712:
	adds r0, #1
	str r0, [r5]
_0805D716:
	adds r7, #1
	adds r5, #0x88
	adds r6, #0x88
	cmp r7, #0x1f
	ble _0805D6C4
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805d72c
FUN_0805d72c: @ 0x0805D72C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x38
	movs r4, #0
_0805D736:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _0805D74C
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805d690
_0805D74C:
	adds r4, #1
	adds r5, #0x88
	cmp r4, #0x1f
	ble _0805D736
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805d75c
FUN_0805d75c: @ 0x0805D75C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0
	str r0, [r6, #0x18]
	adds r4, r6, #0
	adds r4, #0x1c
	ldr r1, _0805D798 @ =0x0000848F
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r4, #0
	movs r1, #0xdb
	bl Video_SetAuxSpritePltt
	adds r5, r6, #0
	adds r5, #0x38
	movs r4, #0
_0805D77E:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805d5e4
	adds r4, #1
	adds r5, #0x88
	cmp r4, #0x1f
	ble _0805D77E
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805D798: .4byte 0x0000848F

	thumb_func_start FUN_0805d79c
FUN_0805d79c: @ 0x0805D79C
	push {r4, lr}
	ldr r1, _0805D7C8 @ =0x00001138
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805D7D4
	ldr r1, _0805D7CC @ =FUN_0805d6b4
	ldr r2, _0805D7D0 @ =FUN_0805d72c
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_0805d75c
	cmp r0, #0
	bge _0805D7D4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805D7D6
	.align 2, 0
_0805D7C8: .4byte 0x00001138
_0805D7CC: .4byte FUN_0805d6b4
_0805D7D0: .4byte FUN_0805d72c
_0805D7D4:
	adds r0, r4, #0
_0805D7D6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805d7dc
FUN_0805d7dc: @ 0x0805D7DC
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r3, #0x38
	movs r2, #0
	movs r5, #1
	ldr r4, [r0, #0x18]
_0805D7E8:
	adds r0, r5, #0
	lsls r0, r2
	ands r0, r4
	cmp r0, #0
	bne _0805D7F8
	str r2, [r1]
	adds r0, r3, #0
	b _0805D804
_0805D7F8:
	adds r2, #1
	adds r3, #0x88
	cmp r2, #0x1f
	ble _0805D7E8
	movs r0, #0
	str r0, [r1]
_0805D804:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805d80c
FUN_0805d80c: @ 0x0805D80C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	mov sb, r1
	adds r5, r2, #0
	adds r7, r3, #0
	adds r6, r0, #0
	add r1, sp, #8
	bl FUN_0805d7dc
	adds r3, r0, #0
	cmp r3, #0
	bne _0805D830
	movs r0, #1
	rsbs r0, r0, #0
	b _0805D90A
_0805D830:
	movs r0, #0x38
	adds r0, r0, r3
	mov r8, r0
	movs r0, #0
	adds r4, r3, #0
	stm r4!, {r0}
	ldr r2, _0805D858 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0805D85C
	asrs r1, r0, #0xc
	b _0805D862
	.align 2, 0
_0805D858: .4byte 0x085B0A08
_0805D85C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805D862:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _0805D87E
	asrs r0, r0, #0xc
	b _0805D884
_0805D87E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805D884:
	strh r0, [r4, #4]
	ldr r2, [sp, #0x28]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3, #0x28]
	str r1, [r3, #0x2c]
	adds r0, r5, #0
	adds r0, #0x60
	movs r1, #0xff
	ands r0, r1
	lsrs r2, r0, #4
	cmp r2, #8
	bls _0805D8AA
	movs r0, #0x10
	subs r0, r0, r2
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	movs r4, #1
	b _0805D8AC
_0805D8AA:
	movs r4, #0
_0805D8AC:
	adds r1, r3, #0
	adds r1, #0xc
	adds r0, r2, #4
	strh r0, [r1, #0x10]
	adds r2, r1, #0
	cmp r4, #0
	beq _0805D8C2
	ldr r0, [r3, #0xc]
	movs r1, #4
	orrs r0, r1
	b _0805D8CA
_0805D8C2:
	ldr r0, [r3, #0xc]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0805D8CA:
	str r0, [r3, #0xc]
	ldr r0, [r3, #0xc]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3, #0xc]
	adds r0, r2, #0
	movs r1, #0
	bl Video_AddAuxSpriteIntoDrawList
	movs r0, #0
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	mov r0, r8
	mov r1, sb
	movs r2, #0x14
	movs r3, #0
	bl Hitbox_SetAttack
	mov r0, r8
	ldr r1, [sp, #0x28]
	movs r2, #0
	bl Hitbox_SetPos
	ldr r0, [sp, #8]
	movs r1, #1
	lsls r1, r0
	ldr r0, [r6, #0x18]
	orrs r0, r1
	str r0, [r6, #0x18]
	movs r0, #0
_0805D90A:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805d918
FUN_0805d918: @ 0x0805D918
	bx lr
	.align 2, 0

	thumb_func_start FUN_0805d91c
FUN_0805d91c: @ 0x0805D91C
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x2c
	adds r4, r0, #0
	adds r6, r1, #0
	movs r0, #0
	mov r8, r0
	str r0, [r6, #4]
	add r5, sp, #0x14
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _0805D9C8 @ =0x05000002
	bl CpuSet
	adds r0, r6, #0
	adds r0, #0xc
	adds r4, #0x1c
	movs r1, #2
	str r1, [sp]
	mov r1, r8
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	str r5, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #1
	bl MainSprite_Setup
	adds r5, r6, #0
	adds r5, #0x6c
	ldr r2, _0805D9CC @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	movs r4, #0x60
	orrs r0, r4
	ldr r1, _0805D9D0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r3, sp, #0x1c
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r4
	str r0, [r3, #4]
	str r1, [sp, #0x24]
	add r1, sp, #0x24
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _0805D9D4 @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	str r3, [sp, #4]
	str r1, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	ldr r1, _0805D9D8 @ =FUN_0805d918
	adds r0, r5, #0
	adds r2, r6, #0
	bl Hitbox_SetHandler
	mov r0, r8
	str r0, [sp]
	movs r0, #0x40
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r1, #0x32
	movs r2, #0x40
	movs r3, #0
	bl Hitbox_SetAttack
	add sp, #0x2c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805D9C8: .4byte 0x05000002
_0805D9CC: .4byte 0xFFFF0000
_0805D9D0: .4byte 0x0000FFFF
_0805D9D4: .4byte 0x00002001
_0805D9D8: .4byte FUN_0805d918

	thumb_func_start FUN_0805d9dc
FUN_0805d9dc: @ 0x0805D9DC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r0, r1, #0
	adds r5, r2, #0
	ldr r1, [r0, #0x14]
	movs r4, #1
	orrs r1, r4
	str r1, [r0, #0x14]
	adds r0, #0xc
	bl MainSprite_Remove
	lsls r4, r5
	ldr r0, [r6, #0x18]
	bics r0, r4
	str r0, [r6, #0x18]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805da00
FUN_0805da00: @ 0x0805DA00
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	adds r2, r1, #0
	ldr r0, [r2, #4]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0805DAC0
	adds r6, r2, #0
	adds r6, #0xc
	ldr r4, _0805DA5C @ =0x0203B400
	ldr r3, _0805DA60 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _0805DA64 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	ldrh r5, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r1, r0
	mov r3, sp
	adds r4, r1, #0
	adds r4, #0x10
	ldr r2, _0805DA68 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0805DA6C
	asrs r1, r0, #0xc
	b _0805DA72
	.align 2, 0
_0805DA5C: .4byte 0x0203B400
_0805DA60: .4byte 0x030046B8
_0805DA64: .4byte 0x000003FF
_0805DA68: .4byte 0x085B0A08
_0805DA6C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805DA72:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0805DA8E
	asrs r0, r0, #0xc
	b _0805DA94
_0805DA8E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805DA94:
	strh r0, [r3, #4]
	mov r2, sp
	mov r1, sp
	ldrh r0, [r6, #0x20]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r6, #0x22]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r6, #0x24]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	adds r2, r7, #0
	adds r2, #0x3c
	movs r0, #0
	mov r1, sp
	bl FUN_080155e4
_0805DAC0:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805dac8
FUN_0805dac8: @ 0x0805DAC8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	adds r5, r7, #0
	adds r5, #0x64
	movs r0, #0
	mov r8, r0
	movs r0, #1
	mov sb, r0
_0805DAE0:
	mov r1, sb
	mov r0, r8
	lsls r1, r0
	ldr r0, [r7, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _0805DBEA
	adds r6, r5, #0
	adds r6, #0xc
	adds r2, r5, #0
	adds r2, #0x6c
	ldrb r4, [r5]
	cmp r4, #1
	beq _0805DB4C
	cmp r4, #1
	bgt _0805DB06
	cmp r4, #0
	beq _0805DB10
	b _0805DBDA
_0805DB06:
	cmp r4, #2
	beq _0805DB8A
	cmp r4, #3
	beq _0805DBB6
	b _0805DBDA
_0805DB10:
	adds r0, r7, #0
	adds r1, r5, #0
	bl FUN_0805da00
	ldr r0, [r5, #4]
	cmp r0, #0x1d
	bls _0805DBDA
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	str r4, [r5, #4]
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	adds r1, #0x1c
	movs r2, #0x2a
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #0xbc
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0805DBDA
_0805DB4C:
	ldrh r0, [r6, #0x14]
	cmp r0, #4
	bhi _0805DB5E
	adds r0, r7, #0
	adds r1, r5, #0
	str r2, [sp, #4]
	bl FUN_0805da00
	ldr r2, [sp, #4]
_0805DB5E:
	ldr r0, [r5, #4]
	cmp r0, #0xe
	bls _0805DB6A
	adds r0, r2, #0
	bl Hitbox_Register
_0805DB6A:
	ldrb r0, [r6, #0x1d]
	ands r4, r0
	cmp r4, #0
	beq _0805DBDA
	ldrb r0, [r5]
	adds r0, #1
	movs r1, #0
	strb r0, [r5]
	str r1, [r5, #4]
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	adds r1, #0x1c
	movs r2, #0x2b
	b _0805DBAE
_0805DB8A:
	adds r0, r2, #0
	bl Hitbox_Register
	ldr r1, [r5, #4]
	ldr r0, [r5, #8]
	cmp r1, r0
	blo _0805DBDA
	ldrb r0, [r5]
	adds r0, #1
	movs r1, #0
	strb r0, [r5]
	str r1, [r5, #4]
	movs r0, #6
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	adds r1, #0x1c
	movs r2, #0x2a
_0805DBAE:
	movs r3, #2
	bl MainSprite_SetAnim
	b _0805DBDA
_0805DBB6:
	ldrh r0, [r6, #0x14]
	cmp r0, #4
	bhi _0805DBC4
	adds r0, r7, #0
	adds r1, r5, #0
	bl FUN_0805da00
_0805DBC4:
	ldrb r1, [r6, #0x1d]
	mov r0, sb
	ands r0, r1
	cmp r0, #0
	beq _0805DBDA
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, r8
	bl FUN_0805d9dc
	b _0805DBEA
_0805DBDA:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r1, #0x1c
	bl MainSprite_AdvanceAnim
	ldr r0, [r5, #4]
	adds r0, #1
	str r0, [r5, #4]
_0805DBEA:
	movs r0, #1
	add r8, r0
	adds r5, #0xbc
	mov r0, r8
	cmp r0, #7
	bgt _0805DBF8
	b _0805DAE0
_0805DBF8:
	movs r0, #0
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805dc08
FUN_0805dc08: @ 0x0805DC08
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x64
	movs r4, #0
_0805DC12:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _0805DC28
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805d9dc
_0805DC28:
	adds r4, #1
	adds r5, #0xbc
	cmp r4, #7
	ble _0805DC12
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805dc38
FUN_0805dc38: @ 0x0805DC38
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r4, #0
	str r4, [r6, #0x18]
	ldr r0, _0805DC54 @ =0x0000CB05
	ldr r1, _0805DC58 @ =0x0000D3FA
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _0805DC5C
	movs r0, #1
	rsbs r0, r0, #0
	b _0805DCCC
	.align 2, 0
_0805DC54: .4byte 0x0000CB05
_0805DC58: .4byte 0x0000D3FA
_0805DC5C:
	adds r1, r6, #0
	adds r1, #0x1c
	adds r0, r2, #0
	ldm r0!, {r3, r5, r7}
	stm r1!, {r3, r5, r7}
	ldm r0!, {r3, r5, r7}
	stm r1!, {r3, r5, r7}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	adds r0, r6, #0
	adds r0, #0x1c
	adds r1, r2, #0
	bl OpenMainSpriteFile
	adds r0, r6, #0
	adds r0, #0x3c
	movs r1, #7
	strh r1, [r6, #0x3c]
	movs r1, #0xc0
	lsls r1, r1, #6
	strh r1, [r0, #2]
	movs r1, #0x40
	strh r1, [r0, #6]
	strh r4, [r0, #8]
	strh r4, [r0, #0xa]
	movs r1, #3
	strh r1, [r0, #0xc]
	strh r1, [r0, #0xe]
	strh r4, [r0, #0x10]
	strh r4, [r0, #0x12]
	strh r4, [r0, #0x14]
	adds r1, #0xfd
	strh r1, [r0, #0x16]
	movs r1, #0x80
	lsls r1, r1, #2
	strh r1, [r0, #0x18]
	strh r4, [r0, #0x1a]
	strh r4, [r0, #0x1c]
	strh r4, [r0, #0x1e]
	strh r1, [r0, #0x20]
	strh r4, [r0, #0x22]
	strh r4, [r0, #0x24]
	strh r4, [r0, #0x26]
	adds r5, r6, #0
	adds r5, #0x64
	movs r4, #0
_0805DCB8:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805d91c
	adds r4, #1
	adds r5, #0xbc
	cmp r4, #7
	ble _0805DCB8
	movs r0, #0
_0805DCCC:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805dcd4
FUN_0805dcd4: @ 0x0805DCD4
	push {r4, lr}
	ldr r1, _0805DD00 @ =0x00000644
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805DD0C
	ldr r1, _0805DD04 @ =FUN_0805dac8
	ldr r2, _0805DD08 @ =FUN_0805dc08
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_0805dc38
	cmp r0, #0
	bge _0805DD0C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805DD0E
	.align 2, 0
_0805DD00: .4byte 0x00000644
_0805DD04: .4byte FUN_0805dac8
_0805DD08: .4byte FUN_0805dc08
_0805DD0C:
	adds r0, r4, #0
_0805DD0E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805dd14
FUN_0805dd14: @ 0x0805DD14
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r3, #0x64
	movs r2, #0
	movs r5, #1
	ldr r4, [r0, #0x18]
_0805DD20:
	adds r0, r5, #0
	lsls r0, r2
	ands r0, r4
	cmp r0, #0
	bne _0805DD30
	str r2, [r1]
	adds r0, r3, #0
	b _0805DD3C
_0805DD30:
	adds r2, #1
	adds r3, #0xbc
	cmp r2, #7
	ble _0805DD20
	movs r0, #0
	str r0, [r1]
_0805DD3C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805dd44
FUN_0805dd44: @ 0x0805DD44
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	mov sl, r1
	adds r5, r2, #0
	mov sb, r3
	add r1, sp, #8
	bl FUN_0805dd14
	adds r6, r0, #0
	cmp r6, #0
	beq _0805DDCA
	adds r4, r6, #0
	adds r4, #0xc
	movs r0, #0x6c
	adds r0, r0, r6
	mov r8, r0
	movs r0, #0
	strb r0, [r6]
	str r0, [r6, #4]
	str r5, [r6, #8]
	adds r1, r7, #0
	adds r1, #0x1c
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0x2a
	movs r3, #2
	bl MainSprite_SetAnim
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6, #0x2c]
	str r1, [r6, #0x30]
	adds r0, r4, #0
	movs r1, #0
	bl Video_AddMainSpriteIntoDrawList
	movs r0, #0x80
	lsls r0, r0, #0xb
	str r0, [sp]
	movs r0, #0x40
	str r0, [sp, #4]
	mov r0, r8
	mov r1, sl
	movs r2, #0x40
	movs r3, #0
	bl Hitbox_SetAttack
	mov r0, r8
	mov r1, sb
	movs r2, #0
	bl Hitbox_SetPos
	ldr r0, [sp, #8]
	movs r1, #1
	lsls r1, r0
	ldr r0, [r7, #0x18]
	orrs r0, r1
	str r0, [r7, #0x18]
	movs r0, #0
	b _0805DDCE
_0805DDCA:
	movs r0, #1
	rsbs r0, r0, #0
_0805DDCE:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
