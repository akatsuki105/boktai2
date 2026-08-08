	push {lr}
	adds r3, r0, #0
	ldr r0, _08217464 @ =0x0000166C
	adds r2, r3, r0
	ldr r1, _08217468 @ =0x00001FE4
	adds r0, r3, r1
	ldrh r0, [r0]
	subs r0, #4
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3d
	bls _0821745A
	b _08217628
_0821745A:
	lsls r0, r0, #2
	ldr r1, _0821746C @ =_08217470
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08217464: .4byte 0x0000166C
_08217468: .4byte 0x00001FE4
_0821746C: .4byte _08217470
_08217470: @ jump table
	.4byte _08217568 @ case 0
	.4byte _08217628 @ case 1
	.4byte _08217628 @ case 2
	.4byte _08217628 @ case 3
	.4byte _08217628 @ case 4
	.4byte _08217574 @ case 5
	.4byte _08217628 @ case 6
	.4byte _08217628 @ case 7
	.4byte _08217628 @ case 8
	.4byte _08217628 @ case 9
	.4byte _08217580 @ case 10
	.4byte _08217628 @ case 11
	.4byte _08217628 @ case 12
	.4byte _08217628 @ case 13
	.4byte _08217628 @ case 14
	.4byte _0821758C @ case 15
	.4byte _08217628 @ case 16
	.4byte _08217628 @ case 17
	.4byte _08217628 @ case 18
	.4byte _08217628 @ case 19
	.4byte _08217598 @ case 20
	.4byte _08217628 @ case 21
	.4byte _08217628 @ case 22
	.4byte _08217628 @ case 23
	.4byte _08217628 @ case 24
	.4byte _082175A4 @ case 25
	.4byte _08217628 @ case 26
	.4byte _08217628 @ case 27
	.4byte _08217628 @ case 28
	.4byte _08217628 @ case 29
	.4byte _082175B0 @ case 30
	.4byte _08217628 @ case 31
	.4byte _08217628 @ case 32
	.4byte _08217628 @ case 33
	.4byte _08217628 @ case 34
	.4byte _082175BC @ case 35
	.4byte _08217628 @ case 36
	.4byte _08217628 @ case 37
	.4byte _08217628 @ case 38
	.4byte _08217628 @ case 39
	.4byte _082175C8 @ case 40
	.4byte _08217628 @ case 41
	.4byte _08217628 @ case 42
	.4byte _08217628 @ case 43
	.4byte _08217628 @ case 44
	.4byte _082175D4 @ case 45
	.4byte _08217628 @ case 46
	.4byte _08217628 @ case 47
	.4byte _08217628 @ case 48
	.4byte _08217628 @ case 49
	.4byte _082175E0 @ case 50
	.4byte _08217628 @ case 51
	.4byte _08217628 @ case 52
	.4byte _08217628 @ case 53
	.4byte _08217628 @ case 54
	.4byte _082175EC @ case 55
	.4byte _08217628 @ case 56
	.4byte _082175F8 @ case 57
	.4byte _08217628 @ case 58
	.4byte _08217604 @ case 59
	.4byte _08217610 @ case 60
	.4byte _0821761C @ case 61
_08217568:
	ldr r0, _08217570 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x1e
	b _08217630
	.align 2, 0
_08217570: .4byte 0x00000978
_08217574:
	ldr r0, _0821757C @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x23
	b _08217630
	.align 2, 0
_0821757C: .4byte 0x00000978
_08217580:
	ldr r0, _08217588 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x28
	b _08217630
	.align 2, 0
_08217588: .4byte 0x00000978
_0821758C:
	ldr r0, _08217594 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x2d
	b _08217630
	.align 2, 0
_08217594: .4byte 0x00000978
_08217598:
	ldr r0, _082175A0 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x32
	b _08217630
	.align 2, 0
_082175A0: .4byte 0x00000978
_082175A4:
	ldr r0, _082175AC @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x37
	b _08217630
	.align 2, 0
_082175AC: .4byte 0x00000978
_082175B0:
	ldr r0, _082175B8 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x3c
	b _08217630
	.align 2, 0
_082175B8: .4byte 0x00000978
_082175BC:
	ldr r0, _082175C4 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x3e
	b _08217630
	.align 2, 0
_082175C4: .4byte 0x00000978
_082175C8:
	ldr r0, _082175D0 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x40
	b _08217630
	.align 2, 0
_082175D0: .4byte 0x00000978
_082175D4:
	ldr r0, _082175DC @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x41
	b _08217630
	.align 2, 0
_082175DC: .4byte 0x00000978
_082175E0:
	ldr r0, _082175E8 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x41
	b _08217630
	.align 2, 0
_082175E8: .4byte 0x00000978
_082175EC:
	ldr r0, _082175F4 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x41
	b _08217630
	.align 2, 0
_082175F4: .4byte 0x00000978
_082175F8:
	ldr r0, _08217600 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0
	b _08217630
	.align 2, 0
_08217600: .4byte 0x00000978
_08217604:
	ldr r0, _0821760C @ =0x00000978
	adds r1, r2, r0
	movs r0, #5
	b _08217630
	.align 2, 0
_0821760C: .4byte 0x00000978
_08217610:
	ldr r0, _08217618 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x3f
	b _08217630
	.align 2, 0
_08217618: .4byte 0x00000978
_0821761C:
	ldr r0, _08217624 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0xf
	b _08217630
	.align 2, 0
_08217624: .4byte 0x00000978
_08217628:
	ldr r0, _08217644 @ =0x00000978
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
_08217630:
	strh r0, [r1]
	adds r0, r3, #0
	bl FUN_08216a90
	movs r0, #0xdc
	bl PlaySound_082406e0
	pop {r0}
	bx r0
	.align 2, 0
_08217644: .4byte 0x00000978
