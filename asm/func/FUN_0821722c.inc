	push {lr}
	adds r3, r0, #0
	ldr r0, _0821724C @ =0x0000166C
	adds r2, r3, r0
	ldr r1, _08217250 @ =0x00001FE4
	adds r0, r3, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x41
	bls _08217242
	b _08217420
_08217242:
	lsls r0, r0, #2
	ldr r1, _08217254 @ =_08217258
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0821724C: .4byte 0x0000166C
_08217250: .4byte 0x00001FE4
_08217254: .4byte _08217258
_08217258: @ jump table
	.4byte _08217360 @ case 0
	.4byte _08217420 @ case 1
	.4byte _08217420 @ case 2
	.4byte _08217420 @ case 3
	.4byte _08217420 @ case 4
	.4byte _0821736C @ case 5
	.4byte _08217420 @ case 6
	.4byte _08217420 @ case 7
	.4byte _08217420 @ case 8
	.4byte _08217420 @ case 9
	.4byte _08217378 @ case 10
	.4byte _08217420 @ case 11
	.4byte _08217420 @ case 12
	.4byte _08217420 @ case 13
	.4byte _08217420 @ case 14
	.4byte _08217384 @ case 15
	.4byte _08217420 @ case 16
	.4byte _08217420 @ case 17
	.4byte _08217420 @ case 18
	.4byte _08217420 @ case 19
	.4byte _08217390 @ case 20
	.4byte _08217420 @ case 21
	.4byte _08217420 @ case 22
	.4byte _08217420 @ case 23
	.4byte _08217420 @ case 24
	.4byte _0821739C @ case 25
	.4byte _08217420 @ case 26
	.4byte _08217420 @ case 27
	.4byte _08217420 @ case 28
	.4byte _08217420 @ case 29
	.4byte _082173A8 @ case 30
	.4byte _08217420 @ case 31
	.4byte _08217420 @ case 32
	.4byte _08217420 @ case 33
	.4byte _08217420 @ case 34
	.4byte _082173B4 @ case 35
	.4byte _08217420 @ case 36
	.4byte _08217420 @ case 37
	.4byte _08217420 @ case 38
	.4byte _08217420 @ case 39
	.4byte _082173C0 @ case 40
	.4byte _08217420 @ case 41
	.4byte _08217420 @ case 42
	.4byte _08217420 @ case 43
	.4byte _08217420 @ case 44
	.4byte _082173CC @ case 45
	.4byte _08217420 @ case 46
	.4byte _08217420 @ case 47
	.4byte _08217420 @ case 48
	.4byte _08217420 @ case 49
	.4byte _082173D8 @ case 50
	.4byte _08217420 @ case 51
	.4byte _08217420 @ case 52
	.4byte _08217420 @ case 53
	.4byte _08217420 @ case 54
	.4byte _082173E4 @ case 55
	.4byte _08217420 @ case 56
	.4byte _08217420 @ case 57
	.4byte _08217420 @ case 58
	.4byte _08217420 @ case 59
	.4byte _082173F0 @ case 60
	.4byte _08217420 @ case 61
	.4byte _082173FC @ case 62
	.4byte _08217420 @ case 63
	.4byte _08217408 @ case 64
	.4byte _08217414 @ case 65
_08217360:
	ldr r0, _08217368 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x3d
	b _08217428
	.align 2, 0
_08217368: .4byte 0x00000978
_0821736C:
	ldr r0, _08217374 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x3f
	b _08217428
	.align 2, 0
_08217374: .4byte 0x00000978
_08217378:
	ldr r0, _08217380 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x40
	b _08217428
	.align 2, 0
_08217380: .4byte 0x00000978
_08217384:
	ldr r0, _0821738C @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x41
	b _08217428
	.align 2, 0
_0821738C: .4byte 0x00000978
_08217390:
	ldr r0, _08217398 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x41
	b _08217428
	.align 2, 0
_08217398: .4byte 0x00000978
_0821739C:
	ldr r0, _082173A4 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x41
	b _08217428
	.align 2, 0
_082173A4: .4byte 0x00000978
_082173A8:
	ldr r0, _082173B0 @ =0x00000978
	adds r1, r2, r0
	movs r0, #4
	b _08217428
	.align 2, 0
_082173B0: .4byte 0x00000978
_082173B4:
	ldr r0, _082173BC @ =0x00000978
	adds r1, r2, r0
	movs r0, #9
	b _08217428
	.align 2, 0
_082173BC: .4byte 0x00000978
_082173C0:
	ldr r0, _082173C8 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0xe
	b _08217428
	.align 2, 0
_082173C8: .4byte 0x00000978
_082173CC:
	ldr r0, _082173D4 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x13
	b _08217428
	.align 2, 0
_082173D4: .4byte 0x00000978
_082173D8:
	ldr r0, _082173E0 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x18
	b _08217428
	.align 2, 0
_082173E0: .4byte 0x00000978
_082173E4:
	ldr r0, _082173EC @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x1d
	b _08217428
	.align 2, 0
_082173EC: .4byte 0x00000978
_082173F0:
	ldr r0, _082173F8 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x22
	b _08217428
	.align 2, 0
_082173F8: .4byte 0x00000978
_082173FC:
	ldr r0, _08217404 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x27
	b _08217428
	.align 2, 0
_08217404: .4byte 0x00000978
_08217408:
	ldr r0, _08217410 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x2c
	b _08217428
	.align 2, 0
_08217410: .4byte 0x00000978
_08217414:
	ldr r0, _0821741C @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x31
	b _08217428
	.align 2, 0
_0821741C: .4byte 0x00000978
_08217420:
	ldr r0, _0821743C @ =0x00000978
	adds r1, r2, r0
	ldrh r0, [r1]
	subs r0, #1
_08217428:
	strh r0, [r1]
	adds r0, r3, #0
	bl FUN_08216a90
	movs r0, #0xdc
	bl PlaySound_082406e0
	pop {r0}
	bx r0
	.align 2, 0
_0821743C: .4byte 0x00000978
