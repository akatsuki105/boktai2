	push {r4, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	movs r0, #0x9f
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0
	str r0, [r1]
	movs r1, #0
	movs r2, #0x9b
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r2, #3
_08064856:
	strh r1, [r0]
	strh r1, [r0, #8]
	adds r0, #2
	subs r2, #1
	cmp r2, #0
	bge _08064856
	movs r1, #0xde
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r2, _08064884 @ =0xF000000F
	ldr r1, [r0]
	ands r1, r2
	str r1, [r0]
	adds r2, r0, #0
	cmp r3, #0
	bne _0806488C
	adds r0, r4, #0
	bl FUN_08062c3c
	ldr r2, _08064888 @ =0x0000094C
	adds r1, r4, r2
	b _08064A50
	.align 2, 0
_08064884: .4byte 0xF000000F
_08064888: .4byte 0x0000094C
_0806488C:
	ldrb r0, [r3, #3]
	subs r0, #1
	cmp r0, #0x1f
	bls _08064896
	b _08064A46
_08064896:
	lsls r0, r0, #2
	ldr r1, _080648A0 @ =_080648A4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080648A0: .4byte _080648A4
_080648A4: @ jump table
	.4byte _08064988 @ case 0
	.4byte _080649A0 @ case 1
	.4byte _080649BC @ case 2
	.4byte _080649D8 @ case 3
	.4byte _08064924 @ case 4
	.4byte _08064934 @ case 5
	.4byte _08064940 @ case 6
	.4byte _0806494C @ case 7
	.4byte _08064958 @ case 8
	.4byte _08064964 @ case 9
	.4byte _08064970 @ case 10
	.4byte _0806497C @ case 11
	.4byte _080649DC @ case 12
	.4byte _080649E0 @ case 13
	.4byte _08064A46 @ case 14
	.4byte _08064A06 @ case 15
	.4byte _080649E6 @ case 16
	.4byte _080649EC @ case 17
	.4byte _080649F2 @ case 18
	.4byte _080649F8 @ case 19
	.4byte _08064A0C @ case 20
	.4byte _08064A12 @ case 21
	.4byte _080649FE @ case 22
	.4byte _08064A02 @ case 23
	.4byte _08064A18 @ case 24
	.4byte _080649C8 @ case 25
	.4byte _08064A1E @ case 26
	.4byte _08064A24 @ case 27
	.4byte _08064A2A @ case 28
	.4byte _08064A30 @ case 29
	.4byte _08064A36 @ case 30
	.4byte _08064A3C @ case 31
_08064924:
	movs r3, #0x9f
	lsls r3, r3, #2
	adds r1, r4, r3
	movs r0, #1
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #7
	b _08064A40
_08064934:
	movs r0, #0x9f
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #2
	str r0, [r1]
	b _08064A46
_08064940:
	movs r2, #0x9f
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r0, #4
	str r0, [r1]
	b _08064A46
_0806494C:
	movs r3, #0x9f
	lsls r3, r3, #2
	adds r1, r4, r3
	movs r0, #8
	str r0, [r1]
	b _08064A46
_08064958:
	movs r0, #0x9f
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0x10
	str r0, [r1]
	b _08064A46
_08064964:
	movs r2, #0x9f
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r0, #0x20
	str r0, [r1]
	b _08064A46
_08064970:
	movs r3, #0x9f
	lsls r3, r3, #2
	adds r1, r4, r3
	movs r0, #0x3c
	str r0, [r1]
	b _08064A46
_0806497C:
	movs r0, #0x9f
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0x40
	str r0, [r1]
	b _08064A46
_08064988:
	ldrb r1, [r3, #4]
	movs r2, #3
	ldr r3, _0806499C @ =0x0000027A
	adds r0, r4, r3
_08064990:
	strh r1, [r0]
	subs r0, #2
	subs r2, #1
	cmp r2, #0
	bge _08064990
	b _08064A46
	.align 2, 0
_0806499C: .4byte 0x0000027A
_080649A0:
	ldrb r1, [r3, #4]
	rsbs r1, r1, #0
	movs r2, #3
	ldr r3, _080649B8 @ =0x0000027A
	adds r0, r4, r3
_080649AA:
	strh r1, [r0]
	subs r0, #2
	subs r2, #1
	cmp r2, #0
	bge _080649AA
	b _08064A46
	.align 2, 0
_080649B8: .4byte 0x0000027A
_080649BC:
	ldrb r1, [r3, #4]
	movs r2, #0x9c
	lsls r2, r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	b _08064A46
_080649C8:
	ldrb r1, [r3, #4]
	ldr r3, _080649D4 @ =0x00000272
	adds r0, r4, r3
	strh r1, [r0]
	b _08064A46
	.align 2, 0
_080649D4: .4byte 0x00000272
_080649D8:
	movs r1, #0x10
	b _08064A40
_080649DC:
	movs r1, #0x80
	b _08064A40
_080649E0:
	movs r1, #0x80
	lsls r1, r1, #5
	b _08064A40
_080649E6:
	movs r1, #0x80
	lsls r1, r1, #3
	b _08064A40
_080649EC:
	movs r1, #0x80
	lsls r1, r1, #1
	b _08064A40
_080649F2:
	movs r1, #0x80
	lsls r1, r1, #2
	b _08064A40
_080649F8:
	movs r1, #0x80
	lsls r1, r1, #4
	b _08064A40
_080649FE:
	movs r1, #0x20
	b _08064A40
_08064A02:
	movs r1, #0x40
	b _08064A40
_08064A06:
	movs r1, #0x80
	lsls r1, r1, #6
	b _08064A40
_08064A0C:
	movs r1, #0x80
	lsls r1, r1, #8
	b _08064A40
_08064A12:
	movs r1, #0x80
	lsls r1, r1, #9
	b _08064A40
_08064A18:
	movs r1, #0x80
	lsls r1, r1, #0xa
	b _08064A40
_08064A1E:
	movs r1, #0x80
	lsls r1, r1, #0xb
	b _08064A40
_08064A24:
	movs r1, #0x80
	lsls r1, r1, #0xc
	b _08064A40
_08064A2A:
	movs r1, #0x80
	lsls r1, r1, #0xd
	b _08064A40
_08064A30:
	movs r1, #0x80
	lsls r1, r1, #0xe
	b _08064A40
_08064A36:
	movs r1, #0x80
	lsls r1, r1, #0xf
	b _08064A40
_08064A3C:
	movs r1, #0x80
	lsls r1, r1, #0x10
_08064A40:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_08064A46:
	adds r0, r4, #0
	bl FUN_08062c3c
	ldr r0, _08064A5C @ =0x0000094C
	adds r1, r4, r0
_08064A50:
	ldr r0, _08064A60 @ =0x0000FFFF
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08064A5C: .4byte 0x0000094C
_08064A60: .4byte 0x0000FFFF
