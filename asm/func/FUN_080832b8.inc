	push {r4, r5, lr}
	sub sp, #0x18
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	beq _080832D4
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0
	bl FUN_08080e0c
_080832D4:
	ldr r2, _080832F4 @ =0x00000951
	adds r0, r4, r2
	movs r1, #9
	strb r1, [r0]
	ldr r3, _080832F8 @ =0x0000037D
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #7
	bls _080832E8
	b _080835CE
_080832E8:
	lsls r0, r0, #2
	ldr r1, _080832FC @ =_08083300
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080832F4: .4byte 0x00000951
_080832F8: .4byte 0x0000037D
_080832FC: .4byte _08083300
_08083300: @ jump table
	.4byte _08083320 @ case 0
	.4byte _0808337C @ case 1
	.4byte _080833E0 @ case 2
	.4byte _080835CE @ case 3
	.4byte _080835CE @ case 4
	.4byte _08083460 @ case 5
	.4byte _08083510 @ case 6
	.4byte _08083540 @ case 7
_08083320:
	movs r1, #0xef
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	bne _08083332
	b _080835CE
_08083332:
	adds r0, r4, #0
	movs r1, #3
	movs r2, #1
	bl FUN_08080e0c
	ldr r0, _08083368 @ =0x0000046E
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	ldr r2, _0808336C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08083370 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08083374 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	adds r0, #2
	ldr r2, _08083378 @ =0x0000046F
	adds r1, r4, r2
	strb r0, [r1]
	b _080835CE
	.align 2, 0
_08083368: .4byte 0x0000046E
_0808336C: .4byte 0x030046B8
_08083370: .4byte 0x000003FF
_08083374: .4byte 0x0203B400
_08083378: .4byte 0x0000046F
_0808337C:
	ldr r3, _080833BC @ =0x0000037E
	adds r5, r4, r3
	ldrh r0, [r5]
	cmp r0, #0
	bne _0808338C
	ldr r0, _080833C0 @ =0x000001F7
	bl PlaySound_082406e0
_0808338C:
	ldr r1, _080833C4 @ =0x000001E3
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _080833A6
	b _080835CE
_080833A6:
	bl FUN_080298dc
	cmp r0, #0
	beq _080833C8
	adds r0, r4, #0
	movs r1, #3
	movs r2, #2
	bl FUN_08080e0c
	b _080835CE
	.align 2, 0
_080833BC: .4byte 0x0000037E
_080833C0: .4byte 0x000001F7
_080833C4: .4byte 0x000001E3
_080833C8:
	adds r0, r4, #0
	movs r1, #1
	movs r2, #6
	movs r3, #2
	bl FUN_080831e0
	adds r0, r4, #0
	movs r1, #3
	movs r2, #5
	bl FUN_08080e0c
	b _080835CE
_080833E0:
	ldr r1, _0808343C @ =0x000001E3
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r0, _08083440 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _08083448
	add r2, sp, #8
	adds r0, r4, #0
	mov r1, sp
	bl FUN_08081de0
	cmp r0, #0
	bne _0808340C
	b _080835CE
_0808340C:
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x2c
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	bne _08083422
	b _080835CE
_08083422:
	movs r2, #0x8e
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #3
	strb r0, [r1]
	ldr r1, [sp, #8]
	ldr r3, _08083444 @ =0x00000471
	adds r0, r4, r3
	strb r1, [r0]
	adds r0, r4, #0
	movs r1, #2
	b _08083508
	.align 2, 0
_0808343C: .4byte 0x000001E3
_08083440: .4byte 0x0000037E
_08083444: .4byte 0x00000471
_08083448:
	ldr r0, _0808345C @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _0808345A
	b _080835CE
_0808345A:
	b _08083504
	.align 2, 0
_0808345C: .4byte 0x03002BE0
_08083460:
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r2, _080834A4 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _08083480
	b _080835CE
_08083480:
	ldr r3, _080834A8 @ =0x0000046E
	adds r0, r4, r3
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	adds r2, #0xf1
	adds r0, r4, r2
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrb r0, [r0]
	cmp r1, r0
	bhs _080834AC
	adds r0, r4, #0
	movs r1, #3
	movs r2, #1
	bl FUN_08080e0c
	b _080835CE
	.align 2, 0
_080834A4: .4byte 0x0000037E
_080834A8: .4byte 0x0000046E
_080834AC:
	ldr r0, _080834FC @ =0x03002BE0
	ldr r0, [r0]
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _08083504
	add r5, sp, #0xc
	add r2, sp, #0x14
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08081de0
	cmp r0, #0
	bne _080834CE
	b _080835CE
_080834CE:
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x2c
	adds r2, r5, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _080835CE
	movs r2, #0x8e
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #3
	strb r0, [r1]
	ldr r1, [sp, #0x14]
	ldr r3, _08083500 @ =0x00000471
	adds r0, r4, r3
	strb r1, [r0]
	adds r0, r4, #0
	movs r1, #2
	b _08083508
	.align 2, 0
_080834FC: .4byte 0x03002BE0
_08083500: .4byte 0x00000471
_08083504:
	adds r0, r4, #0
	movs r1, #3
_08083508:
	movs r2, #6
	bl FUN_08080e0c
	b _080835CE
_08083510:
	ldr r1, _08083538 @ =0x000001E3
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r0, _0808353C @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #9
	bls _080835CE
	adds r0, r4, #0
	movs r1, #3
	movs r2, #7
	bl FUN_08080e0c
	b _080835CE
	.align 2, 0
_08083538: .4byte 0x000001E3
_0808353C: .4byte 0x0000037E
_08083540:
	movs r1, #0xef
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r2, _080835B4 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _080835CE
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r4, r3
	adds r1, r4, #0
	adds r1, #0x2c
	ldr r2, _080835B8 @ =0x000004A6
	adds r5, r4, r2
	ldrb r2, [r5]
	lsls r2, r2, #3
	movs r3, #0x8f
	lsls r3, r3, #3
	adds r2, r2, r3
	adds r2, r4, r2
	bl FUN_08235f40
	cmp r0, #0
	beq _080835C4
	movs r0, #0x8e
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #8
	strb r0, [r1]
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r0, r4, r0
	ldr r1, _080835BC @ =0x0000047E
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r2, _080835C0 @ =0x00000471
	adds r0, r4, r2
	strb r1, [r0]
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	bl FUN_08080e0c
	ldrb r0, [r5]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r5]
	b _080835CE
	.align 2, 0
_080835B4: .4byte 0x0000037E
_080835B8: .4byte 0x000004A6
_080835BC: .4byte 0x0000047E
_080835C0: .4byte 0x00000471
_080835C4:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08080e0c
_080835CE:
	add sp, #0x18
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
