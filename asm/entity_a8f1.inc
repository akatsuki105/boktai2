	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a251c
FUN_080a251c: @ 0x080A251C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x29
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080A2542
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	adds r0, r4, #0
	adds r0, #0x28
	strb r2, [r0]
	b _080A25C0
_080A2542:
	ldrh r0, [r4, #0x2c]
	ldrh r1, [r4, #0x18]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x2e]
	ldrh r1, [r4, #0x1a]
	adds r0, r0, r1
	strh r0, [r4, #0x1a]
	ldrh r0, [r4, #0x30]
	ldrh r1, [r4, #0x1c]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	ldr r0, _080A2584 @ =0x00001C1E
	bl GetParticleGroup
	adds r1, r0, #0
	ldrb r2, [r5]
	lsrs r2, r2, #2
	movs r0, #1
	ands r2, r0
	adds r2, #2
	adds r0, r4, #0
	bl Particle_SetFrame
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	cmp r0, #0
	blt _080A2588
	asrs r0, r0, #4
	b _080A258E
	.align 2, 0
_080A2584: .4byte 0x00001C1E
_080A2588:
	rsbs r0, r0, #0
	asrs r0, r0, #4
	rsbs r0, r0, #0
_080A258E:
	strh r0, [r4, #0x2c]
	movs r0, #0x2e
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	cmp r0, #0
	blt _080A25A0
	asrs r0, r0, #4
	b _080A25A6
_080A25A0:
	rsbs r0, r0, #0
	asrs r0, r0, #4
	rsbs r0, r0, #0
_080A25A6:
	strh r0, [r4, #0x2e]
	movs r0, #0x30
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	cmp r0, #0
	blt _080A25B8
	asrs r0, r0, #4
	b _080A25BE
_080A25B8:
	rsbs r0, r0, #0
	asrs r0, r0, #4
	rsbs r0, r0, #0
_080A25BE:
	strh r0, [r4, #0x30]
_080A25C0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a25c8
FUN_080a25c8: @ 0x080A25C8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [r0, #0x18]
	str r2, [r0, #0x1c]
	ldr r6, _080A266C @ =0x0203B400
	ldr r1, _080A2670 @ =0x030046B8
	mov sb, r1
	ldr r2, [r1]
	adds r2, #1
	ldr r4, _080A2674 @ =0x000003FF
	ands r2, r4
	lsls r1, r2, #1
	adds r1, r1, r6
	ldrh r3, [r1]
	ldrh r1, [r0, #0x18]
	subs r1, #0xf
	movs r5, #0x1f
	ands r3, r5
	adds r1, r1, r3
	movs r3, #0
	mov r8, r3
	strh r1, [r0, #0x18]
	adds r2, #1
	ands r2, r4
	lsls r3, r2, #1
	adds r3, r3, r6
	movs r7, #0xc0
	lsls r7, r7, #2
	adds r1, r7, #0
	ldrh r7, [r0, #0x1a]
	adds r1, r1, r7
	ldrb r3, [r3]
	adds r1, r1, r3
	strh r1, [r0, #0x1a]
	adds r2, #1
	ands r2, r4
	lsls r1, r2, #1
	adds r1, r1, r6
	ldrh r3, [r1]
	ldrh r1, [r0, #0x1c]
	subs r1, #0xf
	ands r3, r5
	adds r1, r1, r3
	strh r1, [r0, #0x1c]
	adds r3, r0, #0
	adds r3, #0x29
	movs r1, #0x18
	strb r1, [r3]
	mov r1, r8
	strh r1, [r0, #0x2c]
	adds r2, #1
	ands r2, r4
	mov r3, sb
	str r2, [r3]
	lsls r2, r2, #1
	adds r2, r2, r6
	ldrh r1, [r2]
	ands r1, r5
	adds r1, #0x20
	rsbs r1, r1, #0
	strh r1, [r0, #0x2e]
	mov r7, r8
	strh r7, [r0, #0x30]
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	adds r0, #0x28
	movs r1, #1
	strb r1, [r0]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A266C: .4byte 0x0203B400
_080A2670: .4byte 0x030046B8
_080A2674: .4byte 0x000003FF

	thumb_func_start FUN_080a2678
FUN_080a2678: @ 0x080A2678
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [r0, #0x18]
	str r2, [r0, #0x1c]
	ldr r6, _080A2710 @ =0x0203B400
	ldr r1, _080A2714 @ =0x030046B8
	mov sb, r1
	ldr r3, [r1]
	adds r3, #1
	ldr r4, _080A2718 @ =0x000003FF
	ands r3, r4
	lsls r1, r3, #1
	adds r1, r1, r6
	ldrh r2, [r1]
	ldrh r1, [r0, #0x18]
	subs r1, #0xf
	movs r5, #0x1f
	ands r2, r5
	adds r1, r1, r2
	movs r2, #0
	mov r8, r2
	strh r1, [r0, #0x18]
	adds r3, #1
	ands r3, r4
	lsls r2, r3, #1
	adds r2, r2, r6
	ldrh r1, [r0, #0x1a]
	ldrb r2, [r2]
	adds r1, r1, r2
	strh r1, [r0, #0x1a]
	adds r3, #1
	ands r3, r4
	lsls r1, r3, #1
	adds r1, r1, r6
	ldrh r2, [r1]
	ldrh r1, [r0, #0x1c]
	subs r1, #0xf
	ands r2, r5
	adds r1, r1, r2
	strh r1, [r0, #0x1c]
	adds r2, r0, #0
	adds r2, #0x29
	movs r1, #0x18
	strb r1, [r2]
	mov r1, r8
	strh r1, [r0, #0x2c]
	adds r3, #1
	ands r3, r4
	mov r2, sb
	str r3, [r2]
	lsls r3, r3, #1
	adds r3, r3, r6
	ldrh r1, [r3]
	ands r1, r5
	adds r1, #0x18
	strh r1, [r0, #0x2e]
	mov r1, r8
	strh r1, [r0, #0x30]
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	adds r0, #0x28
	movs r1, #1
	strb r1, [r0]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A2710: .4byte 0x0203B400
_080A2714: .4byte 0x030046B8
_080A2718: .4byte 0x000003FF

	thumb_func_start FUN_080a271c
FUN_080a271c: @ 0x080A271C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080A276C @ =0x030046A0
	ldr r3, [r0]
	movs r0, #0x30
	ldrsh r1, [r3, r0]
	adds r0, r4, #0
	adds r0, #0x98
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r2, r1, r0
	cmp r2, #0
	bge _080A2738
	rsbs r2, r2, #0
_080A2738:
	movs r1, #0x34
	ldrsh r0, [r3, r1]
	adds r1, r4, #0
	adds r1, #0x9c
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r1, r0, r1
	cmp r1, #0
	bge _080A274C
	rsbs r1, r1, #0
_080A274C:
	cmp r2, #0x60
	bgt _080A2770
	cmp r1, #0x60
	bgt _080A2770
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	movs r1, #0x90
	lsls r1, r1, #6
	cmp r0, r1
	bgt _080A2770
	movs r0, #1
	b _080A2772
	.align 2, 0
_080A276C: .4byte 0x030046A0
_080A2770:
	movs r0, #0
_080A2772:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a2778
FUN_080a2778: @ 0x080A2778
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080865c0
	adds r3, r0, #0
	cmp r3, #0
	beq _080A27FC
	ldr r0, _080A27F0 @ =0x03002C00
	ldr r1, [r0]
	ldrb r0, [r1, #0x1a]
	cmp r0, #4
	bne _080A27FC
	ldr r2, _080A27F4 @ =0x000001F5
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #4
	bhi _080A27FC
	movs r0, #2
	ldrsh r1, [r3, r0]
	adds r0, r4, #0
	adds r0, #0x9a
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _080A27AE
	rsbs r1, r1, #0
_080A27AE:
	cmp r1, #0xff
	bgt _080A27FC
	movs r0, #0
	ldrsh r1, [r3, r0]
	adds r0, r4, #0
	adds r0, #0x98
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r2, r1, r0
	movs r0, #4
	ldrsh r1, [r3, r0]
	adds r0, r4, #0
	adds r0, #0x9c
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r1, r1, r0
	movs r0, #0xbe
	lsls r0, r0, #1
	cmp r2, r0
	bgt _080A27FC
	cmp r1, r0
	bgt _080A27FC
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	ldr r1, _080A27F8 @ =0x00023410
	cmp r0, r1
	bgt _080A27FC
	movs r0, #1
	b _080A27FE
	.align 2, 0
_080A27F0: .4byte 0x03002C00
_080A27F4: .4byte 0x000001F5
_080A27F8: .4byte 0x00023410
_080A27FC:
	movs r0, #0
_080A27FE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a2804
FUN_080a2804: @ 0x080A2804
	push {r4, r5, lr}
	adds r3, r0, #0
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r4, r3, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _080A2816
	b _080A29E8
_080A2816:
	cmp r0, #2
	bhi _080A2864
	adds r2, r3, #0
	adds r2, #0xe8
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	subs r2, #0x4e
	ldrh r1, [r4]
	movs r0, #2
	subs r0, r0, r1
	movs r1, #0xab
	muls r0, r1, r0
	ldr r1, _080A2860 @ =0x00000402
	adds r0, r0, r1
	ldrh r2, [r2]
	adds r0, r0, r2
	movs r2, #0x83
	lsls r2, r2, #1
	adds r1, r3, r2
	strh r0, [r1]
	movs r4, #0x8a
	lsls r4, r4, #1
	adds r1, r3, r4
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r5, #0xa0
	lsls r5, r5, #1
	adds r1, r3, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _080A28C4
	.align 2, 0
_080A2860: .4byte 0x00000402
_080A2864:
	cmp r0, #4
	bhi _080A28D4
	adds r1, r3, #0
	adds r1, #0xe8
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r0, #0x9a
	adds r0, r0, r3
	mov ip, r0
	ldr r1, _080A28D0 @ =0x00000402
	adds r0, r1, #0
	mov r5, ip
	ldrh r5, [r5]
	adds r0, r0, r5
	movs r5, #0x83
	lsls r5, r5, #1
	adds r1, r3, r5
	strh r0, [r1]
	movs r0, #0x8a
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldrh r1, [r4]
	movs r0, #4
	subs r0, r0, r1
	movs r1, #0xab
	muls r0, r1, r0
	movs r1, #0xab
	lsls r1, r1, #2
	adds r0, r0, r1
	mov r2, ip
	ldrh r2, [r2]
	adds r0, r0, r2
	movs r4, #0x99
	lsls r4, r4, #1
	adds r1, r3, r4
	strh r0, [r1]
	adds r5, #0x3a
	adds r2, r3, r5
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
_080A28C4:
	adds r0, r3, #0
	adds r0, #0x4e
	ldrh r1, [r0]
	adds r0, #2
	strh r1, [r0, #0x10]
	b _080A2A0C
	.align 2, 0
_080A28D0: .4byte 0x00000402
_080A28D4:
	cmp r0, #6
	bhi _080A2960
	adds r1, r3, #0
	adds r1, #0xe8
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r0, #0x9a
	adds r0, r0, r3
	mov ip, r0
	ldr r1, _080A295C @ =0x00000402
	adds r0, r1, #0
	mov r5, ip
	ldrh r5, [r5]
	adds r0, r0, r5
	movs r5, #0x83
	lsls r5, r5, #1
	adds r1, r3, r5
	strh r0, [r1]
	movs r0, #0x8a
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r1, #0xab
	lsls r1, r1, #2
	adds r0, r1, #0
	mov r5, ip
	ldrh r5, [r5]
	adds r0, r0, r5
	movs r5, #0x99
	lsls r5, r5, #1
	adds r1, r3, r5
	strh r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldrh r1, [r4]
	movs r0, #6
	subs r0, r0, r1
	movs r1, #0xab
	muls r0, r1, r0
	adds r1, #0xab
	adds r0, r0, r1
	mov r2, ip
	ldrh r2, [r2]
	adds r0, r0, r2
	movs r4, #0xaf
	lsls r4, r4, #1
	adds r1, r3, r4
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x4e
	ldrh r1, [r0]
	adds r0, #2
	strh r1, [r0, #0x10]
	adds r1, r3, #0
	adds r1, #0x57
	movs r0, #3
	strb r0, [r1]
	b _080A2A0C
	.align 2, 0
_080A295C: .4byte 0x00000402
_080A2960:
	adds r1, r3, #0
	adds r1, #0xe8
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r5, #0x9a
	adds r5, r5, r3
	mov ip, r5
	ldr r1, _080A29E4 @ =0x00000402
	adds r0, r1, #0
	ldrh r4, [r5]
	adds r0, r0, r4
	movs r5, #0x83
	lsls r5, r5, #1
	adds r1, r3, r5
	strh r0, [r1]
	movs r0, #0x8a
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r1, #0xab
	lsls r1, r1, #2
	adds r0, r1, #0
	mov r4, ip
	ldrh r4, [r4]
	adds r0, r0, r4
	adds r5, #0x2c
	adds r1, r3, r5
	strh r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r1, #0xab
	lsls r1, r1, #1
	adds r0, r1, #0
	mov r2, ip
	ldrh r2, [r2]
	adds r0, r0, r2
	movs r4, #0xaf
	lsls r4, r4, #1
	adds r1, r3, r4
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x4e
	ldrh r0, [r0]
	adds r1, r3, #0
	adds r1, #0x50
	adds r0, #8
	strh r0, [r1, #0x10]
	ldr r0, [r3, #0x50]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r3, #0x50]
	adds r1, r3, #0
	adds r1, #0x57
	movs r0, #1
	strb r0, [r1]
	b _080A2A0C
	.align 2, 0
_080A29E4: .4byte 0x00000402
_080A29E8:
	adds r1, r3, #0
	adds r1, #0xe8
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r5, #0x8a
	lsls r5, r5, #1
	adds r1, r3, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_080A2A0C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a2a14
FUN_080a2a14: @ 0x080A2A14
	movs r3, #0xe1
	lsls r3, r3, #2
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _080A2A28 @ =0x00000382
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_080A2A28: .4byte 0x00000382

	thumb_func_start FUN_080a2a2c
FUN_080a2a2c: @ 0x080A2A2C
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x50]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #0x50]
	adds r0, r2, #0
	adds r0, #0x7c
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r1, r2, r3
	ldrh r1, [r1]
	bl Video_SetAuxSpritePltt
	pop {r0}
	bx r0

	thumb_func_start FUN_080a2a4c
FUN_080a2a4c: @ 0x080A2A4C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080A2A88 @ =0x00000382
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	bne _080A2A68
	movs r0, #0xcc
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_080A2A68:
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #7
	bhi _080A2A78
	adds r0, #1
	strh r0, [r1]
_080A2A78:
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0x16
	bhi _080A2A8C
	adds r0, #2
	b _080A2A8E
	.align 2, 0
_080A2A88: .4byte 0x00000382
_080A2A8C:
	movs r0, #0x18
_080A2A8E:
	strb r0, [r1]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r2, r4, r1
	ldrb r0, [r2]
	cmp r0, #0
	bne _080A2AA6
	ldr r0, [r4, #0x50]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x50]
	b _080A2AC0
_080A2AA6:
	ldr r0, [r4, #0x50]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x50]
	adds r0, r4, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	ldrb r2, [r2]
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0x6e
	strh r0, [r1]
_080A2AC0:
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #7
	bls _080A2ADE
	adds r0, r4, #0
	adds r0, #0x7c
	subs r2, #2
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #2
	bl Video_SetAuxSpritePltt
	b _080A2B06
_080A2ADE:
	cmp r0, #0
	beq _080A2AF6
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #1
	bl Video_SetAuxSpritePltt
	b _080A2B06
_080A2AF6:
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	bl Video_SetAuxSpritePltt
_080A2B06:
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x17
	bls _080A2B24
	ldr r1, _080A2B2C @ =FUN_080a2b30
	adds r0, r4, #0
	bl FUN_080a2a14
	adds r0, r4, #0
	adds r0, #0x18
	movs r1, #1
	bl MsgQueue_EndWait
_080A2B24:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A2B2C: .4byte FUN_080a2b30

	thumb_func_start FUN_080a2b30
FUN_080a2b30: @ 0x080A2B30
	push {lr}
	adds r3, r0, #0
	movs r0, #0xda
	lsls r0, r0, #2
	adds r2, r3, r0
	movs r0, #0x18
	strb r0, [r2]
	movs r0, #0xe3
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #8
	strh r0, [r1]
	ldr r0, [r3, #0x50]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3, #0x50]
	adds r0, r3, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	ldrb r2, [r2]
	adds r0, r0, r2
	adds r1, r3, #0
	adds r1, #0x6e
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r3, r2
	ldrh r1, [r1]
	adds r1, #2
	bl Video_SetAuxSpritePltt
	pop {r0}
	bx r0

	thumb_func_start FUN_080a2b78
FUN_080a2b78: @ 0x080A2B78
	push {lr}
	adds r3, r0, #0
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r3, r0
	ldrb r0, [r1]
	cmp r0, #1
	bls _080A2B8C
	subs r0, #2
	b _080A2B8E
_080A2B8C:
	movs r0, #0
_080A2B8E:
	strb r0, [r1]
	adds r1, r3, #0
	adds r1, #0x9a
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r3, r2
	ldrh r1, [r1]
	ldrb r2, [r0]
	adds r1, r1, r2
	adds r2, r3, #0
	adds r2, #0x6e
	strh r1, [r2]
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A2BCE
	ldr r0, [r3, #0x50]
	ldr r1, _080A2BD4 @ =0xFFFFFDFF
	ands r0, r1
	str r0, [r3, #0x50]
	adds r1, r3, #0
	adds r1, #0x57
	movs r0, #3
	strb r0, [r1]
	adds r2, #0x32
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _080A2BD8 @ =FUN_080a2bdc
	adds r0, r3, #0
	bl FUN_080a2a14
_080A2BCE:
	pop {r0}
	bx r0
	.align 2, 0
_080A2BD4: .4byte 0xFFFFFDFF
_080A2BD8: .4byte FUN_080a2bdc

	thumb_func_start FUN_080a2bdc
FUN_080a2bdc: @ 0x080A2BDC
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #6
	bhi _080A2BF8
	adds r0, #1
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080a2804
	b _080A2C18
_080A2BF8:
	ldr r0, _080A2C20 @ =0x00000382
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080A2C18
	ldr r0, _080A2C24 @ =0x0000015F
	bl PlaySound_082406e0
	ldr r1, _080A2C28 @ =FUN_080a2c2c
	adds r0, r4, #0
	bl FUN_080a2a14
_080A2C18:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A2C20: .4byte 0x00000382
_080A2C24: .4byte 0x0000015F
_080A2C28: .4byte FUN_080a2c2c

	thumb_func_start FUN_080a2c2c
FUN_080a2c2c: @ 0x080A2C2C
	push {lr}
	adds r2, r0, #0
	ldr r0, _080A2C50 @ =0x00000382
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080A2C4A
	ldr r1, _080A2C54 @ =FUN_080a2c58
	adds r0, r2, #0
	bl FUN_080a2a14
_080A2C4A:
	pop {r0}
	bx r0
	.align 2, 0
_080A2C50: .4byte 0x00000382
_080A2C54: .4byte FUN_080a2c58

	thumb_func_start FUN_080a2c58
FUN_080a2c58: @ 0x080A2C58
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080A2CA8 @ =0x00000382
	adds r0, r4, r1
	ldrh r2, [r0]
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x1f
	bhi _080A2C88
	movs r0, #3
	ands r0, r2
	cmp r0, #0
	bne _080A2C88
	lsrs r1, r1, #0x12
	movs r0, #0x34
	muls r0, r1, r0
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r0, r4, r0
	adds r1, r4, #0
	adds r1, #0x98
	bl FUN_080a2678
_080A2C88:
	ldr r0, _080A2CA8 @ =0x00000382
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x40
	bne _080A2CA2
	ldr r1, _080A2CAC @ =FUN_080a2cb0
	adds r0, r4, #0
	bl FUN_080a2a14
_080A2CA2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A2CA8: .4byte 0x00000382
_080A2CAC: .4byte FUN_080a2cb0

	thumb_func_start FUN_080a2cb0
FUN_080a2cb0: @ 0x080A2CB0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x50]
	movs r3, #2
	rsbs r3, r3, #0
	ands r0, r3
	str r0, [r4, #0x50]
	adds r2, r4, #0
	adds r2, #0x6e
	movs r0, #0
	ldrsh r1, [r2, r0]
	adds r0, r4, #0
	adds r0, #0x9a
	movs r5, #0
	ldrsh r0, [r0, r5]
	adds r0, #0x16
	cmp r1, r0
	bge _080A2CDA
	ldrh r0, [r2]
	adds r0, #2
	strh r0, [r2]
_080A2CDA:
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080A2CF2
	subs r0, #1
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080a2804
	b _080A2D0E
_080A2CF2:
	adds r1, r4, #0
	adds r1, #0xa0
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	ldr r1, _080A2D14 @ =FUN_080a2e20
	adds r0, r4, #0
	bl FUN_080a2a14
	adds r0, r4, #0
	adds r0, #0x18
	movs r1, #1
	bl MsgQueue_EndWait
_080A2D0E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A2D14: .4byte FUN_080a2e20

	thumb_func_start FUN_080a2d18
FUN_080a2d18: @ 0x080A2D18
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080A2D94 @ =0x00000382
	adds r5, r4, r0
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0x3f
	bhi _080A2D98
	ldr r0, [r4, #0x50]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	movs r2, #2
	orrs r0, r2
	str r0, [r4, #0x50]
	adds r1, r4, #0
	adds r1, #0xa0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #2
	bl Video_SetAuxSpritePltt
	ldrh r0, [r5]
	adds r2, r4, #0
	adds r2, #0x58
	strb r0, [r2]
	adds r1, r4, #0
	adds r1, #0x59
	strb r0, [r1]
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r3, r4, #0
	adds r3, #0x56
	strb r0, [r3]
	ldrb r1, [r2]
	adds r0, r4, #0
	adds r0, #0xa8
	strb r1, [r0]
	ldrb r0, [r2]
	adds r1, r4, #0
	adds r1, #0xa9
	strb r0, [r1]
	ldrb r0, [r3]
	subs r1, #3
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	adds r0, #0x16
	subs r1, #0x38
	strh r0, [r1]
	b _080A2E14
	.align 2, 0
_080A2D94: .4byte 0x00000382
_080A2D98:
	cmp r3, #0x40
	bne _080A2DC4
	ldr r0, [r4, #0x50]
	movs r2, #3
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r4, #0x50]
	adds r1, r4, #0
	adds r1, #0xa0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0x58
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #0x4f
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	b _080A2E14
_080A2DC4:
	cmp r3, #0x4f
	bls _080A2E14
	adds r1, r4, #0
	adds r1, #0x6e
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	adds r1, #0x2c
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	ble _080A2DF4
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #1
	bl Video_SetAuxSpritePltt
	b _080A2E14
_080A2DF4:
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	bl Video_SetAuxSpritePltt
	ldr r0, [r4, #0x50]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x50]
	ldr r1, _080A2E1C @ =FUN_080a2e20
	adds r0, r4, #0
	bl FUN_080a2a14
_080A2E14:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A2E1C: .4byte FUN_080a2e20

	thumb_func_start FUN_080a2e20
FUN_080a2e20: @ 0x080A2E20
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080A2E94 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080A2E40
	ldr r0, _080A2E98 @ =0x0000036A
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #9
	bhi _080A2E40
	adds r0, #1
	strh r0, [r1]
_080A2E40:
	adds r0, r4, #0
	bl FUN_080a271c
	adds r6, r0, #0
	cmp r6, #0
	bne _080A2E4E
	b _080A2F4C
_080A2E4E:
	ldr r1, _080A2E9C @ =0x00000369
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A2EAC
	movs r2, #1
	ldr r0, _080A2EA0 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	bne _080A2E66
	b _080A2F86
_080A2E66:
	ldr r0, _080A2EA4 @ =0x03002BE0
	ldr r0, [r0]
	adds r1, #0x13
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x18
	bne _080A2E76
	b _080A2F86
_080A2E76:
	cmp r0, #0x19
	bne _080A2E7C
	b _080A2F86
_080A2E7C:
	ldr r0, _080A2EA8 @ =0x030044E0
	ldrh r1, [r0, #2]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _080A2E8A
	b _080A2F86
_080A2E8A:
	movs r0, #0x92
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080A2F86
	.align 2, 0
_080A2E94: .4byte 0x030047A4
_080A2E98: .4byte 0x0000036A
_080A2E9C: .4byte 0x00000369
_080A2EA0: .4byte 0x03002BC0
_080A2EA4: .4byte 0x03002BE0
_080A2EA8: .4byte 0x030044E0
_080A2EAC:
	adds r5, r4, #0
	adds r5, #0x4c
	ldrh r0, [r5]
	cmp r0, #1
	beq _080A2EC2
	movs r0, #0xcc
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #1
	strh r0, [r5]
_080A2EC2:
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #7
	bhi _080A2ED2
	adds r0, #1
	strh r0, [r1]
_080A2ED2:
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0x16
	bhi _080A2EE2
	adds r0, #2
	b _080A2EE4
_080A2EE2:
	movs r0, #0x18
_080A2EE4:
	strb r0, [r1]
	movs r2, #1
	ldr r0, _080A2F3C @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	beq _080A2F86
	ldr r0, _080A2F40 @ =0x030044E0
	ldrh r1, [r0, #2]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080A2F86
	ldr r0, _080A2F44 @ =0x03002BE0
	ldr r2, [r0]
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A2F86
	subs r1, #0x16
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #9
	bls _080A2F86
	movs r0, #0xe3
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #8
	strh r0, [r1]
	adds r1, r4, #0
	adds r1, #0x98
	adds r0, r2, #0
	movs r2, #0
	movs r3, #4
	bl FUN_0807ba94
	ldr r1, _080A2F48 @ =FUN_080a3004
	adds r0, r4, #0
	bl FUN_080a2a14
	b _080A2F86
	.align 2, 0
_080A2F3C: .4byte 0x03002BC0
_080A2F40: .4byte 0x030044E0
_080A2F44: .4byte 0x03002BE0
_080A2F48: .4byte FUN_080a3004
_080A2F4C:
	adds r5, r4, #0
	adds r5, #0x4c
	ldrh r0, [r5]
	cmp r0, #0
	beq _080A2F5E
	ldr r0, _080A2F80 @ =0x00000199
	bl PlaySound_082406e0
	strh r6, [r5]
_080A2F5E:
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _080A2F6E
	subs r0, #1
	strh r0, [r1]
_080A2F6E:
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #2
	bls _080A2F84
	subs r0, #2
	strb r0, [r1]
	b _080A2F86
	.align 2, 0
_080A2F80: .4byte 0x00000199
_080A2F84:
	strb r6, [r1]
_080A2F86:
	movs r1, #0xda
	lsls r1, r1, #2
	adds r2, r4, r1
	ldrb r0, [r2]
	cmp r0, #0
	bne _080A2F9C
	ldr r0, [r4, #0x50]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x50]
	b _080A2FB6
_080A2F9C:
	ldr r0, [r4, #0x50]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x50]
	adds r0, r4, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	ldrb r2, [r2]
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0x6e
	strh r0, [r1]
_080A2FB6:
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #7
	bls _080A2FD4
	adds r0, r4, #0
	adds r0, #0x7c
	subs r2, #2
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #2
	bl Video_SetAuxSpritePltt
	b _080A2FFC
_080A2FD4:
	cmp r0, #0
	beq _080A2FEC
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #1
	bl Video_SetAuxSpritePltt
	b _080A2FFC
_080A2FEC:
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	bl Video_SetAuxSpritePltt
_080A2FFC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a3004
FUN_080a3004: @ 0x080A3004
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #1
	bls _080A3018
	subs r0, #2
	b _080A301A
_080A3018:
	movs r0, #0
_080A301A:
	strb r0, [r1]
	adds r1, r4, #0
	adds r1, #0x9a
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r1, [r1]
	ldrb r2, [r0]
	adds r1, r1, r2
	adds r2, r4, #0
	adds r2, #0x6e
	strh r1, [r2]
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A30A6
	ldr r0, _080A30AC @ =0x03002BE0
	ldr r1, [r0]
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A30A6
	adds r0, r1, #0
	movs r1, #4
	movs r2, #0
	bl FUN_0807c200
	ldr r0, _080A30B0 @ =0x000001C3
	adds r5, r4, r0
	movs r0, #0
	strb r0, [r5]
	adds r0, r4, #0
	bl FUN_080a2778
	cmp r0, #0
	beq _080A3070
	bl FUN_08086ab8
	cmp r0, #0
	beq _080A3070
	movs r0, #1
	strb r0, [r5]
_080A3070:
	ldr r0, [r4, #0x50]
	ldr r1, _080A30B4 @ =0xFFFFFDFF
	ands r0, r1
	str r0, [r4, #0x50]
	adds r1, r4, #0
	adds r1, #0x57
	movs r0, #3
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0xa0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _080A30B8 @ =FUN_080a30bc
	adds r0, r4, #0
	bl FUN_080a2a14
	movs r1, #0xdb
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080A30A6
	movs r1, #0
	bl VM_ExecByID
_080A30A6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A30AC: .4byte 0x03002BE0
_080A30B0: .4byte 0x000001C3
_080A30B4: .4byte 0xFFFFFDFF
_080A30B8: .4byte FUN_080a30bc

	thumb_func_start FUN_080a30bc
FUN_080a30bc: @ 0x080A30BC
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #6
	bhi _080A30D8
	adds r0, #1
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080a2804
	b _080A30F8
_080A30D8:
	ldr r0, _080A3100 @ =0x00000382
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080A30F8
	ldr r0, _080A3104 @ =0x0000015F
	bl PlaySound_082406e0
	ldr r1, _080A3108 @ =FUN_080a310c
	adds r0, r4, #0
	bl FUN_080a2a14
_080A30F8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A3100: .4byte 0x00000382
_080A3104: .4byte 0x0000015F
_080A3108: .4byte FUN_080a310c

	thumb_func_start FUN_080a310c
FUN_080a310c: @ 0x080A310C
	push {lr}
	adds r2, r0, #0
	ldr r0, _080A3130 @ =0x00000382
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080A312A
	ldr r1, _080A3134 @ =FUN_080a3138
	adds r0, r2, #0
	bl FUN_080a2a14
_080A312A:
	pop {r0}
	bx r0
	.align 2, 0
_080A3130: .4byte 0x00000382
_080A3134: .4byte FUN_080a3138

	thumb_func_start FUN_080a3138
FUN_080a3138: @ 0x080A3138
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r1, _080A31D0 @ =0x00000382
	adds r0, r4, r1
	ldrh r2, [r0]
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x1f
	bhi _080A316A
	movs r0, #3
	ands r0, r2
	cmp r0, #0
	bne _080A316A
	lsrs r1, r1, #0x12
	movs r0, #0x34
	muls r0, r1, r0
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r0, r3
	adds r0, r4, r0
	adds r1, r4, #0
	adds r1, #0x98
	bl FUN_080a2678
_080A316A:
	ldr r0, _080A31D0 @ =0x00000382
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x40
	bne _080A31C6
	movs r1, #0xdd
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080A31AA
	ldr r1, _080A31D4 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	mov r3, sp
	str r3, [r1, #4]
	movs r3, #0xde
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r0, [r0]
	str r0, [sp]
	adds r0, r2, #0
	bl VM_ExecByID
_080A31AA:
	ldr r1, _080A31D8 @ =0x000001C3
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A31C6
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r0, [r0]
	cmp r0, #0
	beq _080A31C6
	movs r1, #0
	bl VM_ExecByID
_080A31C6:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A31D0: .4byte 0x00000382
_080A31D4: .4byte 0xFFFF0000
_080A31D8: .4byte 0x000001C3

	thumb_func_start FUN_080a31dc
FUN_080a31dc: @ 0x080A31DC
	push {lr}
	adds r2, r0, #0
	ldr r0, _080A3200 @ =0x00000382
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _080A31FA
	ldr r1, _080A3204 @ =FUN_080a3208
	adds r0, r2, #0
	bl FUN_080a2a14
_080A31FA:
	pop {r0}
	bx r0
	.align 2, 0
_080A3200: .4byte 0x00000382
_080A3204: .4byte FUN_080a3208

	thumb_func_start FUN_080a3208
FUN_080a3208: @ 0x080A3208
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080A326C @ =0x00000382
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0x10
	bne _080A3222
	ldr r0, _080A3270 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #4
	movs r2, #0
	bl FUN_0807c36c
_080A3222:
	ldrh r2, [r5]
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x1f
	bhi _080A324A
	movs r0, #3
	ands r0, r2
	cmp r0, #0
	bne _080A324A
	lsrs r1, r1, #0x12
	movs r0, #0x34
	muls r0, r1, r0
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r0, r4, r0
	adds r1, r4, #0
	adds r1, #0x98
	bl FUN_080a25c8
_080A324A:
	ldr r0, _080A326C @ =0x00000382
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _080A3264
	ldr r1, _080A3274 @ =FUN_080a3278
	adds r0, r4, #0
	bl FUN_080a2a14
_080A3264:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A326C: .4byte 0x00000382
_080A3270: .4byte 0x03002BE0
_080A3274: .4byte FUN_080a3278

	thumb_func_start FUN_080a3278
FUN_080a3278: @ 0x080A3278
	push {lr}
	adds r2, r0, #0
	ldr r0, _080A329C @ =0x00000382
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080A3296
	ldr r1, _080A32A0 @ =FUN_080a32a4
	adds r0, r2, #0
	bl FUN_080a2a14
_080A3296:
	pop {r0}
	bx r0
	.align 2, 0
_080A329C: .4byte 0x00000382
_080A32A0: .4byte FUN_080a32a4

	thumb_func_start FUN_080a32a4
FUN_080a32a4: @ 0x080A32A4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x50]
	movs r5, #2
	rsbs r5, r5, #0
	ands r0, r5
	str r0, [r4, #0x50]
	adds r2, r4, #0
	adds r2, #0x6e
	movs r0, #0
	ldrsh r1, [r2, r0]
	adds r0, r4, #0
	adds r0, #0x9a
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r0, #0x16
	cmp r1, r0
	bge _080A32CE
	ldrh r0, [r2]
	adds r0, #2
	strh r0, [r2]
_080A32CE:
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080A32E6
	subs r0, #1
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080a2804
	b _080A3336
_080A32E6:
	ldr r0, _080A3314 @ =0x03002BE0
	ldr r0, [r0]
	bl FUN_0807d118
	bl FUN_080a6edc
	adds r1, r4, #0
	adds r1, #0xa0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A331C
	ldr r1, _080A3318 @ =FUN_080a3340
	adds r0, r4, #0
	bl FUN_080a2a14
	b _080A3324
	.align 2, 0
_080A3314: .4byte 0x03002BE0
_080A3318: .4byte FUN_080a3340
_080A331C:
	ldr r1, _080A333C @ =FUN_080a2e20
	adds r0, r4, #0
	bl FUN_080a2a14
_080A3324:
	movs r3, #0xdc
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r0, [r0]
	cmp r0, #0
	beq _080A3336
	movs r1, #0
	bl VM_ExecByID
_080A3336:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A333C: .4byte FUN_080a2e20

	thumb_func_start FUN_080a3340
FUN_080a3340: @ 0x080A3340
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xda
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, #2
	bls _080A3370
	subs r0, #2
	strb r0, [r2]
	ldr r0, [r4, #0x50]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x50]
	adds r0, r4, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	ldrb r2, [r2]
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0x6e
	strh r0, [r1]
	b _080A3378
_080A3370:
	ldr r0, [r4, #0x50]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x50]
_080A3378:
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _080A3388
	subs r0, #1
	strh r0, [r1]
_080A3388:
	ldrh r0, [r1]
	cmp r0, #7
	bls _080A33A2
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #2
	bl Video_SetAuxSpritePltt
	b _080A33CA
_080A33A2:
	cmp r0, #0
	beq _080A33BA
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #1
	bl Video_SetAuxSpritePltt
	b _080A33CA
_080A33BA:
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	bl Video_SetAuxSpritePltt
_080A33CA:
	ldr r0, _080A3424 @ =0x00000382
	adds r3, r4, r0
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bhi _080A3428
	ldr r0, [r4, #0x50]
	movs r2, #2
	orrs r0, r2
	str r0, [r4, #0x50]
	adds r1, r4, #0
	adds r1, #0xa0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrb r1, [r3]
	movs r0, #0x40
	subs r0, r0, r1
	adds r2, r4, #0
	adds r2, #0x58
	strb r0, [r2]
	adds r1, r4, #0
	adds r1, #0x59
	strb r0, [r1]
	ldrb r0, [r3]
	lsls r0, r0, #2
	adds r3, r4, #0
	adds r3, #0x56
	strb r0, [r3]
	ldrb r1, [r2]
	adds r0, r4, #0
	adds r0, #0xa8
	strb r1, [r0]
	ldrb r0, [r2]
	adds r1, r4, #0
	adds r1, #0xa9
	strb r0, [r1]
	ldrb r1, [r3]
	adds r0, r4, #0
	adds r0, #0xa6
	strb r1, [r0]
	b _080A3440
	.align 2, 0
_080A3424: .4byte 0x00000382
_080A3428:
	ldr r0, [r4, #0x50]
	movs r2, #1
	orrs r0, r2
	str r0, [r4, #0x50]
	adds r1, r4, #0
	adds r1, #0xa0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r4, #0
	bl KillEntity
_080A3440:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a3448
FUN_080a3448: @ 0x080A3448
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r6, r7, #0
	adds r6, #0x18
	movs r5, #0
	ldr r2, _080A3494 @ =0x03002B4C
	ldr r1, [r2]
	adds r1, #0x24
	adds r0, #0x1e
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r5, r0
	bge _080A34C4
	mov r8, r2
_080A346A:
	mov r1, r8
	ldr r0, [r1]
	lsls r1, r5, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r6, #0
	adds r0, #8
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	bl MsgQueue_BeginWait
	ldrb r0, [r4, #6]
	cmp r0, #7
	beq _080A3498
	cmp r0, #8
	beq _080A34A8
	b _080A34B0
	.align 2, 0
_080A3494: .4byte 0x03002B4C
_080A3498:
	adds r0, r7, #0
	ldr r1, _080A34A4 @ =FUN_080a2a4c
	bl FUN_080a2a14
	b _080A34B0
	.align 2, 0
_080A34A4: .4byte FUN_080a2a4c
_080A34A8:
	adds r0, r7, #0
	ldr r1, _080A34D0 @ =FUN_080a2b78
	bl FUN_080a2a14
_080A34B0:
	adds r5, #1
	mov r0, r8
	ldr r1, [r0]
	adds r1, #0x24
	adds r0, r6, #6
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r5, r0
	blt _080A346A
_080A34C4:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A34D0: .4byte FUN_080a2b78

	thumb_func_start EntityA8F1_Update
EntityA8F1_Update: @ 0x080A34D4
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_080a3448
	movs r1, #0xe1
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r5, #0
_080A34EC:
	movs r0, #0x34
	adds r1, r5, #0
	muls r1, r0, r1
	adds r0, r4, r1
	movs r2, #0xf8
	lsls r2, r2, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A350A
	subs r2, #0x28
	adds r0, r1, r2
	adds r0, r4, r0
	bl FUN_080a251c
_080A350A:
	adds r5, #1
	cmp r5, #7
	ble _080A34EC
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start EntityA8F1_Destroy
EntityA8F1_Destroy: @ 0x080A3518
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r0, #0x50
	bl AuxSprite_Remove
	adds r0, r6, #0
	adds r0, #0xa0
	bl AuxSprite_Remove
	adds r4, r6, #0
	adds r4, #0xe8
	movs r5, #2
_080A3530:
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r4, #0x2c
	subs r5, #1
	cmp r5, #0
	bge _080A3530
	adds r7, r6, #0
	adds r7, #0x18
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r4, r6, r0
	movs r5, #7
_080A354A:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x34
	subs r5, #1
	cmp r5, #0
	bge _080A354A
	adds r0, r7, #0
	bl MsgQueue_Unregister
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a3568
FUN_080a3568: @ 0x080A3568
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	movs r7, #0
	ldr r0, _080A35F8 @ =0x00001C1E
	mov sb, r0
	movs r0, #0
	mov sl, r0
	subs r0, #4
	mov r8, r0
_080A3582:
	movs r0, #0x34
	adds r5, r7, #0
	muls r5, r0, r5
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r4, r5, r0
	adds r4, r6, r4
	mov r0, sb
	bl GetParticleGroup
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #1
	bl Particle_Add
	adds r0, r4, #0
	mov r1, r8
	mov r2, r8
	bl Particle_SetOffset
	adds r0, r4, #0
	movs r1, #1
	bl Particle_SetPltt
	mov r0, sb
	bl GetParticleGroup
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #2
	bl Particle_SetFrame
	movs r0, #1
	strb r0, [r4, #0xf]
	movs r0, #0x14
	strb r0, [r4, #0x10]
	adds r0, r6, #0
	adds r0, #0x98
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r4, #0x18]
	str r1, [r4, #0x1c]
	adds r5, r6, r5
	movs r0, #0xf8
	lsls r0, r0, #1
	adds r5, r5, r0
	mov r0, sl
	strb r0, [r5]
	adds r7, #1
	cmp r7, #7
	ble _080A3582
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A35F8: .4byte 0x00001C1E

	thumb_func_start EntityA8F1_Init
EntityA8F1_Init: @ 0x080A35FC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	str r1, [sp]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	adds r2, r0, #0
	cmp r2, #0
	beq _080A36BC
	bl VM_GetValue
	adds r4, r7, #0
	adds r4, #0x98
	strh r0, [r4]
	bl VM_GetValue
	adds r5, r7, #0
	adds r5, #0x9a
	strh r0, [r5]
	bl VM_GetValue
	adds r1, r7, #0
	adds r1, #0x9c
	strh r0, [r1]
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r4, [sp, #0xc]
	cmp r2, #0
	blt _080A365C
	cmp r1, #0
	blt _080A365C
	ldr r0, _080A3660 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A365C
	ldr r0, _080A3664 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A3668
_080A365C:
	movs r6, #0
	b _080A3676
	.align 2, 0
_080A3660: .4byte 0x030046A8
_080A3664: .4byte 0x030046AC
_080A3668:
	ldr r0, _080A3688 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r2
_080A3676:
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080A368C
	adds r0, #4
	b _080A3698
	.align 2, 0
_080A3688: .4byte 0x030046A4
_080A368C:
	ldr r0, _080A36AC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A3698:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080A36B0
	cmp r2, #2
	beq _080A36B4
	b _080A36B8
	.align 2, 0
_080A36AC: .4byte 0x030046A4
_080A36B0:
	ldrb r0, [r4, #4]
	b _080A36B6
_080A36B4:
	ldrb r0, [r4]
_080A36B6:
	subs r1, r1, r0
_080A36B8:
	strh r1, [r5]
	b _080A36CE
_080A36BC:
	adds r1, r7, #0
	adds r1, #0x98
	strh r2, [r1]
	adds r0, r7, #0
	adds r0, #0x9a
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	str r1, [sp, #0xc]
_080A36CE:
	movs r0, #0x43
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A36E8
	bl VM_GetValue
	movs r2, #0xdb
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A36F0
_080A36E8:
	movs r3, #0xdb
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A36F0:
	movs r0, #0x63
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A370A
	bl VM_GetValue
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A3712
_080A370A:
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A3712:
	movs r0, #0x69
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A372C
	bl VM_GetValue
	movs r2, #0xdc
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A3734
_080A372C:
	movs r3, #0xdc
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A3734:
	movs r0, #0x6f
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A374E
	bl VM_GetValue
	movs r2, #0xdd
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A3756
_080A374E:
	movs r3, #0xdd
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A3756:
	movs r0, #0x64
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A376A
	bl VM_GetValue
	adds r1, r7, #0
	adds r1, #0x4e
	b _080A3770
_080A376A:
	adds r1, r7, #0
	adds r1, #0x4e
	movs r0, #6
_080A3770:
	strh r0, [r1]
	mov sl, r1
	movs r0, #0x61
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A3790
	bl VM_GetValue
	ldr r2, _080A378C @ =0x00000369
	adds r1, r7, r2
	strb r0, [r1]
	b _080A3796
	.align 2, 0
_080A378C: .4byte 0x00000369
_080A3790:
	ldr r3, _080A37B0 @ =0x00000369
	adds r0, r7, r3
	strb r1, [r0]
_080A3796:
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A37B4
	bl VM_GetValue
	movs r2, #0xde
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A37BC
	.align 2, 0
_080A37B0: .4byte 0x00000369
_080A37B4:
	movs r3, #0xde
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A37BC:
	mov r1, sl
	ldrh r0, [r1]
	lsrs r0, r0, #1
	lsls r1, r0, #1
	adds r1, r1, r0
	adds r1, #0x61
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r6, r7, r2
	strh r1, [r6]
	movs r3, #0x7c
	adds r3, r3, r7
	mov r8, r3
	ldr r5, _080A3930 @ =0x00000BA8
	mov r0, r8
	adds r1, r5, #0
	bl Video_GetAuxSprite
	adds r4, r7, #0
	adds r4, #0x50
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl AuxSprite_Add
	mov r1, sl
	ldrh r0, [r1]
	strh r0, [r4, #0x10]
	ldrh r1, [r6]
	mov r0, r8
	bl Video_SetAuxSpritePltt
	ldr r0, [r7, #0x50]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r7, #0x50]
	adds r0, r7, #0
	adds r0, #0x57
	movs r2, #3
	mov sb, r2
	mov r3, sb
	strb r3, [r0]
	ldr r2, [sp, #0xc]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x6c]
	str r1, [r7, #0x70]
	adds r4, #0x7c
	adds r0, r4, #0
	adds r1, r5, #0
	bl Video_GetAuxSprite
	adds r5, r7, #0
	adds r5, #0xa0
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	mov r3, sl
	ldrh r0, [r3]
	strh r0, [r5, #0x10]
	ldrh r1, [r6]
	adds r0, r4, #0
	bl Video_SetAuxSpritePltt
	ldr r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r5]
	adds r0, r7, #0
	adds r0, #0xa7
	mov r1, sb
	strb r1, [r0]
	adds r2, r7, #0
	adds r2, #0xbc
	ldr r3, [sp, #0xc]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0
	mov sb, r0
	mov r1, r8
	str r1, [sp, #8]
	mov r8, r5
	adds r2, #0x2c
	str r2, [sp, #0x10]
	adds r3, r7, #0
	adds r3, #0x18
	str r3, [sp, #0x14]
	adds r0, r7, #0
	adds r0, #0x4c
	str r0, [sp, #4]
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r6, r7, r1
_080A3882:
	adds r0, r6, #0
	ldr r1, _080A3930 @ =0x00000BA8
	bl Video_GetAuxSprite
	movs r0, #0x2c
	mov r4, sb
	muls r4, r0, r4
	adds r0, r4, #0
	adds r0, #0xe8
	adds r0, r7, r0
	adds r1, r6, #0
	movs r2, #0
	bl AuxSprite_Add
	mov r2, sl
	ldrh r0, [r2]
	movs r5, #1
	adds r1, r5, #0
	ands r1, r0
	adds r0, r4, r7
	adds r0, #0xe8
	adds r1, #0x10
	strh r1, [r0, #0x10]
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrh r1, [r0]
	adds r1, #2
	adds r0, r6, #0
	bl Video_SetAuxSpritePltt
	ldr r0, [sp, #0x10]
	adds r2, r0, r4
	ldr r0, [r2]
	ldr r1, _080A3934 @ =0x00000201
	orrs r0, r1
	str r0, [r2]
	adds r1, r7, r4
	adds r0, r1, #0
	adds r0, #0xef
	movs r2, #1
	strb r2, [r0]
	movs r3, #0x82
	lsls r3, r3, #1
	adds r2, r1, r3
	ldr r3, [sp, #0xc]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	adds r6, #0x1c
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #2
	ble _080A3882
	adds r0, r7, #0
	bl FUN_080a3568
	ldr r0, [sp, #0x14]
	ldr r1, [sp]
	movs r2, #0xa
	bl MsgQueue_Register
	movs r0, #0x44
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A3940
	movs r2, #0
	movs r1, #0
	ldr r3, [sp, #4]
	strh r1, [r3]
	movs r3, #0xe3
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
	ldr r3, _080A3938 @ =0x0000036A
	adds r0, r7, r3
	strh r1, [r0]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r7, r1
	strb r2, [r0]
	ldr r1, _080A393C @ =FUN_080a2a2c
	b _080A3A70
	.align 2, 0
_080A3930: .4byte 0x00000BA8
_080A3934: .4byte 0x00000201
_080A3938: .4byte 0x0000036A
_080A393C: .4byte FUN_080a2a2c
_080A3940:
	movs r4, #0
	movs r0, #0x66
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A3952
	bl VM_GetValue
	adds r4, r0, #0
_080A3952:
	movs r6, #0
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A3964
	bl VM_GetValue
	adds r6, r0, #0
_080A3964:
	cmp r4, #0
	beq _080A3A24
	movs r0, #0xb0
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r2, #0xe0
	lsls r2, r2, #2
	adds r0, r7, r2
	strh r5, [r0]
	movs r0, #0
	bl FUN_080a6e88
	ldr r4, _080A3A18 @ =0x03002BE0
	ldr r0, [r4]
	ldr r1, [sp, #0xc]
	bl FUN_0807a91c
	ldr r0, [r4]
	bl FUN_0807b8dc
	ldr r0, [r7, #0x50]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #0x50]
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrh r1, [r0]
	adds r1, #2
	ldr r0, [sp, #8]
	bl Video_SetAuxSpritePltt
	mov r1, r8
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #7
	strh r0, [r1]
	adds r0, r7, #0
	bl FUN_080a2804
	movs r3, #0xe3
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r0, #8
	strh r0, [r1]
	ldr r0, [sp, #4]
	strh r5, [r0]
	ldr r2, _080A3A1C @ =0x0000036A
	adds r1, r7, r2
	movs r0, #0xa
	strh r0, [r1]
	movs r3, #0xda
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r0, #0x18
	strb r0, [r1]
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r7, r1
	strb r6, [r0]
	ldr r1, _080A3A20 @ =FUN_080a31dc
	adds r0, r7, #0
	bl FUN_080a2a14
	movs r4, #0
	movs r0, #0x77
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A3A02
	bl VM_GetValue
	adds r4, r0, #0
_080A3A02:
	cmp r4, #0
	beq _080A3A88
	bl FUN_08086af0
	cmp r0, #0
	beq _080A3A88
	ldr r0, [sp, #0xc]
	bl FUN_08086a4c
	b _080A3A88
	.align 2, 0
_080A3A18: .4byte 0x03002BE0
_080A3A1C: .4byte 0x0000036A
_080A3A20: .4byte FUN_080a31dc
_080A3A24:
	movs r0, #0
	ldr r2, [sp, #4]
	strh r4, [r2]
	movs r3, #0xe3
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r4, [r1]
	ldr r2, _080A3A78 @ =0x0000036A
	adds r1, r7, r2
	strh r4, [r1]
	movs r3, #0xda
	lsls r3, r3, #2
	adds r1, r7, r3
	strb r0, [r1]
	cmp r6, #0
	beq _080A3A80
	movs r0, #0xaf
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r0, [r7, #0x50]
	movs r1, #2
	orrs r0, r1
	str r0, [r7, #0x50]
	mov r2, r8
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	adds r0, r7, #0
	adds r0, #0x58
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
	adds r0, #0x4f
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
	ldr r1, _080A3A7C @ =FUN_080a2d18
_080A3A70:
	adds r0, r7, #0
	bl FUN_080a2a14
	b _080A3A88
	.align 2, 0
_080A3A78: .4byte 0x0000036A
_080A3A7C: .4byte FUN_080a2d18
_080A3A80:
	ldr r1, _080A3A9C @ =FUN_080a2e20
	adds r0, r7, #0
	bl FUN_080a2a14
_080A3A88:
	movs r0, #0
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A3A9C: .4byte FUN_080a2e20

	thumb_func_start EntityA8F1_Create
EntityA8F1_Create: @ 0x080A3AA0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0xe2
	lsls r1, r1, #2
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A3AE0
	ldr r1, _080A3AD8 @ =EntityA8F1_Update
	ldr r2, _080A3ADC @ =EntityA8F1_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl EntityA8F1_Init
	cmp r0, #0
	bge _080A3AE0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A3AE2
	.align 2, 0
_080A3AD8: .4byte EntityA8F1_Update
_080A3ADC: .4byte EntityA8F1_Destroy
_080A3AE0:
	adds r0, r4, #0
_080A3AE2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
