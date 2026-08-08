	push {lr}
	adds r3, r0, #0
	ldr r0, _08217668 @ =0x0000166C
	adds r2, r3, r0
	ldr r1, _0821766C @ =0x00001FE4
	adds r0, r3, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x41
	bls _0821765E
	b _0821783C
_0821765E:
	lsls r0, r0, #2
	ldr r1, _08217670 @ =_08217674
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08217668: .4byte 0x0000166C
_0821766C: .4byte 0x00001FE4
_08217670: .4byte _08217674
_08217674: @ jump table
	.4byte _0821777C @ case 0
	.4byte _08217788 @ case 1
	.4byte _08217794 @ case 2
	.4byte _082177A0 @ case 3
	.4byte _082177AC @ case 4
	.4byte _0821783C @ case 5
	.4byte _0821783C @ case 6
	.4byte _0821783C @ case 7
	.4byte _0821783C @ case 8
	.4byte _0821783C @ case 9
	.4byte _0821783C @ case 10
	.4byte _0821783C @ case 11
	.4byte _0821783C @ case 12
	.4byte _0821783C @ case 13
	.4byte _0821783C @ case 14
	.4byte _0821783C @ case 15
	.4byte _0821783C @ case 16
	.4byte _0821783C @ case 17
	.4byte _0821783C @ case 18
	.4byte _0821783C @ case 19
	.4byte _0821783C @ case 20
	.4byte _0821783C @ case 21
	.4byte _0821783C @ case 22
	.4byte _0821783C @ case 23
	.4byte _0821783C @ case 24
	.4byte _0821783C @ case 25
	.4byte _0821783C @ case 26
	.4byte _0821783C @ case 27
	.4byte _0821783C @ case 28
	.4byte _0821783C @ case 29
	.4byte _082177B8 @ case 30
	.4byte _082177C4 @ case 31
	.4byte _082177D0 @ case 32
	.4byte _082177DC @ case 33
	.4byte _082177E8 @ case 34
	.4byte _0821783C @ case 35
	.4byte _0821783C @ case 36
	.4byte _0821783C @ case 37
	.4byte _0821783C @ case 38
	.4byte _0821783C @ case 39
	.4byte _0821783C @ case 40
	.4byte _0821783C @ case 41
	.4byte _0821783C @ case 42
	.4byte _0821783C @ case 43
	.4byte _0821783C @ case 44
	.4byte _0821783C @ case 45
	.4byte _0821783C @ case 46
	.4byte _0821783C @ case 47
	.4byte _0821783C @ case 48
	.4byte _0821783C @ case 49
	.4byte _0821783C @ case 50
	.4byte _0821783C @ case 51
	.4byte _0821783C @ case 52
	.4byte _0821783C @ case 53
	.4byte _0821783C @ case 54
	.4byte _0821783C @ case 55
	.4byte _0821783C @ case 56
	.4byte _0821783C @ case 57
	.4byte _0821783C @ case 58
	.4byte _0821783C @ case 59
	.4byte _082177F4 @ case 60
	.4byte _08217800 @ case 61
	.4byte _0821780C @ case 62
	.4byte _08217818 @ case 63
	.4byte _08217824 @ case 64
	.4byte _08217830 @ case 65
_0821777C:
	ldr r0, _08217784 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x19
	b _08217844
	.align 2, 0
_08217784: .4byte 0x00000978
_08217788:
	ldr r0, _08217790 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x1a
	b _08217844
	.align 2, 0
_08217790: .4byte 0x00000978
_08217794:
	ldr r0, _0821779C @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x1b
	b _08217844
	.align 2, 0
_0821779C: .4byte 0x00000978
_082177A0:
	ldr r0, _082177A8 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x1c
	b _08217844
	.align 2, 0
_082177A8: .4byte 0x00000978
_082177AC:
	ldr r0, _082177B4 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x1d
	b _08217844
	.align 2, 0
_082177B4: .4byte 0x00000978
_082177B8:
	ldr r0, _082177C0 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x37
	b _08217844
	.align 2, 0
_082177C0: .4byte 0x00000978
_082177C4:
	ldr r0, _082177CC @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x38
	b _08217844
	.align 2, 0
_082177CC: .4byte 0x00000978
_082177D0:
	ldr r0, _082177D8 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x39
	b _08217844
	.align 2, 0
_082177D8: .4byte 0x00000978
_082177DC:
	ldr r0, _082177E4 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x3a
	b _08217844
	.align 2, 0
_082177E4: .4byte 0x00000978
_082177E8:
	ldr r0, _082177F0 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x3b
	b _08217844
	.align 2, 0
_082177F0: .4byte 0x00000978
_082177F4:
	ldr r0, _082177FC @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x41
	b _08217844
	.align 2, 0
_082177FC: .4byte 0x00000978
_08217800:
	ldr r0, _08217808 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x41
	b _08217844
	.align 2, 0
_08217808: .4byte 0x00000978
_0821780C:
	ldr r0, _08217814 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x3c
	b _08217844
	.align 2, 0
_08217814: .4byte 0x00000978
_08217818:
	ldr r0, _08217820 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x3d
	b _08217844
	.align 2, 0
_08217820: .4byte 0x00000978
_08217824:
	ldr r0, _0821782C @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x3e
	b _08217844
	.align 2, 0
_0821782C: .4byte 0x00000978
_08217830:
	ldr r0, _08217838 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x40
	b _08217844
	.align 2, 0
_08217838: .4byte 0x00000978
_0821783C:
	ldr r0, _08217858 @ =0x00000978
	adds r1, r2, r0
	ldrh r0, [r1]
	subs r0, #5
_08217844:
	strh r0, [r1]
	adds r0, r3, #0
	bl FUN_08216a90
	movs r0, #0xdc
	bl PlaySound_082406e0
	pop {r0}
	bx r0
	.align 2, 0
_08217858: .4byte 0x00000978
