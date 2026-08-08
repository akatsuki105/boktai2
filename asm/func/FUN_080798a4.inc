	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r1, [r5, #0x20]
	orrs r1, r0
	str r1, [r5, #0x20]
	ldr r0, [r5, #0x1c]
	cmp r0, #1
	beq _080798BE
	cmp r0, #2
	beq _08079964
	b _08079986
_080798BE:
	movs r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _080798D8
	ldr r0, _08079954 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08079958 @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl FUN_080667b0
_080798D8:
	adds r0, r5, #0
	bl FUN_0806680c
	cmp r0, #0
	beq _080798EE
	adds r0, r5, #0
	bl FUN_0806687c
	adds r0, r5, #0
	bl FUN_0806692c
_080798EE:
	adds r0, r5, #0
	bl FUN_080784fc
	adds r0, r5, #0
	bl FUN_080794e0
	adds r4, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08066d7c
	ldr r0, _0807995C @ =0x085ABDB0
	lsls r4, r4, #2
	adds r4, r4, r0
	ldr r1, [r4]
	adds r0, r5, #0
	bl _call_via_r1
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807992C
	movs r2, #0xea
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x34]
	str r1, [r5, #0x38]
_0807992C:
	adds r0, r5, #0
	bl FUN_08066408
	adds r0, r5, #0
	bl FUN_0807972c
	ldr r1, _08079960 @ =0x000003CE
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _0807994A
	adds r0, r5, #0
	bl FUN_08066df8
_0807994A:
	adds r0, r5, #0
	bl FUN_0806623c
	b _08079986
	.align 2, 0
_08079954: .4byte 0x030046A0
_08079958: .4byte 0x00000942
_0807995C: .4byte 0x085ABDB0
_08079960: .4byte 0x000003CE
_08079964:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08060c40
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	bl FUN_0807972c
	adds r0, r5, #0
	bl FUN_080726ec
_08079986:
	pop {r4, r5}
	pop {r0}
	bx r0
