	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _08218404 @ =0x0000166C
	adds r2, r3, r0
	ldr r1, _08218408 @ =0x00001FE6
	adds r0, r3, r1
	ldrh r0, [r0]
	subs r0, #4
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x52
	bls _082183FA
	b _08218658
_082183FA:
	lsls r0, r0, #2
	ldr r1, _0821840C @ =_08218410
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08218404: .4byte 0x0000166C
_08218408: .4byte 0x00001FE6
_0821840C: .4byte _08218410
_08218410: @ jump table
	.4byte _0821855C @ case 0
	.4byte _08218658 @ case 1
	.4byte _08218658 @ case 2
	.4byte _08218658 @ case 3
	.4byte _08218658 @ case 4
	.4byte _08218568 @ case 5
	.4byte _08218658 @ case 6
	.4byte _08218658 @ case 7
	.4byte _08218658 @ case 8
	.4byte _08218658 @ case 9
	.4byte _08218574 @ case 10
	.4byte _08218658 @ case 11
	.4byte _08218658 @ case 12
	.4byte _08218658 @ case 13
	.4byte _08218658 @ case 14
	.4byte _08218580 @ case 15
	.4byte _08218658 @ case 16
	.4byte _08218658 @ case 17
	.4byte _08218658 @ case 18
	.4byte _08218658 @ case 19
	.4byte _0821858C @ case 20
	.4byte _08218658 @ case 21
	.4byte _08218658 @ case 22
	.4byte _08218658 @ case 23
	.4byte _08218658 @ case 24
	.4byte _08218598 @ case 25
	.4byte _08218658 @ case 26
	.4byte _08218658 @ case 27
	.4byte _08218658 @ case 28
	.4byte _08218658 @ case 29
	.4byte _082185A4 @ case 30
	.4byte _08218658 @ case 31
	.4byte _08218658 @ case 32
	.4byte _08218658 @ case 33
	.4byte _08218658 @ case 34
	.4byte _082185B0 @ case 35
	.4byte _08218658 @ case 36
	.4byte _08218658 @ case 37
	.4byte _08218658 @ case 38
	.4byte _08218658 @ case 39
	.4byte _082185BC @ case 40
	.4byte _08218658 @ case 41
	.4byte _08218658 @ case 42
	.4byte _08218658 @ case 43
	.4byte _08218658 @ case 44
	.4byte _082185C8 @ case 45
	.4byte _08218658 @ case 46
	.4byte _08218658 @ case 47
	.4byte _08218658 @ case 48
	.4byte _08218658 @ case 49
	.4byte _082185D4 @ case 50
	.4byte _08218658 @ case 51
	.4byte _08218658 @ case 52
	.4byte _08218658 @ case 53
	.4byte _08218658 @ case 54
	.4byte _082185E0 @ case 55
	.4byte _08218658 @ case 56
	.4byte _08218658 @ case 57
	.4byte _08218658 @ case 58
	.4byte _08218658 @ case 59
	.4byte _082185EC @ case 60
	.4byte _08218658 @ case 61
	.4byte _08218658 @ case 62
	.4byte _08218658 @ case 63
	.4byte _08218658 @ case 64
	.4byte _082185F8 @ case 65
	.4byte _08218658 @ case 66
	.4byte _08218658 @ case 67
	.4byte _08218658 @ case 68
	.4byte _08218658 @ case 69
	.4byte _08218604 @ case 70
	.4byte _08218658 @ case 71
	.4byte _08218658 @ case 72
	.4byte _08218658 @ case 73
	.4byte _08218658 @ case 74
	.4byte _08218610 @ case 75
	.4byte _08218658 @ case 76
	.4byte _0821861C @ case 77
	.4byte _08218658 @ case 78
	.4byte _08218628 @ case 79
	.4byte _08218634 @ case 80
	.4byte _08218640 @ case 81
	.4byte _0821864C @ case 82
_0821855C:
	ldr r4, _08218564 @ =0x0000097A
	adds r1, r2, r4
	movs r0, #0x28
	b _08218684
	.align 2, 0
_08218564: .4byte 0x0000097A
_08218568:
	ldr r0, _08218570 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x2d
	b _08218684
	.align 2, 0
_08218570: .4byte 0x0000097A
_08218574:
	ldr r4, _0821857C @ =0x0000097A
	adds r1, r2, r4
	movs r0, #0x32
	b _08218684
	.align 2, 0
_0821857C: .4byte 0x0000097A
_08218580:
	ldr r0, _08218588 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x37
	b _08218684
	.align 2, 0
_08218588: .4byte 0x0000097A
_0821858C:
	ldr r4, _08218594 @ =0x0000097A
	adds r1, r2, r4
	movs r0, #0x3c
	b _08218684
	.align 2, 0
_08218594: .4byte 0x0000097A
_08218598:
	ldr r0, _082185A0 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x41
	b _08218684
	.align 2, 0
_082185A0: .4byte 0x0000097A
_082185A4:
	ldr r4, _082185AC @ =0x0000097A
	adds r1, r2, r4
	movs r0, #0x46
	b _08218684
	.align 2, 0
_082185AC: .4byte 0x0000097A
_082185B0:
	ldr r0, _082185B8 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x4b
	b _08218684
	.align 2, 0
_082185B8: .4byte 0x0000097A
_082185BC:
	ldr r4, _082185C4 @ =0x0000097A
	adds r1, r2, r4
	movs r0, #0x50
	b _08218684
	.align 2, 0
_082185C4: .4byte 0x0000097A
_082185C8:
	ldr r0, _082185D0 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x52
	b _08218684
	.align 2, 0
_082185D0: .4byte 0x0000097A
_082185D4:
	ldr r4, _082185DC @ =0x0000097A
	adds r1, r2, r4
	movs r0, #0x54
	b _08218684
	.align 2, 0
_082185DC: .4byte 0x0000097A
_082185E0:
	ldr r0, _082185E8 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x55
	b _08218684
	.align 2, 0
_082185E8: .4byte 0x0000097A
_082185EC:
	ldr r4, _082185F4 @ =0x0000097A
	adds r1, r2, r4
	movs r0, #0x56
	b _08218684
	.align 2, 0
_082185F4: .4byte 0x0000097A
_082185F8:
	ldr r0, _08218600 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x56
	b _08218684
	.align 2, 0
_08218600: .4byte 0x0000097A
_08218604:
	ldr r4, _0821860C @ =0x0000097A
	adds r1, r2, r4
	movs r0, #0x56
	b _08218684
	.align 2, 0
_0821860C: .4byte 0x0000097A
_08218610:
	ldr r0, _08218618 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x56
	b _08218684
	.align 2, 0
_08218618: .4byte 0x0000097A
_0821861C:
	ldr r4, _08218624 @ =0x0000097A
	adds r1, r2, r4
	movs r0, #0
	b _08218684
	.align 2, 0
_08218624: .4byte 0x0000097A
_08218628:
	ldr r0, _08218630 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #5
	b _08218684
	.align 2, 0
_08218630: .4byte 0x0000097A
_08218634:
	ldr r4, _0821863C @ =0x0000097A
	adds r1, r2, r4
	movs r0, #0xa
	b _08218684
	.align 2, 0
_0821863C: .4byte 0x0000097A
_08218640:
	ldr r0, _08218648 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0xf
	b _08218684
	.align 2, 0
_08218648: .4byte 0x0000097A
_0821864C:
	ldr r4, _08218654 @ =0x0000097A
	adds r1, r2, r4
	movs r0, #0x14
	b _08218684
	.align 2, 0
_08218654: .4byte 0x0000097A
_08218658:
	ldr r1, _08218674 @ =0x00000974
	adds r0, r2, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #1
	bne _0821867C
	ldr r0, _08218678 @ =0x0000097A
	adds r1, r2, r0
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #0x4e
	bne _0821867C
	movs r0, #0x4a
	b _08218684
	.align 2, 0
_08218674: .4byte 0x00000974
_08218678: .4byte 0x0000097A
_0821867C:
	ldr r0, _08218698 @ =0x0000097A
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
_08218684:
	strh r0, [r1]
	adds r0, r3, #0
	bl FUN_08217a10
	movs r0, #0xdc
	bl PlaySound_082406e0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08218698: .4byte 0x0000097A
