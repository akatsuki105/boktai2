	push {lr}
	adds r3, r0, #0
	ldr r0, _0821815C @ =0x0000166C
	adds r2, r3, r0
	ldr r1, _08218160 @ =0x00001FE6
	adds r0, r3, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x56
	bls _08218152
	b _082183C0
_08218152:
	lsls r0, r0, #2
	ldr r1, _08218164 @ =_08218168
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0821815C: .4byte 0x0000166C
_08218160: .4byte 0x00001FE6
_08218164: .4byte _08218168
_08218168: @ jump table
	.4byte _082182C4 @ case 0
	.4byte _082183C0 @ case 1
	.4byte _082183C0 @ case 2
	.4byte _082183C0 @ case 3
	.4byte _082183C0 @ case 4
	.4byte _082182D0 @ case 5
	.4byte _082183C0 @ case 6
	.4byte _082183C0 @ case 7
	.4byte _082183C0 @ case 8
	.4byte _082183C0 @ case 9
	.4byte _082182DC @ case 10
	.4byte _082183C0 @ case 11
	.4byte _082183C0 @ case 12
	.4byte _082183C0 @ case 13
	.4byte _082183C0 @ case 14
	.4byte _082182E8 @ case 15
	.4byte _082183C0 @ case 16
	.4byte _082183C0 @ case 17
	.4byte _082183C0 @ case 18
	.4byte _082183C0 @ case 19
	.4byte _082182F4 @ case 20
	.4byte _082183C0 @ case 21
	.4byte _082183C0 @ case 22
	.4byte _082183C0 @ case 23
	.4byte _082183C0 @ case 24
	.4byte _08218300 @ case 25
	.4byte _082183C0 @ case 26
	.4byte _082183C0 @ case 27
	.4byte _082183C0 @ case 28
	.4byte _082183C0 @ case 29
	.4byte _0821830C @ case 30
	.4byte _082183C0 @ case 31
	.4byte _082183C0 @ case 32
	.4byte _082183C0 @ case 33
	.4byte _082183C0 @ case 34
	.4byte _08218318 @ case 35
	.4byte _082183C0 @ case 36
	.4byte _082183C0 @ case 37
	.4byte _082183C0 @ case 38
	.4byte _082183C0 @ case 39
	.4byte _08218324 @ case 40
	.4byte _082183C0 @ case 41
	.4byte _082183C0 @ case 42
	.4byte _082183C0 @ case 43
	.4byte _082183C0 @ case 44
	.4byte _08218330 @ case 45
	.4byte _082183C0 @ case 46
	.4byte _082183C0 @ case 47
	.4byte _082183C0 @ case 48
	.4byte _082183C0 @ case 49
	.4byte _0821833C @ case 50
	.4byte _082183C0 @ case 51
	.4byte _082183C0 @ case 52
	.4byte _082183C0 @ case 53
	.4byte _082183C0 @ case 54
	.4byte _08218348 @ case 55
	.4byte _082183C0 @ case 56
	.4byte _082183C0 @ case 57
	.4byte _082183C0 @ case 58
	.4byte _082183C0 @ case 59
	.4byte _08218354 @ case 60
	.4byte _082183C0 @ case 61
	.4byte _082183C0 @ case 62
	.4byte _082183C0 @ case 63
	.4byte _082183C0 @ case 64
	.4byte _08218360 @ case 65
	.4byte _082183C0 @ case 66
	.4byte _082183C0 @ case 67
	.4byte _082183C0 @ case 68
	.4byte _082183C0 @ case 69
	.4byte _0821836C @ case 70
	.4byte _082183C0 @ case 71
	.4byte _082183C0 @ case 72
	.4byte _082183C0 @ case 73
	.4byte _082183C0 @ case 74
	.4byte _08218378 @ case 75
	.4byte _082183C0 @ case 76
	.4byte _082183C0 @ case 77
	.4byte _082183C0 @ case 78
	.4byte _082183C0 @ case 79
	.4byte _08218384 @ case 80
	.4byte _082183C0 @ case 81
	.4byte _08218390 @ case 82
	.4byte _082183C0 @ case 83
	.4byte _0821839C @ case 84
	.4byte _082183A8 @ case 85
	.4byte _082183B4 @ case 86
_082182C4:
	ldr r0, _082182CC @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x51
	b _082183C8
	.align 2, 0
_082182CC: .4byte 0x0000097A
_082182D0:
	ldr r0, _082182D8 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x53
	b _082183C8
	.align 2, 0
_082182D8: .4byte 0x0000097A
_082182DC:
	ldr r0, _082182E4 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x54
	b _082183C8
	.align 2, 0
_082182E4: .4byte 0x0000097A
_082182E8:
	ldr r0, _082182F0 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x55
	b _082183C8
	.align 2, 0
_082182F0: .4byte 0x0000097A
_082182F4:
	ldr r0, _082182FC @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x56
	b _082183C8
	.align 2, 0
_082182FC: .4byte 0x0000097A
_08218300:
	ldr r0, _08218308 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x56
	b _082183C8
	.align 2, 0
_08218308: .4byte 0x0000097A
_0821830C:
	ldr r0, _08218314 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x56
	b _082183C8
	.align 2, 0
_08218314: .4byte 0x0000097A
_08218318:
	ldr r0, _08218320 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x56
	b _082183C8
	.align 2, 0
_08218320: .4byte 0x0000097A
_08218324:
	ldr r0, _0821832C @ =0x0000097A
	adds r1, r2, r0
	movs r0, #4
	b _082183C8
	.align 2, 0
_0821832C: .4byte 0x0000097A
_08218330:
	ldr r0, _08218338 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #9
	b _082183C8
	.align 2, 0
_08218338: .4byte 0x0000097A
_0821833C:
	ldr r0, _08218344 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0xe
	b _082183C8
	.align 2, 0
_08218344: .4byte 0x0000097A
_08218348:
	ldr r0, _08218350 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x13
	b _082183C8
	.align 2, 0
_08218350: .4byte 0x0000097A
_08218354:
	ldr r0, _0821835C @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x18
	b _082183C8
	.align 2, 0
_0821835C: .4byte 0x0000097A
_08218360:
	ldr r0, _08218368 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x1d
	b _082183C8
	.align 2, 0
_08218368: .4byte 0x0000097A
_0821836C:
	ldr r0, _08218374 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x22
	b _082183C8
	.align 2, 0
_08218374: .4byte 0x0000097A
_08218378:
	ldr r0, _08218380 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x27
	b _082183C8
	.align 2, 0
_08218380: .4byte 0x0000097A
_08218384:
	ldr r0, _0821838C @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x2c
	b _082183C8
	.align 2, 0
_0821838C: .4byte 0x0000097A
_08218390:
	ldr r0, _08218398 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x31
	b _082183C8
	.align 2, 0
_08218398: .4byte 0x0000097A
_0821839C:
	ldr r0, _082183A4 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x36
	b _082183C8
	.align 2, 0
_082183A4: .4byte 0x0000097A
_082183A8:
	ldr r0, _082183B0 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x3b
	b _082183C8
	.align 2, 0
_082183B0: .4byte 0x0000097A
_082183B4:
	ldr r0, _082183BC @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x40
	b _082183C8
	.align 2, 0
_082183BC: .4byte 0x0000097A
_082183C0:
	ldr r0, _082183DC @ =0x0000097A
	adds r1, r2, r0
	ldrh r0, [r1]
	subs r0, #1
_082183C8:
	strh r0, [r1]
	adds r0, r3, #0
	bl FUN_08217a10
	movs r0, #0xdc
	bl PlaySound_082406e0
	pop {r0}
	bx r0
	.align 2, 0
_082183DC: .4byte 0x0000097A
