	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080740D2
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080740D6
_080740D2:
	movs r6, #0x30
	b _080740D8
_080740D6:
	movs r6, #0x40
_080740D8:
	ldr r1, _080740F0 @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #4
	bls _080740E4
	b _0807423C
_080740E4:
	lsls r0, r0, #2
	ldr r1, _080740F4 @ =_080740F8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080740F0: .4byte 0x0000037D
_080740F4: .4byte _080740F8
_080740F8: @ jump table
	.4byte _0807410C @ case 0
	.4byte _0807413C @ case 1
	.4byte _08074156 @ case 2
	.4byte _080741EC @ case 3
	.4byte _08074214 @ case 4
_0807410C:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x18
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_08060a24
	cmp r0, #0
	bne _0807412A
	b _0807423C
_0807412A:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	bl FUN_08060b84
	adds r0, r5, #0
	bl FUN_080726b4
	b _0807423C
_0807413C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x19
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	b _0807423C
_08074156:
	ldr r2, _08074174 @ =0x0000037E
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _0807418C
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0807417C
	ldr r0, _08074178 @ =0x0000038F
	bl PlaySound_082406e0
	b _08074182
	.align 2, 0
_08074174: .4byte 0x0000037E
_08074178: .4byte 0x0000038F
_0807417C:
	ldr r0, _080741E4 @ =0x0000038D
	bl PlaySound_082406e0
_08074182:
	ldr r2, _080741E8 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0807418C:
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r4, r5, r0
	ldrb r0, [r4]
	movs r1, #0x1c
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_08060a24
	adds r6, r0, #0
	ldrb r0, [r4]
	cmp r0, #1
	bne _080741D4
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #1
	bne _080741D4
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _080741D4
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x2c
	adds r0, r5, #0
	movs r3, #0
	bl FUN_08061970
_080741D4:
	cmp r6, #0
	beq _0807423C
	adds r0, r5, #0
	movs r1, #3
	movs r2, #3
	bl FUN_08060b84
	b _0807423C
	.align 2, 0
_080741E4: .4byte 0x0000038D
_080741E8: .4byte 0x0000037E
_080741EC:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x18
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_08060a24
	cmp r0, #0
	beq _0807423C
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl FUN_08060b84
	b _0807423C
_08074214:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x19
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_08060a24
	cmp r0, #0
	beq _0807423C
	adds r0, r5, #0
	bl FUN_08072620
	adds r0, r5, #0
	bl FUN_080726b4
_0807423C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
