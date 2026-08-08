	push {lr}
	adds r3, r0, #0
	ldr r0, _082186BC @ =0x0000166C
	adds r2, r3, r0
	ldr r1, _082186C0 @ =0x00001FE6
	adds r0, r3, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x56
	bls _082186B2
	b _082188F0
_082186B2:
	lsls r0, r0, #2
	ldr r1, _082186C4 @ =_082186C8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_082186BC: .4byte 0x0000166C
_082186C0: .4byte 0x00001FE6
_082186C4: .4byte _082186C8
_082186C8: @ jump table
	.4byte _08218824 @ case 0
	.4byte _08218830 @ case 1
	.4byte _0821883C @ case 2
	.4byte _08218848 @ case 3
	.4byte _08218854 @ case 4
	.4byte _082188F0 @ case 5
	.4byte _082188F0 @ case 6
	.4byte _082188F0 @ case 7
	.4byte _082188F0 @ case 8
	.4byte _082188F0 @ case 9
	.4byte _082188F0 @ case 10
	.4byte _082188F0 @ case 11
	.4byte _082188F0 @ case 12
	.4byte _082188F0 @ case 13
	.4byte _082188F0 @ case 14
	.4byte _082188F0 @ case 15
	.4byte _082188F0 @ case 16
	.4byte _082188F0 @ case 17
	.4byte _082188F0 @ case 18
	.4byte _082188F0 @ case 19
	.4byte _082188F0 @ case 20
	.4byte _082188F0 @ case 21
	.4byte _082188F0 @ case 22
	.4byte _082188F0 @ case 23
	.4byte _082188F0 @ case 24
	.4byte _082188F0 @ case 25
	.4byte _082188F0 @ case 26
	.4byte _082188F0 @ case 27
	.4byte _082188F0 @ case 28
	.4byte _082188F0 @ case 29
	.4byte _082188F0 @ case 30
	.4byte _082188F0 @ case 31
	.4byte _082188F0 @ case 32
	.4byte _082188F0 @ case 33
	.4byte _082188F0 @ case 34
	.4byte _082188F0 @ case 35
	.4byte _082188F0 @ case 36
	.4byte _082188F0 @ case 37
	.4byte _082188F0 @ case 38
	.4byte _082188F0 @ case 39
	.4byte _08218860 @ case 40
	.4byte _0821886C @ case 41
	.4byte _08218878 @ case 42
	.4byte _08218884 @ case 43
	.4byte _08218890 @ case 44
	.4byte _082188F0 @ case 45
	.4byte _082188F0 @ case 46
	.4byte _082188F0 @ case 47
	.4byte _082188F0 @ case 48
	.4byte _082188F0 @ case 49
	.4byte _082188F0 @ case 50
	.4byte _082188F0 @ case 51
	.4byte _082188F0 @ case 52
	.4byte _082188F0 @ case 53
	.4byte _082188F0 @ case 54
	.4byte _082188F0 @ case 55
	.4byte _082188F0 @ case 56
	.4byte _082188F0 @ case 57
	.4byte _082188F0 @ case 58
	.4byte _082188F0 @ case 59
	.4byte _082188F0 @ case 60
	.4byte _082188F0 @ case 61
	.4byte _082188F0 @ case 62
	.4byte _082188F0 @ case 63
	.4byte _082188F0 @ case 64
	.4byte _082188F0 @ case 65
	.4byte _082188F0 @ case 66
	.4byte _082188F0 @ case 67
	.4byte _082188F0 @ case 68
	.4byte _082188F0 @ case 69
	.4byte _082188F0 @ case 70
	.4byte _082188F0 @ case 71
	.4byte _082188F0 @ case 72
	.4byte _082188F0 @ case 73
	.4byte _082188F0 @ case 74
	.4byte _082188F0 @ case 75
	.4byte _082188F0 @ case 76
	.4byte _082188F0 @ case 77
	.4byte _082188F0 @ case 78
	.4byte _082188F0 @ case 79
	.4byte _0821889C @ case 80
	.4byte _082188A8 @ case 81
	.4byte _082188B4 @ case 82
	.4byte _082188C0 @ case 83
	.4byte _082188CC @ case 84
	.4byte _082188D8 @ case 85
	.4byte _082188E4 @ case 86
_08218824:
	ldr r0, _0821882C @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x23
	b _082188F8
	.align 2, 0
_0821882C: .4byte 0x0000097A
_08218830:
	ldr r0, _08218838 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x24
	b _082188F8
	.align 2, 0
_08218838: .4byte 0x0000097A
_0821883C:
	ldr r0, _08218844 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x25
	b _082188F8
	.align 2, 0
_08218844: .4byte 0x0000097A
_08218848:
	ldr r0, _08218850 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x26
	b _082188F8
	.align 2, 0
_08218850: .4byte 0x0000097A
_08218854:
	ldr r0, _0821885C @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x27
	b _082188F8
	.align 2, 0
_0821885C: .4byte 0x0000097A
_08218860:
	ldr r0, _08218868 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x4b
	b _082188F8
	.align 2, 0
_08218868: .4byte 0x0000097A
_0821886C:
	ldr r0, _08218874 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x4c
	b _082188F8
	.align 2, 0
_08218874: .4byte 0x0000097A
_08218878:
	ldr r0, _08218880 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x4d
	b _082188F8
	.align 2, 0
_08218880: .4byte 0x0000097A
_08218884:
	ldr r0, _0821888C @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x4e
	b _082188F8
	.align 2, 0
_0821888C: .4byte 0x0000097A
_08218890:
	ldr r0, _08218898 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x4f
	b _082188F8
	.align 2, 0
_08218898: .4byte 0x0000097A
_0821889C:
	ldr r0, _082188A4 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x56
	b _082188F8
	.align 2, 0
_082188A4: .4byte 0x0000097A
_082188A8:
	ldr r0, _082188B0 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x56
	b _082188F8
	.align 2, 0
_082188B0: .4byte 0x0000097A
_082188B4:
	ldr r0, _082188BC @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x50
	b _082188F8
	.align 2, 0
_082188BC: .4byte 0x0000097A
_082188C0:
	ldr r0, _082188C8 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x51
	b _082188F8
	.align 2, 0
_082188C8: .4byte 0x0000097A
_082188CC:
	ldr r0, _082188D4 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x52
	b _082188F8
	.align 2, 0
_082188D4: .4byte 0x0000097A
_082188D8:
	ldr r0, _082188E0 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x54
	b _082188F8
	.align 2, 0
_082188E0: .4byte 0x0000097A
_082188E4:
	ldr r0, _082188EC @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x55
	b _082188F8
	.align 2, 0
_082188EC: .4byte 0x0000097A
_082188F0:
	ldr r0, _0821890C @ =0x0000097A
	adds r1, r2, r0
	ldrh r0, [r1]
	subs r0, #5
_082188F8:
	strh r0, [r1]
	adds r0, r3, #0
	bl FUN_08217a10
	movs r0, #0xdc
	bl PlaySound_082406e0
	pop {r0}
	bx r0
	.align 2, 0
_0821890C: .4byte 0x0000097A
