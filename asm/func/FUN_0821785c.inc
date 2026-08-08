	push {lr}
	adds r3, r0, #0
	ldr r0, _08217880 @ =0x0000166C
	adds r2, r3, r0
	ldr r1, _08217884 @ =0x00001FE4
	adds r0, r3, r1
	ldrh r0, [r0]
	subs r0, #0x19
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x28
	bls _08217876
	b _082179F0
_08217876:
	lsls r0, r0, #2
	ldr r1, _08217888 @ =_0821788C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08217880: .4byte 0x0000166C
_08217884: .4byte 0x00001FE4
_08217888: .4byte _0821788C
_0821788C: @ jump table
	.4byte _08217930 @ case 0
	.4byte _0821793C @ case 1
	.4byte _08217948 @ case 2
	.4byte _08217954 @ case 3
	.4byte _08217960 @ case 4
	.4byte _082179F0 @ case 5
	.4byte _082179F0 @ case 6
	.4byte _082179F0 @ case 7
	.4byte _082179F0 @ case 8
	.4byte _082179F0 @ case 9
	.4byte _082179F0 @ case 10
	.4byte _082179F0 @ case 11
	.4byte _082179F0 @ case 12
	.4byte _082179F0 @ case 13
	.4byte _082179F0 @ case 14
	.4byte _082179F0 @ case 15
	.4byte _082179F0 @ case 16
	.4byte _082179F0 @ case 17
	.4byte _082179F0 @ case 18
	.4byte _082179F0 @ case 19
	.4byte _082179F0 @ case 20
	.4byte _082179F0 @ case 21
	.4byte _082179F0 @ case 22
	.4byte _082179F0 @ case 23
	.4byte _082179F0 @ case 24
	.4byte _082179F0 @ case 25
	.4byte _082179F0 @ case 26
	.4byte _082179F0 @ case 27
	.4byte _082179F0 @ case 28
	.4byte _082179F0 @ case 29
	.4byte _0821796C @ case 30
	.4byte _08217978 @ case 31
	.4byte _08217984 @ case 32
	.4byte _08217990 @ case 33
	.4byte _0821799C @ case 34
	.4byte _082179A8 @ case 35
	.4byte _082179B4 @ case 36
	.4byte _082179C0 @ case 37
	.4byte _082179CC @ case 38
	.4byte _082179D8 @ case 39
	.4byte _082179E4 @ case 40
_08217930:
	ldr r0, _08217938 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0
	b _082179F8
	.align 2, 0
_08217938: .4byte 0x00000978
_0821793C:
	ldr r0, _08217944 @ =0x00000978
	adds r1, r2, r0
	movs r0, #1
	b _082179F8
	.align 2, 0
_08217944: .4byte 0x00000978
_08217948:
	ldr r0, _08217950 @ =0x00000978
	adds r1, r2, r0
	movs r0, #2
	b _082179F8
	.align 2, 0
_08217950: .4byte 0x00000978
_08217954:
	ldr r0, _0821795C @ =0x00000978
	adds r1, r2, r0
	movs r0, #3
	b _082179F8
	.align 2, 0
_0821795C: .4byte 0x00000978
_08217960:
	ldr r0, _08217968 @ =0x00000978
	adds r1, r2, r0
	movs r0, #4
	b _082179F8
	.align 2, 0
_08217968: .4byte 0x00000978
_0821796C:
	ldr r0, _08217974 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x1e
	b _082179F8
	.align 2, 0
_08217974: .4byte 0x00000978
_08217978:
	ldr r0, _08217980 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x1f
	b _082179F8
	.align 2, 0
_08217980: .4byte 0x00000978
_08217984:
	ldr r0, _0821798C @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x20
	b _082179F8
	.align 2, 0
_0821798C: .4byte 0x00000978
_08217990:
	ldr r0, _08217998 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x21
	b _082179F8
	.align 2, 0
_08217998: .4byte 0x00000978
_0821799C:
	ldr r0, _082179A4 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x22
	b _082179F8
	.align 2, 0
_082179A4: .4byte 0x00000978
_082179A8:
	ldr r0, _082179B0 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x3e
	b _082179F8
	.align 2, 0
_082179B0: .4byte 0x00000978
_082179B4:
	ldr r0, _082179BC @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x3f
	b _082179F8
	.align 2, 0
_082179BC: .4byte 0x00000978
_082179C0:
	ldr r0, _082179C8 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x40
	b _082179F8
	.align 2, 0
_082179C8: .4byte 0x00000978
_082179CC:
	ldr r0, _082179D4 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x40
	b _082179F8
	.align 2, 0
_082179D4: .4byte 0x00000978
_082179D8:
	ldr r0, _082179E0 @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x41
	b _082179F8
	.align 2, 0
_082179E0: .4byte 0x00000978
_082179E4:
	ldr r0, _082179EC @ =0x00000978
	adds r1, r2, r0
	movs r0, #0x3c
	b _082179F8
	.align 2, 0
_082179EC: .4byte 0x00000978
_082179F0:
	ldr r0, _08217A0C @ =0x00000978
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #5
_082179F8:
	strh r0, [r1]
	adds r0, r3, #0
	bl FUN_08216a90
	movs r0, #0xdc
	bl PlaySound_082406e0
	pop {r0}
	bx r0
	.align 2, 0
_08217A0C: .4byte 0x00000978
